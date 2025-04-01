#include "semantic.h"

HashTable_Type* table_syn;
HashTable_Func* table_func;

void Program(Node* now){ //在入口进行所有的初始化操作
    table_syn = create_table_type(HASH_SIZE);
    table_func = create_table_func(HASH_SIZE);
    //调用ExtDefList
}