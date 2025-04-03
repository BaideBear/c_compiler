#ifndef SYN_HASH_LIST_H
#define SYN_HASH_LIST_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define INT 0
#define FLOAT 1
#define HASH_SIZE 16384

typedef struct Type Type;
typedef struct FieldList FieldList;
struct Type{
    enum { BASIC, ARRAY, STRUCTURE, FAULT} kind;
    union {
        int basic; //BASIC, 0->int, 1->float
        struct { Type* elem; int size; }; //ARRAY
        FieldList* structure; //STRUCTURE
    };
};
struct FieldList{
    Type* type;
    char* name;
    FieldList* tail;
};

typedef struct Arg Arg;
struct Arg{
    Type* arg_type;
    Arg* tail;
};
typedef struct Func Func;
struct Func{
    char* name;
    Type* return_type;
    Arg* args;
};

typedef struct HashItem_Type {
    char* key;
    Type* value;
    int is_occupied; // 0 = empty, 1 = occupied, -1 = deleted
} HashItem_Type;
typedef struct HashTable_Type {
    HashItem_Type* table;
    size_t size;
} HashTable_Type;

typedef struct HashItem_Func {
    char* key;
    Func* value;
    int is_occupied; // 0 = empty, 1 = occupied, -1 = deleted
} HashItem_Func;
typedef struct HashTable_Func {
    HashItem_Func* table;
    size_t size;
} HashTable_Func;

unsigned int hash_pjw(char* name);  //哈希函数

HashTable_Type* create_table_type(size_t size); //创建符号表
void insert_type(HashTable_Type* hash_table, char* key, Type* value); //插入符号表
Type* search_type(HashTable_Type* hash_table, char* key); //查询符号表

HashTable_Func* create_table_func(size_t size); //创建函数表
void insert_func(HashTable_Func* hash_table, char* key, Func* value); //插入函数表
Func* search_func(HashTable_Func* hash_table, char* key); //查询函数表

Type* new_fault(); //创建错误类型
Type* new_basic(int basic_); //新建BASIC节点，basic_取值为 INT/FLOAT
Type* new_array(Type* right_type, int size); //新建ARRAY节点，right_type为右侧的类分析（分析是由右至左的）
Type* new_struct(); //穿件新的STRUCTURE空节点
void add_struct_member(Type* struct_now, char* name, Type* type); //在struct_now中追加新的域（末端）
Func* new_fault_func(); //错误返回
Func* new_func(char *name, Type *return_type); //创建新的函数节点
void add_func_arg(Func* func_now, Type* arg_type); //在函数中追加参数（末端）

bool type_compare(Type* x, Type* y); //比较x,y的类型是否相同（嵌入了结构体的结构等价实现）
bool arg_compare(Func *x, Func *y); //比较两个函数的参数是否相同


#endif