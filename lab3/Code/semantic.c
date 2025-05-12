#include "semantic.h"

//#define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(str) fprintf(stderr, "%s\n", str)
#else
    #define DEBUG_PRINT(str) // 无操作
#endif


HashTable_Type* table_syn;
HashTable_Func* table_func;
int semantic_error = 0;
int has_array = 0;

char * mystrdup(const char *s)
{
   size_t  len = strlen(s) +1;
   void *new = malloc(len);
   if (new == NULL)
      return NULL;
   return (char *)memcpy(new, s, len);
}

void Program(Node* now){ //在入口进行所有的初始化操作,Program->ExtDefList
    DEBUG_PRINT("Program");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Program"));

    table_syn = create_table_type(HASH_SIZE);
    table_func = create_table_func(HASH_SIZE);
    define_lib_func();
    ExtDefList(now->down);
}
void ExtDefList(Node* now){ //ExtDefList -> ExtDef ExtDefList
    DEBUG_PRINT("ExtDefList");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ExtDefList"));

    Node *ExtDef_ = get_target_down(now, "ExtDef");
    Node *ExtDefList_ = get_target_down(now, "ExtDefList");
    if(ExtDef_ != NULL) ExtDef(ExtDef_);
    if(ExtDefList_ != NULL) ExtDefList(ExtDefList_);
}
void ExtDef(Node* now){
    DEBUG_PRINT("ExtDef");
    if(now == NULL) return;
    assert(!strcmp(now->name, "ExtDef"));

    Node *Specifier_ = get_target_down(now, "Specifier");
    Type *type_ = Specifier(Specifier_);
    
    Node *ExtDecList_ = get_target_down(now, "ExtDecList");
    Node *FunDec_ = get_target_down(now, "FunDec");
    if(ExtDecList_ != NULL){ //ExtDef -> Specifier ExtDecList SEMI
        ExtDecList(ExtDecList_, type_);
    }
    else if(FunDec_ != NULL){ //ExtDef -> Specifier FunDec CompSt
        Func* p = FunDec(FunDec_, type_);
        Func* searched = search_func(table_func, p->name);
        if(searched == NULL) insert_func(table_func, p->name, p);
        else{
            printf("Error type 4 at line %d: Redefined function name\n", now->pos);
            semantic_error = 1;
        } 
        CompSt(get_target_down(now, "CompSt"), p);
    }
    else{ //ExtDef -> Specifier SEMI
        return;
    }
}

Type* Specifier(Node* now){
    DEBUG_PRINT("Specifier");
    Type *fault_type = new_fault();
    if(now == NULL) return fault_type;
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
    Type *fault_type = new_fault();
    if(now == NULL) return fault_type;
    assert(!strcmp(now->name, "StructSpecifier"));

    Node *OptTag_ = get_target_down(now, "OptTag");
    Node *DefList_ = get_target_down(now, "DefList");
    Node *Tag_ = get_target_down(now, "Tag");
    //assert(Tag_ != NULL || OptTag_ != NULL);
    if(Tag_ == NULL && OptTag_ == NULL){
        Type *struct_ = new_struct();
        DefList_struct(DefList_, struct_);
        return struct_;
    }
    if(OptTag_ != NULL){ //StructSpecifier -> STRUCT OptTag LC DefList RC
        Type *struct_ = new_struct();
        DefList_struct(DefList_, struct_);
        if(OptTag_ != NULL){ // OptTag -> ID / epsilon
            if(OptTag_->down != NULL) { //ID
                char* name_struct = OptTag_->down->text;
                Type *searched = search_type(table_syn, name_struct);
                if(searched == NULL) insert_type(table_syn, name_struct, struct_);
                else{
                    printf("Error type 16 at line %d: Redefined structure name\n", now->pos);
                    semantic_error = 1;
                }
            }
            else{//epsilon

            }
        }
        FieldList *p = struct_->structure;
        struct_->structure_size = 0;
        while(p != NULL){
            p->size = getTypeSize(p->type);
            p->offset = struct_->structure_size;
            struct_->structure_size += p->size;
            p = p->tail;
        }
        return struct_;
    }
    
    else{ //StructSpecifier -> STRUCT Tag
        assert(Tag_ != NULL);
        char *name_struct = Tag_->down->text; // Tag -> ID
        Type *searched = search_type(table_syn, name_struct);
        if(searched == NULL || searched->kind != STRUCTURE){
            printf("Error type 17 at line %d: The structure was undefined\n", now->pos);
            semantic_error = 1;
            return fault_type;
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
        semantic_error = 1;
        VarDec_struct(VarDec_, struct_, ty);
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
                semantic_error = 1;
                return;
            }
            p = p->tail;
        }
        char* field_name = mystrdup(now->down->text);
        add_struct_member(struct_, field_name, ty);
    }
    else{ // VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL){
            printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);\
            semantic_error = 1;
        } 
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            VarDec_struct(VarDec_, struct_, new_array(ty, p, getTypeSize(ty)));
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
        else{
            printf("Error type 3 at line %d: Variable name redefined\n", now->pos);
            semantic_error = 1;
        } 
    }
    else{ //VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL){
            printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);
            semantic_error = 1;
        }
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            VarDec(VarDec_, new_array(ty, p, getTypeSize(ty)));
        }
    }
}
Func* FunDec(Node* now, Type* return_type){ //FunDec -> ID LP (VarList) RP
    DEBUG_PRINT("FunDec");
    Func* fault_func = new_fault_func();
    if(now == NULL) return fault_func;
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
    if(pm_type_final->kind == ARRAY){
        has_array = 1;
    }
}
Type* VarDec_func(Node* now, Type *ty){ //为Func定制的Type,只是增加了返回值，用来获得形参的信息（数组类型）
    DEBUG_PRINT("VarDec_func");
    Type *fault_type = new_fault();
    if(now == NULL) return fault_type;
    assert(!strcmp(now->name, "VarDec"));

    Node *VarDec_ = get_target_down(now, "VarDec");
    if(VarDec_ == NULL){ // VarDec -> id
        Type *searched = search_type(table_syn, now->down->text);
        if(searched == NULL) insert_type(table_syn, now->down->text, ty);
        else{
            printf("Error type 3 at line %d: Variable name redefined\n", now->pos);
            semantic_error = 1;
        }
    }
    else{ //VarDec -> VarDec LB INT RB
        Node *INT_ = get_target_down(now, "INT");
        if(INT_ == NULL){
            printf("Error type 12 at line %d: Use non-int type in array operand\n", now->pos);
            semantic_error = 1;
        } 
        else{
            char* end;
            int p = (int)strtoul(INT_->text, &end, 10);
            return VarDec_func(VarDec_, new_array(ty, p, getTypeSize(ty)));
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
        Node *p = now;
        while(strcmp(p->name, "ID")){
            p = p->down;
        }
        Type *ty_dec = search_type(table_syn, p->text);
        
        Node *Exp_ = get_target_down(now, "Exp");
        Type *right = Exp(Exp_);
        if(!type_compare(right, ty_dec)){
            printf("Error type 5 at line %d: The struct asides ASSIGNOP mismatched\n", now->pos);
            semantic_error = 1;
        } 
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
    if(CompSt_ != NULL){ //CompSt
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
    else if(WHILE_ != NULL){ // WHILE LP Exp RP Stmt
        Type* p = Exp(get_target_down(now, "Exp"));
        Stmt(get_target_down(now, "Stmt"), func_);
    }
    else if(RETURN_ != NULL){
        Type *return_type = Exp(get_target_down(now, "Exp"));
        if(!type_compare(return_type, func_->return_type)){
            printf("Error type 8 at line %d: Return type mismatched\n", now->pos);
            semantic_error = 1;
        }
    }
    else if(Exp_ != NULL){ //Exp SEMI
        Type *p = Exp(Exp_);
    }
}
bool is_left_value(Node *now){  //检查是否是左值表达式
    Node *next_ = now->down;
    if(!strcmp(next_->name, "ID") && next_->next == NULL) return true;
    else if(get_target_down(now, "LB")) return is_left_value(next_);
    else if(get_target_down(now, "DOT")) return is_left_value(next_);
    else return false;
}
Type* Exp(Node *now){
    DEBUG_PRINT("Exp");
    Type *fault_type = new_fault();
    if(now == NULL) return fault_type;
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
    Node *DOT_ = get_target_down(now, "DOT");
    Node *LP_ = get_target_down(now, "LP");
    Node *ID_ = get_target_down(now, "ID");
    Node *INT_ = get_target_down(now, "INT");
    Node *FLOAT_ = get_target_down(now, "FLOAT");
    Node *Args_ = get_target_down(now, "Args");
    Type *int_example = new_basic(INT);
    Type *float_example = new_basic(FLOAT);
    if(ASSIGNOP_ != NULL){
        Type *t1 = Exp(now->down);
        Type *t2 = Exp(now->down->next->next);
        if(!type_compare(t1, t2)){
            printf("Error type 5 at line %d: Type mismatched\n", now->pos);
            semantic_error = 1;
            return fault_type;
        }
        if(!is_left_value(now->down)) {
            printf("Error type 6 at line %d: Right Value\n", now->pos);
            semantic_error = 1;
        }
        return t1;
    }
    else if(AND_ != NULL || OR_ != NULL){
        Type *t1 = Exp(now->down);
        Type *t2 = Exp(now->down->next->next);
        if(!type_compare(int_example, t1) || !type_compare(int_example, t2)){
            printf("Error type 7 at line %d: Logic operands only accepts int\n", now->pos);
            semantic_error = 1;
        }
        return int_example;
    }
    else if(RELOP_ != NULL || PLUS_ != NULL || STAR_ != NULL || DIV_ != NULL){
        Type *t1 = Exp(now->down);
        Type *t2 = Exp(now->down->next->next);
        if((!type_compare(t1, t2)) || (type_compare(t1, t2) && !type_compare(t1, int_example) && !type_compare(t1, float_example))){
            printf("Error type 7 at line %d: Unmatched type or illeagal type for calculating\n", now->pos);
            semantic_error = 1;
        }
        if(RELOP_ != NULL) return int_example;
        else return t1;
    }
    else if(MINUS_ != NULL){
        if(!strcmp(now->down->name, "MINUS")){
            Type *p = Exp(get_target_down(now, "Exp"));
            if(!type_compare(int_example, p) && !type_compare(float_example, p)){
                printf("Error type 7 at line %d: illeagal type for calculating\n", now->pos);
                semantic_error = 1;
            }
            return p;
        }
        else{
            Type *t1 = Exp(now->down);
            Type *t2 = Exp(now->down->next->next);
            if((!type_compare(t1, t2)) || (type_compare(t1, t2) && !type_compare(t1, int_example) && !type_compare(t1, float_example))){
                printf("Error type 7 at line %d: Unmatched type or illeagal type for calculating\n", now->pos);
                semantic_error = 1;
                return fault_type;
            }
            else return t1;
            
        }
    }
    else if(!strcmp(now->down->name, "LP")){
        return Exp(get_target_down(now, "Exp"));
    }
    else if(NOT_ != NULL){
        Type *p = Exp(get_target_down(now, "Exp"));
        if(!type_compare(int_example, p)) {
            printf("Error type 7 at line %d: Logic operands only accepts int\n", now->pos);
            semantic_error = 1;
            return int_example;
        }
        else return int_example;
    }
    else if(LB_ != NULL){
        Type *t1 = Exp(now->down);
        Type *t2 = Exp(now->down->next->next);
        if(!type_compare(int_example, t2)){
            printf("Error type 12 at line %d: Array index must be int\n", now->pos);
            semantic_error = 1;
        } 
        if(t1->kind != ARRAY){
            printf("Error type 10 at line %d: Index must used by array\n", now->pos);
            semantic_error = 1;
            return t1;
        }
        return t1->elem;
    }
    else if(DOT_ != NULL){
        Type *p = Exp(get_target_down(now, "Exp"));
        if(p->kind != STRUCTURE){
            printf("Error type 13 at line %d: Dot must used after a structure\n", now->pos);
            semantic_error = 1;
            return p;
        }
        char *name_field = get_target_down(now, "ID")->text;
        DEBUG_PRINT(name_field);
        assert(name_field != NULL);
        FieldList *cur = p->structure;
        while(cur != NULL){
            if(strcmp(cur->name, name_field)){
                cur = cur->tail;
                continue; 
            }
            return cur->type;
        }
        printf("Error type 14 at line %d: Undefined field of structure\n", now->pos);
        semantic_error = 1;
        return p;
    }
    else if(ID_ != NULL && LP_ == NULL){
        Type *searched = search_type(table_syn, ID_->text);
        if(searched == NULL){
            printf("Error type 1 at line %d: Undefined variable\n", now->pos);
            semantic_error = 1;
            return fault_type;
        }
        else return searched;
    }
    else if(INT_ != NULL) return int_example;
    else if(FLOAT_ != NULL) return float_example;
    else{
        Func* virtual_func = new_func("A_VERY_UNIQUE_NAME", NULL);
        Args(Args_, virtual_func);
        Func* searched_func = search_func(table_func, ID_->text);
        Type* searched_type = search_type(table_syn, ID_->text);
        if(searched_type != NULL){
            printf("Error type 11 at line %d: Cant call a variable\n", now->pos);
            semantic_error = 1;
            return fault_type;
        }
        else if(searched_func == NULL){
            printf("Error type 2 at line %d: Undefined func\n", now->pos);   
            semantic_error = 1;
            return fault_type;
        }
        else if(!arg_compare(searched_func, virtual_func)){
            printf("Error type 9 at line %d: Unmatching args\n", now->pos); 
            semantic_error = 1;
            return fault_type;
        }
        else return searched_func->return_type;
    }
}
void Args(Node *now, Func* func_){
    DEBUG_PRINT("Args");
    if(now == NULL) return;
    assert(!strcmp(now->name, "Args"));

    Node *Args_ = get_target_down(now, "Args");
    add_func_arg(func_, Exp(get_target_down(now, "Exp")));
    Args(Args_, func_);
}

void define_lib_func(){
    Type* int_type = new_basic(INT);
    Func *funcread = new_func("read", int_type);
    Func *funcwrite = new_func("write", int_type);
    add_func_arg(funcwrite, int_type);
    insert_func(table_func, "read", funcread);
    insert_func(table_func, "write", funcwrite);
}