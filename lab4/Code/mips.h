#ifndef MIPS_H
#define MIPS_H

#include "intercode.h"
#include "syn_hash_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct MipsCode MipsCode;
struct MipsCode{
    char *code;
    MipsCode* next;
    MipsCode* pre;
};
typedef struct MipsCodeList{
    MipsCode* head;
    MipsCode* tail;
}MipsCodeList;

void output_mipscode(FILE* file, MipsCodeList* mcl); //将mips代码输出到对应的文件中
MipsCode* new_mipscode(const char *formatted_code); //创建新的mips语句
MipsCodeList* new_mipscodelist(); //创建新的mips语句列表，包含可执行mips文件的初始代码
void add_mipscode(MipsCodeList* mcl, char *pattern, ...); //在列表中添加新的mips代码

MipsCodeList* translate_icl(InterCodeList* icl); //中间代码转译
void translate_ic(MipsCodeList* mcl, InterCode* ic);

typedef struct HashItem_Offset {
    char* key;
    int value;
    int is_occupied;   // 0 = empty, 1 = occupied, -1 = deleted
} HashItem_Offset;
typedef struct HashTable_Offset {
    HashItem_Offset* table;
    size_t size;
} HashTable_Offset;

HashTable_Offset* create_table_offset(size_t size);
void insert_offset(HashTable_Offset* hash_table, char* key, int value);
int* search_offset(HashTable_Offset* hash_table, char* key);
void clear_table_offset(HashTable_Offset* hash_table);

void add_offset(char* name);
void dec_offset(MipsCodeList* mcl, char* name, int size);
int get_offset(MipsCodeList* mcl, char* name);
//void output_offset(MipsCodeList* mcl, char* name);

void create_sp(MipsCodeList* mcl, InterCode* ic);
//void output_sp(MipsCodeList* mcl, InterCode* ic);

void clear_stack();


#endif