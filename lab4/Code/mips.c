#include "mips.h"

//#define DEBUG_MIPS

#ifdef DEBUG_MIPS
    #define DEBUG_PRINT(format, ...) \
    do { \
        fprintf(stderr, format, ##__VA_ARGS__); \
    } while (0)
#else
    #define DEBUG_PRINT(format, ...) // 无操作
#endif

#define ASSERT(condition) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "Assertion failed: %s, file %s, line %d\n", \
                    #condition, __FILE__, __LINE__); \
            abort(); \
        } \
    } while (0)


HashTable_Offset* table_offset;

void output_mipscode(FILE* file, MipsCodeList* mcl){
    ASSERT(file != NULL);
    MipsCode* now = mcl->head;
    while(now != NULL){
        fprintf(file, "%s\n", now->code);
        now = now->next;
    }
}

void output_mipscode_std(MipsCodeList* mcl){
    MipsCode* now = mcl->head;
    while(now != NULL){
        printf("%s\n", now->code);
        now = now->next;
    }
}

MipsCode* new_mipscode(const char* formatted_code){
    MipsCode *p = (MipsCode*)malloc(sizeof(MipsCode));
    ASSERT(p != NULL);

    size_t length = strlen(formatted_code);
    p->code = (char*)malloc(length + 1);
    ASSERT(p->code != NULL);
    memcpy(p->code, formatted_code, length + 1);

    p->next = p->pre = NULL;
    return p;
}

void add_mipscode(MipsCodeList* mcl, char *pattern, ...){
    DEBUG_PRINT("add_mipscode\n");
    va_list args;
    va_start(args, pattern);
    //MipsCode* mc = new_mipscode(pattern, args);
    int len = vsnprintf(NULL, 0, pattern, args);
    ASSERT(len >= 0);
    char *buffer = (char*)malloc(len + 1);
    ASSERT(buffer != NULL);
    va_end(args);
    va_start(args, pattern);
    vsnprintf(buffer, len + 1, pattern, args);
    va_end(args);
    MipsCode* mc = new_mipscode(buffer);
    free(buffer);
    if(mcl->head == NULL){
        //DEBUG_PRINT("Adding the first element to the list\n");
        mcl->head = mcl->tail = mc;
    }
    else{
        //DEBUG_PRINT("Appending element to existing list\n");
        mcl->tail->next = mc;
        mc->pre = mcl->tail;
        mcl->tail = mc;
    }
    //DEBUG_PRINT("add_mipscode_finished\n");
}

MipsCodeList* new_mipscodelist(){
    MipsCodeList* mcl = (MipsCodeList*)malloc(sizeof(MipsCodeList));
    ASSERT(mcl != NULL);
    mcl->head = mcl->tail = NULL;
    add_mipscode(mcl, ".data");
    add_mipscode(mcl, "_prompt: .asciiz \"Enter an integer:\"");
    add_mipscode(mcl, "_ret: .asciiz \"\\n\"");
    add_mipscode(mcl, ".globl main");
    add_mipscode(mcl, ".text");
    add_mipscode(mcl, "read:");
    add_mipscode(mcl, "  li $v0, 4");
    add_mipscode(mcl, "  la $a0, _prompt");
    add_mipscode(mcl, "  syscall");
    add_mipscode(mcl, "  li $v0, 5");
    add_mipscode(mcl, "  syscall");
    add_mipscode(mcl, "  jr $ra");
    add_mipscode(mcl, "write:");
    add_mipscode(mcl, "  li $v0, 1");
    add_mipscode(mcl, "  syscall");
    add_mipscode(mcl, "  li $v0, 4");
    add_mipscode(mcl, "  la $a0, _ret");
    add_mipscode(mcl, "  syscall");
    add_mipscode(mcl, "  move $v0, $0");
    add_mipscode(mcl, "  jr $ra");
    return mcl;
}

MipsCodeList* translate_icl(InterCodeList* icl){
    table_offset = create_table_offset(HASH_SIZE); //创建栈帧偏移的哈希表
    MipsCodeList* mcl = new_mipscodelist();
    InterCode* ic = icl->head;
    ASSERT(icl->head != NULL);
    while(ic != NULL){
        translate_ic(mcl, ic);
        ic = ic->next;
    }
    return mcl;
};

int param_cnt = 0;
int arg_cnt = 0;
int arg_stack_cnt = 0;

void translate_ic(MipsCodeList* mcl, InterCode* ic){
    //DEBUG_PRINT("translate_ic: %d\n", ic->kind);
    switch(ic->kind){
        case LABEL:{
            add_mipscode(mcl, "%s:", ic->result);
        }break;
        case FUNCTION:{
            add_mipscode(mcl, "%s:", ic->result);
            clear_stack();
            create_sp(mcl, ic);
            param_cnt = 0;
            arg_cnt = 0;
        }break;
        case ASSIGN:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case PLUS:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            if(ic->op2[0] != '#'){
                add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op2));
            }
            else{
                add_mipscode(mcl, "  li $t1, %s", ic->op2 + 1);
            }
            add_mipscode(mcl, "  add $t0, $t0, $t1");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case MINUS:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            if(ic->op2[0] != '#'){
                add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op2));
            }
            else{
                add_mipscode(mcl, "  li $t1, %s", ic->op2 + 1);
            }
            add_mipscode(mcl, "  sub $t0, $t0, $t1");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case STAR:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            if(ic->op2[0] != '#'){
                add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op2));
            }
            else{
                add_mipscode(mcl, "  li $t1, %s", ic->op2 + 1);
            }
            add_mipscode(mcl, "  mul $t0, $t0, $t1");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case DIV:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            if(ic->op2[0] != '#'){
                add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op2));
            }
            else{
                add_mipscode(mcl, "  li $t1, %s", ic->op2 + 1);
            }
            add_mipscode(mcl, "  div $t0, $t1");
            add_mipscode(mcl, "  mflo $t0");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case GET_ADDR:{
            add_mipscode(mcl, "  la $t0, %d($sp)", get_offset(mcl, ic->op1));
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case READ_ADDR:{
            add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            add_mipscode(mcl, "  lw $t0, 0($t0)");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case WRITE_ADDR:{
            add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->result));
            add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op1));
            add_mipscode(mcl, "  sw $t1, 0($t0)");
        }break;
        case GOTO:{
            add_mipscode(mcl, "  j %s", ic->result);
        }break;
        case IF_GOTO:{
            if(ic->op1[0] != '#'){
                add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->op1));
            }
            else{
                add_mipscode(mcl, "  li $t0, %s", ic->op1 + 1);
            }
            if(ic->op2[0] != '#'){
                add_mipscode(mcl, "  lw $t1, %d($sp)", get_offset(mcl, ic->op2));
            }
            else{
                add_mipscode(mcl, "  li $t1, %s", ic->op2 + 1);
            }
            switch(ic->relop->kind){
                case LT: add_mipscode(mcl, "  blt $t0, $t1, %s", ic->result); break;
                case GT: add_mipscode(mcl, "  bgt $t0, $t1, %s", ic->result); break;
                case LEQ: add_mipscode(mcl, "  ble $t0, $t1, %s", ic->result); break;
                case GEQ: add_mipscode(mcl, "  bge $t0, $t1, %s", ic->result); break;
                case EQ: add_mipscode(mcl, "  beq $t0, $t1, %s", ic->result); break;
                case NEQ: add_mipscode(mcl, "  bne $t0, $t1, %s", ic->result); break;
                case NEG: 
                default: ASSERT(0);
            }
        }break;
        case RETURN:{
            add_mipscode(mcl, "  lw $v0, %d($sp)", get_offset(mcl, ic->result));
            add_mipscode(mcl, "  move $sp, $s8");
            add_mipscode(mcl, "  lw $s8, -4($s8)");
            add_mipscode(mcl, "  jr $ra");
        }break;
        case DEC: break;
        case ARGS:{
            if(arg_cnt == 0){
                InterCode* now = ic;
                while(now->kind == ARGS){
                    arg_cnt++;
                    now = now->next;
                }
                arg_stack_cnt = 0;
            }
            add_mipscode(mcl, "  lw $t0, %d($sp)", get_offset(mcl, ic->result));
            if(arg_cnt < 5){
                add_mipscode(mcl, "  move $a%d, $t0", arg_cnt - 1);
            }
            else{
                arg_stack_cnt += 1;
                add_mipscode(mcl, "  sw $t0, -%d($sp)", arg_stack_cnt << 2);
            }
            arg_cnt -= 1;
        }break;
        case CALL:{
            if(arg_stack_cnt > 0){
                add_mipscode(mcl, "  addi $sp, $sp, -%d", arg_stack_cnt << 2);
            }
            add_mipscode(mcl, "  addi $sp, $sp, -4");
            add_mipscode(mcl, "  sw $ra, 0($sp)");
            add_mipscode(mcl, "  jal %s", ic->op1);
            add_mipscode(mcl, "  lw $ra, 0($sp)");
            add_mipscode(mcl, "  addi $sp, $sp, 4");
            if(arg_stack_cnt > 0){
                add_mipscode(mcl, "  addi $sp, $sp, %d", arg_stack_cnt << 2);
                arg_stack_cnt = 0;
            }
            add_mipscode(mcl, "  move $t0, $v0");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case PARAM:{
            param_cnt += 1;
            if(param_cnt < 5){
                add_mipscode(mcl, "  move $t0, $a%d", param_cnt - 1);
            }
            else{
                add_mipscode(mcl, "  lw $t0, %d($s8)", ((param_cnt-5)<<2) + 4);
            }
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case READ:{
            add_mipscode(mcl, "  addi $sp, $sp, -4");
            add_mipscode(mcl, "  sw $ra, 0($sp)");
            add_mipscode(mcl, "  jal read");
            add_mipscode(mcl, "  lw $ra, 0($sp)");
            add_mipscode(mcl, "  addi $sp, $sp, 4");
            add_mipscode(mcl, "  move $t0, $v0");
            add_mipscode(mcl, "  sw $t0, %d($sp)", get_offset(mcl, ic->result));
        }break;
        case WRITE:{
            add_mipscode(mcl, "  lw $a0, %d($sp)", get_offset(mcl, ic->result));
            add_mipscode(mcl, "  addi $sp, $sp, -4");
            add_mipscode(mcl, "  sw $ra, 0($sp)");
            add_mipscode(mcl, "  jal write");
            add_mipscode(mcl, "  lw $ra, 0($sp)");
            add_mipscode(mcl, "  addi $sp, $sp, 4");
            add_mipscode(mcl, "  move $t0, $v0");
        }break;
        default:
            fprintf(stderr, "ic kind fault\n");
            ASSERT(0);
    }
}

HashTable_Offset* create_table_offset(size_t size) {
    HashTable_Offset* hash_table = malloc(sizeof(HashTable_Offset));
    hash_table->size = size;
    hash_table->table = calloc(size, sizeof(HashItem_Offset));
    return hash_table;
}

void insert_offset(HashTable_Offset* hash_table, char* key, int value) {
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

    hash_table->table[index].key = malloc(strlen(key) + 1);
    strcpy(hash_table->table[index].key, key);

    hash_table->table[index].value = value;
    hash_table->table[index].is_occupied = 1;
}

int* search_offset(HashTable_Offset* hash_table, char* key) {
    unsigned int index = hash_pjw(key) % hash_table->size;
    unsigned int original_index = index;

    while (hash_table->table[index].is_occupied != 0) {
        if (hash_table->table[index].is_occupied == 1 &&
            strcmp(hash_table->table[index].key, key) == 0) {
            return &hash_table->table[index].value;
        }
        index = (index + 1) % hash_table->size;
        if (index == original_index) {
            break;
        }
    }
    return NULL; // Not found
}

void clear_table_offset(HashTable_Offset* hash_table) {
    for (size_t i = 0; i < hash_table->size; i++) {
        if (hash_table->table[i].is_occupied == 1) {
            free(hash_table->table[i].key);  // 释放键的内存
            hash_table->table[i].is_occupied = 0;
        }
    }
}


int sp_offset = 0;
void add_offset(char* name){
    DEBUG_PRINT("try_add_offset: %s\n", name);
    //if(search_offset(table_offset, name) == NULL && !(name[0] == 't' && ((name[1] >= '0' && name[1] <= '9') || name[1] == 'N'))){
    if(search_offset(table_offset, name) == NULL){
        //DEBUG_PRINT("add_offset_started: %s\n", name);
        sp_offset++;
        insert_offset(table_offset, name, sp_offset);
        // int *p = search_offset(table_offset, name);
        // ASSERT(p != NULL);
        // *p = sp_offset;
        //DEBUG_PRINT("add_offset_finished: %s\n", name);
    }
}
void dec_offset(MipsCodeList* mcl, char* name, int size){
    DEBUG_PRINT("dec_offset: %s, size = %d\n", name, size);
    sp_offset += (size >> 2);
    insert_offset(table_offset, name, sp_offset);
}
int get_offset(MipsCodeList* mcl, char* name){
    int *p = search_offset(table_offset, name);
    ASSERT(p != NULL);
    DEBUG_PRINT("get_offset: %s, %d\n", name, ((sp_offset - (*p)) << 2));
    return ((sp_offset - (*p)) << 2);
}

// void output_offset(MipsCodeList* mcl, char* name){
// }

void create_sp(MipsCodeList* mcl, InterCode* ic){
    DEBUG_PRINT("create_sp\n");
    ic = ic->next;
    while(ic != NULL && ic->kind != FUNCTION){
        if(ic->kind == DEC){
            dec_offset(mcl, ic->result, ic->size);
        }
        else {
            if(ic->op1 != NULL && ic->op1[0] != '#'){
                add_offset(ic->op1);
            }
            if(ic->op2 != NULL && ic->op2[0] != '#'){
                add_offset(ic->op2);
            }
            if(ic->result != NULL && ic->result[0] != '#'){
                add_offset(ic->result);
            }
        }
        ic = ic->next;
    }
    add_mipscode(mcl, "  addi $sp, $sp, -4");
    add_mipscode(mcl, "  sw $s8, 0($sp)");
    add_mipscode(mcl, "  la $s8, 4($sp)");
    add_mipscode(mcl, "  addi $sp, $sp, -%d", (sp_offset << 2));
}

// void output_sp(MipsCodeList* mcl, InterCode* ic){
// }

void clear_stack(){
    DEBUG_PRINT("clear_stack\n");
    sp_offset = 0;
    clear_table_offset(table_offset);
}
