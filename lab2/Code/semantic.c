#include "semantic.h"

//#define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(str) fprintf(stderr, "%s\n", str)
#else
    #define DEBUG_PRINT(str) // 无操作
#endif


HashTable_Type* table_syn;
HashTable_Func* table_func;

void Program(Node* now){ //在入口进行所有的初始化操作,Program->ExtDefList
    DEBUG_PRINT("Program");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Program"));

    table_syn = create_table_type(HASH_SIZE);
    table_func = create_table_func(HASH_SIZE);
    ExtDefList(now->down);
}
void ExtDefList(Node* now){ //ExtDefList -> ExtDef ExtDefList
    DEBUG_PRINT("ExtDefList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ExtDefList"));

    Node *ExtDef_ = get_target_down(now, "ExtDef");
    Node *ExtDefList_ = get_target_down(now, "ExtDefLIst");
    if(ExtDef_ != NULL) ExtDef(ExtDef_);
    if(ExtDefList_ != NULL) ExtDefList(ExtDefList_);
}
void ExtDef(Node* now){
    DEBUG_PRINT("ExtDef");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ExtDef"));

    Node *Specifier_ = get_target_down(now, "Specifier");
    Type *type_ = Specifier(Specifier_);
    assert(type_ != NULL);
    
    Node *ExtDecList_ = get_target_down(now, "ExtDecList");
    Node *FunDec_ = get_target_down(now, "FunDec");
    if(ExtDecList_ != NULL){ //ExtDef -> Specifier ExtDecList SEMI
        ExtDecList(ExtDecList_, type_);
    }
    else if(FunDec_ != NULL){ //ExtDef -> Specifier FunDec CompSt
        Func* p = FunDec(FunDec_, type_);
        Func* searched = search_func(table_func, p->name);
        if(searched == NULL) insert_func(table_func, p->name, p);
        else printf("Error type 4 at line %d: Redefined function name\n", now->pos);
        CompSt(get_target_down(now, "CompSt"), p);
    }
    else{ //ExtDef -> Specifier SEMI
        return;
    }
}

Type* Specifier(Node* now){
    DEBUG_PRINT("Specifier");
    if(now == NULL) return NULL;
    assert(!strcmp(now->name, "Specifier"));

    Node *TYPE_ = get_target_down(now, "TYPE");
    Node *StructSpecifier_ = get_target_down(now, "StructSpecifier");
    if(TYPE_ != NULL){ // Specifier -> TYPE
        if(!strcmp(TYPE_->text, "int")) return new_basic(INT);
        else return new_basic(FLOAT);
    }
    else{ // Specifier -> StructSpecifier
        return StructSpecifier(StructSpecifier_);
    }
}
Type* StructSpecifier(Node* now){
    DEBUG_PRINT("StructSpecifier");
    if(now == NULL) return NULL;
    assert(!strcmp(now->name, "StructSpecifier"));

    Node *OptTag_ = get_target_down(now, "OptTag");
    Node *DefList_ = get_target_down(now, "DefList");
    Node *Tag_ = get_target_down(now, "Tag");
    if(OptTag_ != NULL){ //StructSpecifier -> STRUCT OptTag LC DefList RC
        Type *struct_ = new_struct();
        DefList_struct(DefList_, struct_);
        if(OptTag_ != NULL){ // OptTag -> ID / epsilon
            if(OptTag_->down != NULL) { //ID
                char* name_struct = OptTag_->down->text;
                Type *searched = search_type(table_syn, name_struct);
                if(searched == NULL) insert_type(table_syn, name_struct, struct_);
                else printf("Error type 16 at line %d: Redefined structure name\n", now->pos);
            }
            else{//epsilon

            }
        }
        return struct_;
    }
    else{ //StructSpecifier -> STRUCT Tag
        char *name_struct = Tag_->down->text; // Tag -> ID
        Type *searched = search_type(table_syn, name_struct);
        if(searched == NULL || searched->kind != STRUCTURE){
            printf("Error type 17 at line %d: The structure was undefined\n", now->pos);
        }
        return searched;
    }
}
void DefList_struct(Node *now, Type* struct_){ // DefList -> Def DefList 特供版，传递structure信息
    DEBUG_PRINT("DefList_struct");
    if(now == NULL) return;
    assert(!strcmp(now->name, "DefList"));

    Node *Def_ = get_target_down(now, "Def");
    Node *DefList_ = get_target_down(now, "DefList");
    Def_struct(Def_, struct_);
    DefList_struct(DefList_, struct_);
}
void Def_struct(Node *now, Type* struct_){ // Def -> Specifier Declist 特供版，传递structure信息
    DEBUG_PRINT("Def_struct");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Def"));

    Node *Specifier_ = get_target_down(now, "Specifier");
    Node *DecList_ = get_target_down(now, "DecList");
    Type* type_ = Specifier(Specifier_);
    DecList_struct(DecList_, struct_, type_);
}
void DecList_struct(Node *now, Type *struct_, Type *ty){ // DecList -> Dec COMMA DecList 特供版，传递structure信息
    DEBUG_PRINT("DecList_struct");
    if(now == NULL) return;
    assert(!strcmp(now->name, "DecList"));

    Node *Dec_ = get_target_down(now, "Dec");
    Node *DecList_ = get_target_down(now, "DecList");
    Dec_struct(Dec_, struct_, ty);
    DecList_struct(DecList_, struct_, ty);
}
void Dec_struct(Node *now, Type *struct_, Type *ty){ // DEc -> VarDec, 有assignop应该报错，struct内不能定义变量值
    DEBUG_PRINT("Dec_struct");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Dec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    Node *ASSIGNOP_ = get_target_down(now, "ASSIGNOP");
    if(ASSIGNOP_ == NULL){
        VarDec_struct(VarDec_, struct_, ty);
    }
    else{
        printf("Error type 15 at line %d: A field of structure has an assignment in defination\n", now->pos);
    }
}
void VarDec_struct(Node *now, Type *struct_, Type *ty){
    DEBUG_PRINT("VarDec_struct");
    if(now == NULL) return;
    assert(!strcmp(now->name, "VarDec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    if(VarDec_ == NULL){ // VarDec -> ID
        //插入结构的域前检查是否有重名的域
        FieldList *p = struct_->structure;
        while(p != NULL){
            if(!strcmp(now->down->text, p->name)){
                printf("Error type 15 at line %d: The same field name in one structure\n", now->pos);
                return;
            }
            p = p->tail;
        }
        add_struct_member(struct_, now->down->text, ty);
    }
    else{ // VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL) printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            VarDec_struct(VarDec_, struct_, new_array(ty, p));
        }
    }
}

void ExtDecList(Node *now, Type *ty){ // ExtDecList -> VarDec (COMMA ExtDecList)
    DEBUG_PRINT("ExtDecList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ExtDecList"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    Node *ExtDecList_ = get_target_down(now, "ExtDecList");
    VarDec(VarDec_, ty);
    ExtDecList(ExtDecList_, ty);
}
void VarDec(Node *now, Type *ty){
    DEBUG_PRINT("VarDec");
    if(now == NULL) return;
    assert(!strcmp(now->name, "VarDec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    if(VarDec_ == NULL){ // VarDec -> id
        Type *searched = search_type(table_syn, now->down->text);
        //printf("At VarDec: %s\n", now->down->text);
        if(searched == NULL) insert_type(table_syn, now->down->text, ty);
        else printf("Error type 3 at line %d: Variable name redefined\n", now->pos);
    }
    else{ //VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL) printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            VarDec(VarDec_, new_array(ty, p));
        }
    }
}
Func* FunDec(Node* now, Type* return_type){ //FunDec -> ID LP (VarList) RP
    DEBUG_PRINT("FunDec");
    if(now == NULL) return NULL;
    assert(!strcmp(now->name, "FunDec"));

    Func *func_now = new_func(now->down->text, return_type);
    Node *VarList_ = get_target_down(now, "VarList");
    if(VarList_ != NULL){
        VarList(VarList_, func_now);
    }
    return func_now;
}
void VarList(Node* now, Func* func_){ // VarList -> ParamDec (VarList)
    DEBUG_PRINT("VarList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "VarList"));
    
    Node *ParamDec_ = get_target_down(now, "ParamDec");
    Node *VarList_ = get_target_down(now, "VarList");
    ParamDec(ParamDec_, func_);
    VarList(VarList_, func_);
}
void ParamDec(Node* now, Func* func_){ // ParamDec -> Specifier VarDec
    DEBUG_PRINT("ParamDec");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ParamDec"));

    Node *Specifier_ = get_target_down(now, "Specifier");
    Node *VarDec_ = get_target_down(now, "VarDec");
    Type *pm_type_ = Specifier(Specifier_);
    Type *pm_type_final = VarDec_func(VarDec_, pm_type_); //判断数组的可能性
    add_func_arg(func_, pm_type_final);
}
Type* VarDec_func(Node* now, Type *ty){ //为Func定制的Type,只是增加了返回值，用来获得形参的信息（数组类型）
    DEBUG_PRINT("VarDec_func");
    if(now == NULL) return NULL;
    assert(!strcmp(now->name, "VarDec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    if(VarDec_ == NULL){ // VarDec -> id
        Type *searched = search_type(table_syn, now->down->text);
        if(searched == NULL) insert_type(table_syn, now->down->text, ty);
        else printf("Error type 3 at line %d: Variable name redefined\n", now->pos);
    }
    else{ //VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL) printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            return VarDec_func(VarDec_, new_array(ty, p));
        }
    }
    return ty;
}

void CompSt(Node *now, Func* func){ // Compst -> LC DefList StmtList RC
    DEBUG_PRINT("CompSt");
    if(now == NULL) return;
    assert(!strcmp(now->name, "CompSt"));

    Node *DefList_ = get_target_down(now, "DefList");
    Node *StmtList_ = get_target_down(now, "StmtList");
    DefList(DefList_);
    StmtList(StmtList_, func);
}
void DefList(Node *now){ // DefList -> Def DefList / epsilon
    DEBUG_PRINT("DefList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "DefList"));

    Node *Def_ = get_target_down(now, "Def");
    Node *DefList_ = get_target_down(now, "DefList");
    Def(Def_);
    DefList(DefList_);
}
void Def(Node *now){ // Def -> Specifier DecList SEMI
    DEBUG_PRINT("Def");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Def"));

    Node *Specifier_ = get_target_down(now, "Specifier");
    Node *DecList_ = get_target_down(now, "DecList");
    Type *type_ = Specifier(Specifier_);
    assert(type_ != NULL);
    DecList(DecList_, type_);
}
void DecList(Node *now, Type* ty){ // DecList -> Dec (COMMA DecList)
    DEBUG_PRINT("DecList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "DecList"));

    Node *Dec_ = get_target_down(now, "Dec");
    Node *DecList_ = get_target_down(now, "DecList");
    Dec(Dec_, ty);
    DecList(DecList_, ty);
}
void Dec(Node *now, Type* ty){
    DEBUG_PRINT("Dec");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Dec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    Node *ASSIGNOP_ = get_target_down(now, "ASSIGNOP");
    Node *Exp_ = get_target_down(now, "Exp");
    VarDec(VarDec_, ty);
    if(ASSIGNOP_ != NULL){ //Dec -> VarDec ASSIGNOP Exp
        Type *right = Exp(Exp_);
        if(!type_compare(right, ty)) printf("Error type 5 at line %d: The struct asides ASSIGNOP mismatched\n", now->pos);
    }
}

void StmtList(Node *now, Func* func_){
    DEBUG_PRINT("StmtList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "StmtList"));

    Node *Stmt_ = get_target_down(now, "Stmt");
    Node *StmtList_ = get_target_down(now, "StmtList");
    Stmt(Stmt_, func_);
    StmtList(StmtList_, func_);
}
void Stmt(Node *now, Func* func_){
    DEBUG_PRINT("Stmt");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Stmt"));

    Node *Exp_ = get_target_down(now, "Exp");
    Node *CompSt_ = get_target_down(now, "CompSt");
    Node *IF_ = get_target_down(now, "IF");
    Node *WHILE_ = get_target_down(now, "WHILE");
    Node *RETURN_ = get_target_down(now, "RETURN");
    if(Exp_ != NULL){ //Exp SEMI
        Type *p = Exp(Exp_);
    }
    else if(CompSt_ != NULL){ //CompSt
        CompSt(CompSt_, func_);
    }
    else if(IF_ != NULL){ // IF LP Exp RP Stmt / IF LP Exp RP Stmt ELSE Stmt
        Type *p = Exp(now->down->next->next);
        Node *stmt_1 = now->down->next->next->next->next;
        Node *maybe_else = now->down->next->next->next->next->next;
        Stmt(stmt_1, func_);
        if(maybe_else != NULL){
            Stmt(maybe_else->next, func_);
        }
    }
    else if(WHILE_ != NULL){ // HILE LP Exp RP Stmt
        Type* p = Exp(get_target_down(now, "Exp"));
        Stmt(get_target_down(now, "Stmt"), func_);
    }
    else if(RETURN_ != NULL){
        Type *return_type = Exp(get_target_down(now, "Exp"));
        if(!type_compare(return_type, func_->return_type)){
            printf("Error type 8 at line %d: Return type mismatched\n", now->pos);
        }
    }
}
Type* Exp(Node *now){
    return NULL;
}
void Args(Node *now, Func* func_){

}