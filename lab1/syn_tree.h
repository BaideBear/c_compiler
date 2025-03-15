#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

#define TERMINAL 0x88
#define UNTERMINAL 0x99

struct Node{
    char *name;   //节点的名字 
    int type;     //节点种类（终结符，非终结符）
    char *text;   //节点内容
    int pos;      //代码行号
    Node* up;     //父节点
    Node* down;   //第一个子节点
    Node* next;   //右侧节点
};

Node* root = NULL:

void set_root(Node* node){  //创立根节点
    root = node;
}

Node* create_node(char *name, int type, char *text, int pos){  //创建节点
    Node *node = malloc(sizeof(Node));
    
}

Node* build_cfg(Node* S, int cnt, ...){   //创建文法
    va_list args;  // 定义一个va_list类型的变量
    va_start(args, count);  // 初始化args，使其指向第一个可变参数
    for (int i = 0; i < count; i++) {
        Node* p = va_arg(args, Node*);  // 访问当前参数，并将args指向下一个参数
        
    }
    va_end(args);
}
