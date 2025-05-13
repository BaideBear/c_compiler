#include "intercode.h"

//#define DEBUG

//#define bug printf("> %s (%d) <%s, %d>\n", now->name, now->pos, __FUNCTION__, __LINE__);

#ifdef DEBUG
    #define DEBUG_PRINT(str) fprintf(stderr, "%s\n", str)
#else
    #define DEBUG_PRINT(str) // 无操作
#endif

extern HashTable_Type* table_syn;
extern HashTable_Func* table_func;

int label_count = 0;
int temp_count = 0;
static bool Paramtable[16384];

int mylog10_int(int x) {
    int result = 0;
    while (x >= 10) {
        x /= 10;
        result++;
    }
    return result;
}

void writeonParam(char *name){
    int num = hash_pjw(name);
    Paramtable[num] = true;
}

bool isonParam(char *name){
    int num = hash_pjw(name);
    return Paramtable[num];
}

InterCodeList* translateExtDefList(Node* now){
    DEBUG_PRINT("translateExtDefList");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "ExtDefList"));
    
    Node *ExtDef_ = get_target_down(now, "ExtDef");
    Node *ExtDefList_ = get_target_down(now, "ExtDefList");
    InterCodeList* code1 = translateExtDef(ExtDef_);
    InterCodeList* code2 = translateExtDefList(ExtDefList_);
    appendInterCodeList(code1, code2);
    return code1;
}

InterCodeList* translateExtDef(Node* now){
    DEBUG_PRINT("translateExtDef");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "ExtDef"));
    
    Node *FunDec_ = get_target_down(now, "FunDec");
    
    if(FunDec_ != NULL){ //ExtDef -> Specifier FunDec CompSt
        InterCode* code1 = newintercode(FUNCTION, FunDec_->down->text);
        InterCodeList* label_codes = getInterCodewrapped(code1);
        InterCodeList* fun_codes = translateFunDec(FunDec_);
        InterCodeList* compst_codes = translateCompSt(get_target_down(now, "CompSt"));
        appendInterCodeList(fun_codes, compst_codes);
        appendInterCodeList(label_codes, fun_codes);
        return label_codes;
    }
    else{ //ExtDef -> Specifier SEMI
        return empty_InterCodeList();
    }
}

InterCodeList* translateFunDec(Node* now){
    DEBUG_PRINT("translateFunDec");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "FunDec"));
    
    Node *VarList_ = get_target_down(now, "VarList");
    InterCodeList* varlist_codes = translateVarList(VarList_);
    return varlist_codes;
}

InterCodeList* translateVarList(Node* now){
    DEBUG_PRINT("translateVarList");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "VarList"));
    
    Node *ParamDec_ = get_target_down(now, "ParamDec");
    Node *VarList_ = get_target_down(now, "VarList");
    InterCodeList* param_codes = translateParamDec(ParamDec_);
    InterCodeList* varlist_codes = translateVarList(VarList_);
    appendInterCodeList(param_codes, varlist_codes);
    return param_codes;
}

InterCodeList* translateParamDec(Node* now){
    DEBUG_PRINT("translateParamDec");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "ParamDec"));
    
    Node *VarDec_ = get_target_down(now, "VarDec");
    InterCodeList* vardec_codes = translateVarDecfunction(VarDec_);
    return vardec_codes;
}

InterCodeList* translateCompSt(Node* now){
    DEBUG_PRINT("translateCompSt");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "CompSt"));
    
    Node *DefList_ = get_target_down(now, "DefList");
    Node *StmtList_ = get_target_down(now, "StmtList");
    InterCodeList* deflist_codes = translateDefList(DefList_);
    InterCodeList* stmtlist_codes = translateStmtList(StmtList_);
    appendInterCodeList(deflist_codes, stmtlist_codes);
    return deflist_codes;
}

InterCodeList* translateVarDecfunction(Node* now){
    DEBUG_PRINT("translateVarDecfunction");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "VarDec"));
    
    if(!strcmp(now->down->name, "ID")){
        char* name = now->down->text;
        writeonParam(name);
        InterCode* code = newintercode(PARAM, name);
        InterCodeList* codes = getInterCodewrapped(code);
        return codes;
    }
    else{
        InterCodeList* codes = translateVarDecfunction(get_target_down(now, "VarDec"));
        return codes;
    }
}

InterCodeList* translateDef(Node* now){
    DEBUG_PRINT("translateDef");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "Def"));
    
    Node *DecList_ = get_target_down(now, "DecList");
    InterCodeList* declist_codes = translateDecList(DecList_);
    return declist_codes;
}

InterCodeList* translateDefList(Node* now){
    DEBUG_PRINT("translateDefList");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "DefList"));
    
    Node *Def_ = get_target_down(now, "Def");
    Node *DefList_ = get_target_down(now, "DefList");
    InterCodeList* def_codes = translateDef(Def_);
    InterCodeList* deflist_codes = translateDefList(DefList_);
    appendInterCodeList(def_codes, deflist_codes);
    return def_codes;
}

InterCodeList* translateDec(Node* now){
    DEBUG_PRINT("translateDec");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "Dec"));
    
    char* nowid;
    Node *findid = now;
    while(strcmp(findid->name, "ID")){
        findid = findid->down;
    }
    nowid = findid->text;

    Type* ty = search_type(table_syn, nowid);
    InterCodeList* codes = empty_InterCodeList();
    if(ty->kind == STRUCTURE){
        InterCode* code = newintercode(DEC, nowid, ty->structure_size);
        appendInterCode(codes, code);
    }
    else if (ty->kind == ARRAY){
        InterCode* code = newintercode(DEC, nowid, ty->size * ty->element_size);
        appendInterCode(codes, code);
    }

    if(get_target_down(now, "ASSIGNOP") != NULL){
        if(ty->kind == BASIC){
            char *newt1 = new_temp();
            InterCode* code = newintercode(ASSIGN, nowid, newt1);
            InterCodeList* exp_codes = translateExp(get_target_down(now, "Exp"), newt1);
            appendInterCode(exp_codes, code);
            return exp_codes;
        }
        else{
            char *newt1 = new_temp();
            InterCodeList* exp_codes = translateExp(get_target_down(now, "Exp"), newt1);
            appendInterCodeList(codes, exp_codes);
            int tysize = getTypeSize(ty) >> 2;
            char * tempt = new_temp();
            char* lefaddr = new_temp();
            char* rightaddr = newt1;
            InterCode* code2 = newintercode(GET_ADDR, lefaddr, nowid);
            appendInterCode(codes, code2);
            for(int i = 0; i < tysize; i++){
                InterCode* code3 = newintercode(READ_ADDR, tempt, rightaddr);
                InterCode* code4 = newintercode(WRITE_ADDR, lefaddr, tempt);
                appendInterCode(codes, code3);
                appendInterCode(codes, code4);
                if(i != tysize - 1){
                    InterCode* code5 = newintercode(PLUS, lefaddr, lefaddr, "#4");
                    InterCode* code6 = newintercode(PLUS, rightaddr, rightaddr, "#4");
                    appendInterCode(codes, code5);
                    appendInterCode(codes, code6);
                }
            }
            return codes;
        }
    }
    return codes;
}

InterCodeList* translateDecList(Node* now){
    DEBUG_PRINT("translateDecList");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "DecList"));
    
    Node *Dec_ = get_target_down(now, "Dec");
    Node *DecList_ = get_target_down(now, "DecList");
    InterCodeList* dec_codes = translateDec(Dec_);
    InterCodeList* declist_codes = translateDecList(DecList_);
    appendInterCodeList(dec_codes, declist_codes);
    return dec_codes;
}

InterCodeList* translateStmtList(Node* now){
    DEBUG_PRINT("translateStmtList");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "StmtList"));
    
    Node *Stmt_ = get_target_down(now, "Stmt");
    Node *StmtList_ = get_target_down(now, "StmtList");
    InterCodeList* stmt_codes = translateStmt(Stmt_);
    InterCodeList* stmtlist_codes = translateStmtList(StmtList_);
    appendInterCodeList(stmt_codes, stmtlist_codes);
    return stmt_codes;
}

InterCodeList* translateStmt(Node* now){
    DEBUG_PRINT("translateStmt");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "Stmt"));

    Node *Exp_ = get_target_down(now, "Exp");
    Node *CompSt_ = get_target_down(now, "CompSt");
    Node *IF_ = get_target_down(now, "IF");
    Node *ELSE_ = get_target_down(now, "ELSE");
    Node *WHILE_ = get_target_down(now, "WHILE");
    Node *RETURN_ = get_target_down(now, "RETURN");
    Node *Stmt_ = get_target_down(now, "Stmt");

    if(!strcmp(now->down->name, "Exp")){ //Exp SEMI
        InterCodeList* exp_codes = translateExp(Exp_, "tNULL");
        return exp_codes;
    }
    else if(CompSt_ != NULL){ //CompSt
        InterCodeList* compst_codes = translateCompSt(now->down);
        return compst_codes;
    }
    else if(IF_ != NULL && ELSE_ == NULL){ // IF LP Exp RP Stmt
        char* label1 = new_label();
        char* label2 = new_label();
        InterCodeList* exp_codes = translateCond(Exp_, label1, label2);
        InterCodeList* stmt_codes = translateStmt(Stmt_);
        InterCode* code1 = newintercode(LABEL, label1);
        InterCode* code2 = newintercode(LABEL, label2);
        appendInterCode(exp_codes, code1);
        appendInterCodeList(exp_codes, stmt_codes);
        appendInterCode(exp_codes, code2);
        return exp_codes;
    }
    else if(ELSE_ != NULL){ // IF LP Exp RP Stmt ELSE Stmt
        char* label1 = new_label();
        char* label2 = new_label();
        char* label3 = new_label();
        InterCodeList* exp_codes = translateCond(Exp_, label1, label2);
        InterCodeList* stmt_codes1 = translateStmt(now->down->next->next->next->next);
        InterCodeList* stmt_codes2 = translateStmt(now->down->next->next->next->next->next->next);
        InterCode* code1 = newintercode(LABEL, label1);
        InterCode* code2 = newintercode(GOTO, label3);
        InterCode* code3 = newintercode(LABEL, label2);
        InterCode* code4 = newintercode(LABEL, label3);
        appendInterCode(exp_codes, code1);
        appendInterCodeList(exp_codes, stmt_codes1);
        appendInterCode(exp_codes, code2);
        appendInterCode(exp_codes, code3);
        appendInterCodeList(exp_codes, stmt_codes2);
        appendInterCode(exp_codes, code4);
        return exp_codes;
    }
    else if(WHILE_ != NULL){ // WHILE LP Exp RP Stmt
        char* label1 = new_label();
        char* label2 = new_label();
        char* label3 = new_label();
        InterCodeList* exp_codes = translateCond(Exp_, label2, label3);
        InterCodeList* stmt_codes = translateStmt(Stmt_);
        InterCodeList* label_codes = getInterCodewrapped(newintercode(LABEL, label1));
        InterCode* code1 = newintercode(LABEL, label2);
        InterCode* code2 = newintercode(GOTO, label1);
        InterCode* code3 = newintercode(LABEL, label3);
        appendInterCodeList(label_codes, exp_codes);
        appendInterCode(label_codes, code1);
        appendInterCodeList(label_codes, stmt_codes);
        appendInterCode(label_codes, code2);
        appendInterCode(label_codes, code3);
        return label_codes;
    }
    else if(RETURN_ != NULL){
        char *newt1 = new_temp();
        InterCodeList* exp_codes = translateExp(Exp_, newt1);
        InterCode* code1 = newintercode(RETURN, newt1);
        appendInterCode(exp_codes, code1);
        return exp_codes;
    }
    return empty_InterCodeList();
}

InterCodeList* translateCond(Node* now, char* label_true, char* label_false){
    DEBUG_PRINT("translateCond");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "Exp"));
    
    Node *Exp_ = get_target_down(now, "Exp");
    Node *RELOP_ = get_target_down(now, "RELOP");
    Node *AND_ = get_target_down(now, "AND");
    Node *OR_ = get_target_down(now, "OR");
    Node *NOT_ = get_target_down(now, "NOT");
    
    if(RELOP_ != NULL){ //RELOP
        char* relopstr = now->down->next->text;
        assert(!strcmp(now->down->next->name, "RELOP"));
        char* newt1 = new_temp();
        char* newt2 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down, newt1);
        InterCodeList* exp_codes2 = translateExp(now->down->next->next, newt2);
        InterRelop* relopnow = malloc(sizeof(InterRelop));
        if(!strcmp(relopstr, "<")) relopnow->kind = LT;
        else if(!strcmp(relopstr, ">")) relopnow->kind = GT;
        else if(!strcmp(relopstr, "<=")) relopnow->kind = LEQ;
        else if(!strcmp(relopstr, ">=")) relopnow->kind = GEQ;
        else if(!strcmp(relopstr, "==")) relopnow->kind = EQ;
        else if(!strcmp(relopstr, "!=")) relopnow->kind = NEQ;
        InterCode* code1 = newintercode(IF_GOTO, newt1, relopnow, newt2, label_true);
        InterCode* code2 = newintercode(GOTO, label_false);
        appendInterCodeList(exp_codes1, exp_codes2);
        appendInterCode(exp_codes1, code1);
        appendInterCode(exp_codes1, code2);
        return exp_codes1;
    }
    else if(AND_ != NULL){ //AND
        char* label1 = new_label();
        InterCodeList* cond1_codes = translateCond(now->down, label1, label_false);
        InterCodeList* cond2_codes = translateCond(now->down->next->next, label_true, label_false);
        InterCode* code1 = newintercode(LABEL, label1);
        appendInterCode(cond1_codes, code1);
        appendInterCodeList(cond1_codes, cond2_codes);
        return cond1_codes;
    }
    else if(OR_ != NULL){ //OR
        char* label1 = new_label();
        InterCodeList* cond1_codes = translateCond(now->down, label_true, label1);
        InterCodeList* cond2_codes = translateCond(now->down->next->next, label_true, label_false);
        InterCode* code1 = newintercode(LABEL, label1);
        appendInterCode(cond1_codes, code1);
        appendInterCodeList(cond1_codes, cond2_codes);
        return cond1_codes;
    }
    else if(NOT_ != NULL){ //NOT
        InterCodeList* cond_codes = translateCond(now->down->next, label_false, label_true);
        return cond_codes;
    }
    else{
        char* newt1 = new_temp();
        InterCodeList* exp_codes = translateExp(now, newt1);
        InterRelop* relopnow = malloc(sizeof(InterRelop));
        relopnow->kind = NEQ;
        InterCode* code1 = newintercode(IF_GOTO, newt1, relopnow, "#0", label_true);
        InterCode* code2 = newintercode(GOTO, label_false);
        appendInterCode(exp_codes, code1);
        appendInterCode(exp_codes, code2);
        return exp_codes;
    }
}

InterCodeList* translateArgs(Node* now, ArgList* arglist){
    DEBUG_PRINT("translateArgs");
    if(now == NULL) return empty_InterCodeList();
    char * newt1 = new_temp();
    InterCodeList* exp_codes = translateExp(now->down, newt1);
    ArgID* nowid = malloc(sizeof(ArgID));
    nowid->next = NULL;
    nowid->name = newt1;
    if(arglist->head){
        nowid->next = arglist->head;
        arglist->head = nowid;
    }
    else{
        arglist->head = nowid;
    }
    if(!get_target_down(now, "COMMA"))
        return exp_codes;
    InterCodeList* args_codes = translateArgs(get_target_down(now, "Args"), arglist);
    appendInterCodeList(exp_codes, args_codes);
    return exp_codes;
}

InterCodeList* translateExp(Node* now, char* place){
    DEBUG_PRINT("translateExp");
    if(now == NULL) return empty_InterCodeList();
    assert(!strcmp(now->name, "Exp"));
    Node *ASSIGNOP_ = get_target_down(now, "ASSIGNOP");
    Node *AND_ = get_target_down(now, "AND");
    Node *OR_ = get_target_down(now, "OR");
    Node *RELOP_ = get_target_down(now, "RELOP");
    Node *PLUS_ = get_target_down(now, "PLUS");
    Node *MINUS_ = get_target_down(now, "MINUS");
    Node *STAR_ = get_target_down(now, "STAR");
    Node *DIV_ = get_target_down(now, "DIV");
    Node *NOT_ = get_target_down(now, "NOT");
    Node *LB_ = get_target_down(now, "LB");
    Node *LP_ = get_target_down(now, "LP");
    Node *DOT_ = get_target_down(now, "DOT");
    Node *ID_ = get_target_down(now, "ID");
    Node *FLOAT_ = get_target_down(now, "FLOAT");
    Node *Args_ = get_target_down(now, "Args");
    
    if(!strcmp(now->down->name, "ID") && now->down->next == NULL){ //ID
        DEBUG_PRINT("ID");
        char* id = now->down->text;
        Type* ty = search_type(table_syn, id);
        if(ty->kind == BASIC){
            InterCode* code1 = newintercode(ASSIGN, place, id);
            InterCodeList* codes = getInterCodewrapped(code1);
            return codes;
        }
        else{
            if(isonParam(id)){
                InterCode* code1 = newintercode(ASSIGN, place, id);
                InterCodeList* codes = getInterCodewrapped(code1);
                return codes;
            }
            else{
                InterCode* code1 = newintercode(GET_ADDR, place, id);
                InterCodeList* codes = getInterCodewrapped(code1);
                return codes;
            }
        }
    }
    else if(ASSIGNOP_ != NULL){ // ASSIGNOP
        DEBUG_PRINT("ASSIGNOP");
        char* newt1 = new_temp();
        InterCodeList* Exp_codes = translateExp(now->down->next->next, newt1);
        if(!strcmp(now->down->down->name,"ID")){
            char *id = now->down->down->text;
            Type* ty = search_type(table_syn, id);
            if(ty->kind == BASIC){
                InterCode* code1 = newintercode(ASSIGN, now->down->down->text, newt1);
                appendInterCode(Exp_codes, code1);
                InterCode* code2 = newintercode(ASSIGN, place, newt1);
                appendInterCode(Exp_codes, code2);//new fixed
                return Exp_codes;
            }
            else{
                char *lefaddr = new_temp();
                char *rightaddr = newt1;
                int tysize = getTypeSize(ty) >> 2;
                InterCode* code1 = newintercode(GET_ADDR, lefaddr, id);
                appendInterCode(Exp_codes, code1);
                char* tempt = new_temp();
                for(int i=0; i < tysize; i++){
                    InterCode* code2 = newintercode(READ_ADDR, tempt, rightaddr);
                    InterCode* code3 = newintercode(WRITE_ADDR, lefaddr, tempt);
                    appendInterCode(Exp_codes, code2);
                    appendInterCode(Exp_codes, code3);
                    if(i != tysize - 1){
                        InterCode* code4 = newintercode(PLUS, lefaddr, lefaddr, "#4");
                        InterCode* code5 = newintercode(PLUS, rightaddr, rightaddr, "#4");
                        appendInterCode(Exp_codes, code4);
                        appendInterCode(Exp_codes, code5);
                    }
                }
                return Exp_codes;
            }
        }
        char* toff = new_temp();
        Offset info = translateExpOffset(now->down, toff);
        InterCodeList* Exp_codes2 = info.code;

        char *id;
        Node *p = now;
        while(strcmp(p->name, "ID")){
            p = p->down;
        }
        id = p->text;

        if(info.ty->kind == BASIC){
            char* temaddr = new_temp();
            if(!isonParam(id)){
                InterCode* code1 = newintercode(GET_ADDR, temaddr, id);
                appendInterCode(Exp_codes2, code1);
            }
            else{
                InterCode* code1 = newintercode(ASSIGN, temaddr, id);
                appendInterCode(Exp_codes2, code1);
                
            }
            InterCode* code1 = newintercode(PLUS, temaddr, temaddr, toff);
            InterCode* code2 = newintercode(WRITE_ADDR, temaddr, newt1);
            InterCode* code3 = newintercode(ASSIGN, place, newt1);
            appendInterCode(Exp_codes2, code1);
            appendInterCode(Exp_codes2, code2);
            appendInterCodeList(Exp_codes, Exp_codes2);
            appendInterCode(Exp_codes, code3);
            return Exp_codes;
        }
        else{
            char *lefaddr = new_temp();
            char *rightaddr = newt1;
            if(!isonParam(id)){
                InterCode* code1 = newintercode(GET_ADDR, lefaddr, id);
                appendInterCode(Exp_codes2, code1);
            }
            else{
                InterCode* code1 = newintercode(ASSIGN, lefaddr, id);
                appendInterCode(Exp_codes2, code1);
            }
            int tysize = getTypeSize(info.ty) >> 2;
            InterCode* code1 = newintercode(PLUS, lefaddr, lefaddr, toff);
            InterCode* code2 = newintercode(ASSIGN, place, newt1);
            appendInterCode(Exp_codes2, code1);
            appendInterCodeList(Exp_codes, Exp_codes2);
            appendInterCode(Exp_codes, code2);
            char* tempt = new_temp();
            for(int i=0; i < tysize; i++){
                InterCode* code3 = newintercode(READ_ADDR, tempt, rightaddr);
                InterCode* code4 = newintercode(WRITE_ADDR, lefaddr, tempt);
                appendInterCode(Exp_codes, code3);
                appendInterCode(Exp_codes, code4);
                if(i != tysize - 1){
                    InterCode* code5 = newintercode(PLUS, lefaddr, lefaddr, "#4");
                    InterCode* code6 = newintercode(PLUS, rightaddr, rightaddr, "#4");
                    appendInterCode(Exp_codes, code5);
                    appendInterCode(Exp_codes, code6);
                }
            }
            return Exp_codes;
        }
    }
    else if(!strcmp(now->down->name, "FLOAT")){ //FLOAT
        DEBUG_PRINT("FLOAT");
        char* floatstr = malloc(strlen(now->down->text) + 2);
        memset(floatstr, 0, sizeof floatstr);
        floatstr[0] = '#';
        strcpy(floatstr + 1, now->down->text);
        InterCode* code1 = newintercode(ASSIGN, place, floatstr);
        InterCodeList* codes = getInterCodewrapped(code1);
        return codes;
    }
    else if(!strcmp(now->down->name, "INT")){ //INT
        DEBUG_PRINT("INT");
        char* intstr = malloc(strlen(now->down->text) + 2);
        memset(intstr, 0, sizeof intstr);
        intstr[0] = '#';
        strcpy(intstr + 1, now->down->text);
        InterCode* code1 = newintercode(ASSIGN, place, intstr);
        InterCodeList* codes = getInterCodewrapped(code1);
        return codes;
    }
    else if(PLUS_ != NULL){ //PLUS
        DEBUG_PRINT("PLUS");
        char* newt1 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down, newt1);
        char* newt2 = new_temp();
        InterCodeList* exp_codes2 = translateExp(now->down->next->next, newt2);
        InterCode* code1 = newintercode(PLUS, place, newt1, newt2);
        appendInterCodeList(exp_codes1, exp_codes2);
        appendInterCode(exp_codes1, code1);
        return exp_codes1;
    }
    else if(MINUS_ != NULL && strcmp(now->down->name, "MINUS")){ //MINUS
        DEBUG_PRINT("MINUS");
        char* newt1 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down, newt1);
        char* newt2 = new_temp();
        InterCodeList* exp_codes2 = translateExp(now->down->next->next, newt2);
        InterCode* code1 = newintercode(MINUS, place, newt1, newt2);
        appendInterCodeList(exp_codes1, exp_codes2);
        appendInterCode(exp_codes1, code1);
        return exp_codes1;
    }
    else if(STAR_ != NULL){ //STAR
        DEBUG_PRINT("STAR");
        char* newt1 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down, newt1);
        char* newt2 = new_temp();
        InterCodeList* exp_codes2 = translateExp(now->down->next->next, newt2);
        InterCode* code1 = newintercode(STAR, place, newt1, newt2);
        appendInterCodeList(exp_codes1, exp_codes2);
        appendInterCode(exp_codes1, code1);
        return exp_codes1;
    }
    else if(DIV_ != NULL){ //DIV
        DEBUG_PRINT("DIV");
        char* newt1 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down, newt1);
        char* newt2 = new_temp();
        InterCodeList* exp_codes2 = translateExp(now->down->next->next, newt2);
        InterCode* code1 = newintercode(DIV, place, newt1, newt2);
        appendInterCodeList(exp_codes1, exp_codes2);
        appendInterCode(exp_codes1, code1);
        return exp_codes1;
    }
    else if(!strcmp(now->down->name,"MINUS")){ //MINUS(NEG)
        DEBUG_PRINT("MINUS(NEG)");
        char* newt1 = new_temp();
        InterCodeList* exp_codes = translateExp(now->down->next, newt1);
        InterCode* code1 = newintercode(MINUS, place, "#0", newt1);
        appendInterCode(exp_codes, code1);
        return exp_codes;
    }
    else if(AND_ != NULL || OR_ != NULL || NOT_ != NULL || RELOP_ != NULL){ //AND OR NOT RELOP
        DEBUG_PRINT("AND OR NOT RELOP");
        char* newlabel1 = new_label();
        char* newlabel2 = new_label();
        InterCode * code1 = newintercode(ASSIGN, place, "#0");
        InterCode * code2 = newintercode(LABEL, newlabel1);
        InterCode * code3 = newintercode(ASSIGN, place, "#1");
        InterCode * code4 = newintercode(LABEL, newlabel2);
        InterCodeList* nowans = getInterCodewrapped(code1);
        appendInterCodeList(nowans, translateCond(now, newlabel1, newlabel2));
        appendInterCode(nowans, code2);
        appendInterCode(nowans, code3);
        appendInterCode(nowans, code4);
        return nowans;
    }
    else if(!strcmp(now->down->name, "LP")){//LP Exp RP
        DEBUG_PRINT("LP Exp RP");
        return translateExp(get_target_down(now, "Exp"), place);
    }
    else if(LP_ != NULL && !Args_){//ID LP RP
        DEBUG_PRINT("ID LP RP");
        assert(!strcmp(now->down->name, "ID"));
        char* id = now->down->text;
        if(strcmp(id, "read")){
            InterCode* code1 = newintercode(CALL, place, id);
            InterCodeList* codes = getInterCodewrapped(code1);
            return codes;
        }
        else{
            InterCode* code1 = newintercode(READ, place);
            InterCodeList* codes = getInterCodewrapped(code1);
            return codes;
        }
    }
    else if(LP_ != NULL && Args_){//ID LP Args RP
        DEBUG_PRINT("ID LP Args RP");
        char* id = now->down->text;
        ArgList* arglist = malloc(sizeof(ArgList));
        arglist->head = NULL;
        InterCodeList* args_codes = translateArgs(get_target_down(now, "Args"), arglist);
        if(!strcmp(id, "write")){
            InterCode* code1 = newintercode(WRITE, arglist->head->name);
            InterCode* code2 = newintercode(ASSIGN, place, "#0");
            appendInterCode(args_codes, code1);
            appendInterCode(args_codes, code2);
            return args_codes;
        }
        ArgID* nowid = arglist->head;
        InterCodeList* codes2 = empty_InterCodeList();
        Func* func = search_func(table_func, id);
        Arg* funcarg = func->args;
        while(nowid != NULL){
            Type* ty = funcarg->arg_type;
            InterCode* code1 = newintercode(ARGS, nowid->name);
            InterCodeList* nowcodes = getInterCodewrapped(code1);
            appendInterCodeList(codes2, nowcodes);
            nowid = nowid->next;
            funcarg = funcarg->tail;
        }
        InterCode* code3 = newintercode(CALL, place, id);
        appendInterCodeList(args_codes, codes2);
        appendInterCode(args_codes, code3);
        return args_codes;
    }
    else if(DOT_ != NULL || LB_ != NULL){ //Exp DOT ID or Exp LB Exp RB
        DEBUG_PRINT("Exp DOT ID or Exp LB Exp RB");
        Node *p = now;
        char *fromid = NULL;
        while(strcmp(p->name, "ID")){
            p = p->down;
        }
        fromid = p->text;
        InterCodeList* anscodes;
        char* tempaddr = place;
        if(!isonParam(fromid)){
            InterCode* code1 = newintercode(GET_ADDR, tempaddr, fromid);
            anscodes = getInterCodewrapped(code1);
        }
        else{
            InterCode* code1 = newintercode(ASSIGN, tempaddr, fromid);
            anscodes = getInterCodewrapped(code1);
        }
        
        char* toff = new_temp();
        Offset info = translateExpOffset(now, toff);
        appendInterCodeList(anscodes, info.code);
        InterCode* code2 = newintercode(PLUS, tempaddr, tempaddr, toff);
        appendInterCode(anscodes, code2);
        if(info.ty->kind == BASIC){
            InterCode* code3 = newintercode(READ_ADDR, tempaddr, tempaddr);
            appendInterCode(anscodes, code3);
        }
        return anscodes;
    }
    printf("Exp error\n");
    return empty_InterCodeList();
}

Offset translateExpOffset(Node* now, char* place){
    DEBUG_PRINT("translateExpOffset");
    assert(!strcmp(now->name, "Exp"));
    Node *DOT_ = get_target_down(now, "DOT");
    Node *LB_ = get_target_down(now, "LB");
    Node *ID_ = get_target_down(now, "ID");
    Node *Exp_ = get_target_down(now, "Exp");
    
    if(LB_ != NULL){ //Exp LB Exp RB
        if(get_target_down(now->down, "LB")){
            printf("multi-dimensional array error\n");
            exit(0);
        }
        Offset info = translateExpOffset(now->down, place);
        char* newt1 = new_temp();
        InterCodeList* exp_codes1 = translateExp(now->down->next->next, newt1);
        char* elementsizestr = malloc(mylog10_int(info.ty->element_size) + 2);
        memset(elementsizestr, 0, sizeof elementsizestr);
        elementsizestr[0] = '#';
        sprintf(elementsizestr + 1, "%d", info.ty->element_size);
        InterCode* code1 = newintercode(STAR, newt1, newt1, elementsizestr);
        InterCode* code2 = newintercode(PLUS, place, place, newt1);
        appendInterCode(exp_codes1, code1);
        appendInterCode(exp_codes1, code2);
        appendInterCodeList(info.code, exp_codes1);

        Offset ans;
        ans.code = info.code;
        ans.ty = info.ty->elem;
        return ans;
    }
    else if(DOT_ != NULL){ //Exp DOT ID
        Offset info = translateExpOffset(now->down, place);
        assert(info.ty->kind == STRUCTURE);
        FieldList* field = info.ty->structure;
        while(strcmp(field->name, now->down->next->next->text)){
            field = field->tail;
        }
        char* fieldoffset = malloc(mylog10_int(field->offset) + 2);
        memset(fieldoffset, 0, sizeof fieldoffset);
        fieldoffset[0] = '#';  
        sprintf(fieldoffset + 1, "%d", field->offset);
        InterCode* code1 = newintercode(PLUS, place, place, fieldoffset);
        appendInterCode(info.code, code1);
        info.ty = field->type;
        return info;
    }
    else{
        Node* nodeson = now->down;
        assert(!strcmp(nodeson->name, "ID"));
        Type* ty = search_type(table_syn, nodeson->text);

        Offset ans;
        InterCode* code1 = newintercode(ASSIGN, place, "#0");
        InterCodeList* code2 = getInterCodewrapped(code1);
        ans.code = code2;
        ans.ty = ty;
        return ans;
    }
}

char* new_temp(){
    temp_count++;
    char* temp = malloc(mylog10_int(temp_count) + 3);
    memset(temp, 0, sizeof temp);
    temp[0] = 't';
    sprintf(temp + 1, "%d", temp_count);
    return temp;
}

char* new_label(){
    label_count++;
    char* label = malloc(mylog10_int(label_count) + 3);
    memset(label, 0, sizeof label);
    label[0] = 'L';
    sprintf(label + 1, "%d", label_count);
    return label;
}

InterCode* newintercode(int kind, ...){
    InterCode* code = (InterCode*)malloc(sizeof(InterCode));
    code->kind = kind;
    va_list args;
    va_start(args, kind);

    code->kind = kind;
    code->op1 = code->op2 = code->result = NULL;
    code->size = 0;
    code->relop = NULL;

    switch(kind){
        case PLUS:
        case MINUS:
        case STAR:
        case DIV:
            code->result = va_arg(args, char*);
            code->op1 = va_arg(args, char*);
            code->op2 = va_arg(args, char*);
            break;
        case IF_GOTO:
            code->op1 = va_arg(args, char*);
            code->relop = va_arg(args, InterRelop*);
            code->op2 = va_arg(args, char*);
            code->result = va_arg(args, char*);
            break;
        case DEC:
            code->result = va_arg(args, char*);
            code->size = va_arg(args, int);
            break;
        case GOTO:
        case FUNCTION:
        case LABEL:
        case ARGS:
        case RETURN:
        case PARAM:
        case READ:
        case WRITE:
            code->result = va_arg(args, char*);
            break;
        
        case ASSIGN:
        case GET_ADDR:
        case READ_ADDR:
        case WRITE_ADDR:
        case CALL:
            code->result = va_arg(args, char*);
            code->op1 = va_arg(args, char*);
            break;
        default:
            fprintf(stderr, "Unknown InterCode kind for intercode now: %d\n", code->kind);
            exit(0);
    }
    va_end(args);
    return code;
}

InterCodeList* newInterCodeList(){
    InterCodeList* codes = malloc(sizeof(InterCodeList));
    codes->head = codes->tail = NULL;
    return codes;
    
}

InterCodeList* getInterCodewrapped(InterCode* code){
    if(code == NULL) return NULL;
    InterCodeList* codes = malloc(sizeof(InterCodeList));
    codes->head = codes->tail = code;
    return codes;
}

void appendInterCode(InterCodeList* codes, InterCode* code){
    if(codes == NULL){
        codes = getInterCodewrapped(code);
        return;
    }
    if(code == NULL) return;
    if(codes->head == NULL){
        codes->head = codes->tail = code;
    }
    else{
        code->prev = codes->tail;
        codes->tail->next = code;
        codes->tail = code;
    }
}

void appendInterCodeList(InterCodeList* codes1, InterCodeList* codes2){
    if(codes2->head == NULL) return;
    if(codes1->head == NULL){
        codes1->head = codes2->head;
        codes1->tail = codes2->tail;
        return;
    }
    else{
        codes1->tail->next = codes2->head;
        codes2->head->prev = codes1->tail;
        codes1->tail = codes2->tail;
        return;
    }
}

void printInterRelop(InterRelop* relop, FILE* fp){
    if(relop == NULL) return;
    switch(relop->kind){
        case LT:
            fprintf(fp, "<");
            break;
        case GT:
            fprintf(fp, ">");
            break;
        case LEQ:
            fprintf(fp, "<=");
            break;
        case GEQ:
            fprintf(fp, ">=");
            break;
        case EQ:
            fprintf(fp, "==");
            break;
        case NEQ:
            fprintf(fp, "!=");
            break;
        default:
            fprintf(stderr, "Unknown InterRelop kind for intercode now: %d\n", relop->kind);
            exit(0);
    }
}

void printInterCode(InterCode* code, FILE* fp){
    switch(code->kind){
        case PLUS:
            fprintf(fp, "%s := %s + %s", code->result, code->op1, code->op2);
            break;
        case MINUS:
            fprintf(fp, "%s := %s - %s", code->result, code->op1, code->op2);
            break;
        case STAR:
            fprintf(fp, "%s := %s * %s", code->result, code->op1, code->op2);
            break;
        case DIV:
            fprintf(fp, "%s := %s / %s", code->result, code->op1, code->op2);
            break;
        case ASSIGN:
            fprintf(fp, "%s := %s", code->result, code->op1);
            break;
        case IF_GOTO:
            fprintf(fp, "IF %s ", code->op1);
            printInterRelop(code->relop, fp);
            fprintf(fp, " %s GOTO %s", code->op2, code->result);
            break;
        case GOTO:
            fprintf(fp, "GOTO %s", code->result);
            break;
        case LABEL:
            fprintf(fp, "LABEL %s :", code->result);
            break;
        case FUNCTION:
            fprintf(fp, "FUNCTION %s :", code->result);
            break;
        case DEC:
            fprintf(fp, "DEC %s %d", code->result, code->size);
            break;
        case ARGS:
            fprintf(fp, "ARG %s", code->result);
            break;
        case CALL:
            fprintf(fp, "%s := CALL %s", code->result, code->op1);
            break;
        case READ:
            fprintf(fp, "READ %s\n", code->result);
            break;
        case WRITE:
            fprintf(fp, "WRITE %s\n", code->result);
            break;
        case GET_ADDR:
            fprintf(fp, "%s := &%s", code->result, code->op1);
            break;
        case READ_ADDR:
            fprintf(fp, "%s := *%s", code->result, code->op1);
            break;
        case WRITE_ADDR:
            fprintf(fp, "*%s := %s", code->result, code->op1);
            break;
        case RETURN:
            fprintf(fp, "RETURN %s", code->result);
            break;
        case PARAM:
            fprintf(fp, "PARAM %s", code->result);
            break;
        default:
            fprintf(stderr, "Unknown InterCode kind for intercode now: %d\n", code->kind);
            exit(0);
    }
}

void printInterCodeList(InterCodeList* codes, FILE* fp){
    if(codes == NULL) return;
    InterCode* current = codes->head;
    while(current != NULL){
        printInterCode(current, fp);
        fprintf(fp, "\n");
        current = current->next;
    }
}

InterCodeList* empty_InterCodeList(){
    InterCodeList* codes = malloc(sizeof(InterCodeList));
    codes->head = codes->tail = NULL;
    return codes;
}