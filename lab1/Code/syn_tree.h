#ifndef SYN_TREE_H
#define SYN_TREE_H 

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h> 
#include <errno.h>
#include <assert.h> 

#define TERMINAL 0x88
#define UNTERMINAL 0x99

typedef struct Node{
    char *name;   //节点的名字 
    int type;     //节点种类（终结符，非终结符）
    char *text;   //节点内容
    int pos;      //代码行号
    struct Node* up;     //父节点
    struct Node* down;   //第一个子节点
    struct Node* next;   //右侧节点
}Node;

void set_root(Node* node);  //创立根节点

Node* create_node(char *name, int type, char *text, int pos); //创建节点

Node* build_cfg(Node* S, int cnt, ...);   //创建文法 S -> ABC...

void print_tree_rec(Node* node, int depth);

void print_tree();   // 打印树的结构

#endif