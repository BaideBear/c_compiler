#include "syn_hash_list.h"

// Type* syn_list[HASH_SIZE];
// Func* func_list[HASH_SIZE];
unsigned int hash_pjw(char* name){
    unsigned int val = 0, i; 
    for (; *name; ++name){
        val = (val << 2) + *name;
        if (i = val & ~0x3fff) val = (val ^ (i >> 12)) & 0x3fff;
    }
    return val;
}

HashTable_Type* create_table_type(size_t size) {
    HashTable_Type* hash_table = malloc(sizeof(HashTable_Type));
    hash_table->size = size;
    hash_table->table = calloc(size, sizeof(HashItem_Type));
    return hash_table;
}
void insert_type(HashTable_Type* hash_table, char* key, Type* value) {
    unsigned int index = hash_pjw(key) % hash_table->size;
    unsigned int original_index = index;

    while (hash_table->table[index].is_occupied == 1) {
        if (strcmp(hash_table->table[index].key, key) == 0) {
            // Replace the existing value
            hash_table->table[index].value = value;
            return;
        }
        index = (index + 1) % hash_table->size;
        if (index == original_index) {
            fprintf(stderr, "Hash table is full!\n");
            return;
        }
    }

    //hash_table->table[index].key = strdup(key);
    hash_table->table[index].key = malloc(strlen(key) + 1);
    strcpy(hash_table->table[index].key, key);
    
    hash_table->table[index].value = value;
    hash_table->table[index].is_occupied = 1;
}
Type* search_type(HashTable_Type* hash_table, char* key) {
    unsigned int index = hash_pjw(key) % hash_table->size;
    unsigned int original_index = index;

    while (hash_table->table[index].is_occupied != 0) {
        if (hash_table->table[index].is_occupied == 1 &&
            strcmp(hash_table->table[index].key, key) == 0) {
            return hash_table->table[index].value;
        }
        index = (index + 1) % hash_table->size;
        if (index == original_index) {
            break; // We've looped all the way around
        }
    }
    return NULL; // Not found
}

HashTable_Func* create_table_func(size_t size) {
    HashTable_Func* hash_table = malloc(sizeof(HashTable_Func));
    hash_table->size = size;
    hash_table->table = calloc(size, sizeof(HashItem_Func));
    return hash_table;
}
void insert_func(HashTable_Func* hash_table, char* key, Func* value) {
    unsigned int index = hash_pjw(key) % hash_table->size;
    unsigned int original_index = index;

    while (hash_table->table[index].is_occupied == 1) {
        if (strcmp(hash_table->table[index].key, key) == 0) {
            // Replace the existing value
            hash_table->table[index].value = value;
            return;
        }
        index = (index + 1) % hash_table->size;
        if (index == original_index) {
            fprintf(stderr, "Hash table is full!\n");
            return;
        }
    }

    //hash_table->table[index].key = strdup(key);
    hash_table->table[index].key = malloc(strlen(key) + 1);
    strcpy(hash_table->table[index].key, key);

    hash_table->table[index].value = value;
    hash_table->table[index].is_occupied = 1;
}
Func* search_func(HashTable_Func* hash_table, char* key) {
    unsigned int index = hash_pjw(key) % hash_table->size;
    unsigned int original_index = index;

    while (hash_table->table[index].is_occupied != 0) {
        if (hash_table->table[index].is_occupied == 1 &&
            strcmp(hash_table->table[index].key, key) == 0) {
            return hash_table->table[index].value;
        }
        index = (index + 1) % hash_table->size;
        if (index == original_index) {
            break; // We've looped all the way around
        }
    }
    return NULL; // Not found
}

Type* new_fault(){
    Type* p = malloc(sizeof(Type));
    p->kind = FAULT;
    return p;
}

Type* new_basic(int basic_){ //basic_: INT/FLOAT
    Type* p = malloc(sizeof(Type));
    p->kind = BASIC;
    p->basic = basic_;
    return p;
}

Type* new_array(Type* right_type, int size, int element_size){ //right_type: 右侧的类分析（分析是由右至左的）
    Type* p = malloc(sizeof(Type));
    p->kind = ARRAY;
    p->elem = right_type;
    p->size = size;
    p->element_size = element_size;
    return p;
}

Type* new_struct(){
    Type* p = malloc(sizeof(Type));
    p->kind = STRUCTURE;
    p->structure = NULL;
    return p;
}
void add_struct_member(Type* struct_now, char* name, Type* ty){
    FieldList *p = malloc(sizeof(FieldList));
    p->name = name;
    p->type = ty;
    p->tail = NULL;

    FieldList *now = struct_now->structure;
    FieldList *pst = NULL;
    while(now != NULL){
        pst = now;
        now = now->tail;
    }
    if(now == NULL && pst == NULL){
        struct_now->structure = p;
    }else{
        pst->tail = p;
    }
}

Func* new_fault_func(){
    Func *p = malloc(sizeof(Func));
    char *ch = malloc(sizeof(char)*100);
    p->name = ch;
    p->return_type = new_fault();
    p->args = NULL;
    return p;
}

Func* new_func(char *name, Type *return_type){
    Func *p = malloc(sizeof(Func));
    p->name = name;
    p->return_type = return_type;
    p->args = NULL;
    return p;
}
void add_func_arg(Func* func_now, Type* arg_type){
    Arg* p = malloc(sizeof(Arg));
    p->arg_type = arg_type;
    p->tail = NULL;

    Arg *now = func_now->args;
    Arg *pst = NULL;
    while(now != NULL){
        pst = now;
        now = now->tail;
    }
    // if(now == NULL){
    //     now = p;
    // }else{
    //     pst->tail = p;
    // }
    if(now == NULL && pst == NULL){
        func_now->args = p;
    }
    else{
        pst->tail = p;
    }
}

bool type_compare(Type* x, Type* y){
    if(x == NULL || y == NULL) return false;
    else if(x->kind != y->kind) return false;
    else if(x->kind == BASIC){
        if(x->basic != y->basic) return false;
        else return true;
    }
    else if(x->kind == ARRAY){
        return type_compare(x->elem, y->elem);
    }
    else{ //x->kind == STRUCTURE
        FieldList *x_ = x->structure, *y_ = y->structure;
        while(1){
            if(x_ == NULL && y_ == NULL) return true;
            else if(x_ == NULL || y_ == NULL) return false;
            else if(!type_compare(x_->type, y_->type)) return false;
            x_ = x_->tail;
            y_ = y_->tail;
        }
    }
}

bool arg_compare(Func *x, Func *y){
    Arg *x_ = x->args, *y_ = y->args;
    while(1){
        if(x_ == NULL && y_ == NULL) return true;
        else if(x_ == NULL || y_ == NULL) return false;
        else if(!type_compare(x_->arg_type, y_->arg_type)) {
            return false;
        }
        x_ = x_->tail;
        y_ = y_->tail;
    }
}

Arg* new_arg(Type *arg_type){
    Arg* p = malloc(sizeof(Arg));
    p->arg_type = arg_type;
    p->tail = NULL;
    return p;
}

int getTypeSize(Type* ty){
    if(ty == NULL) return 0;
    else if(ty->kind == BASIC){
        return 4;
    }
    else if(ty->kind == ARRAY){
        return ty->size * ty->element_size;
    }
    else if(ty->kind == STRUCTURE){
        return ty->structure_size;
    }
}