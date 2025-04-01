#include "syn_tree.h"

Node* root = NULL;

void set_root(Node* node){  //创立根节点
    root = node;
}

Node* create_node(char *name, int type, char *text, int pos){  //创建节点
    Node *node = malloc(sizeof(Node));
    assert(node != NULL);
    // node->name = strdup(name);   //深拷贝, c99下会有Segmentation fault (core dumped)
    if (name != NULL) {
        node->name = malloc(strlen(name) + 1);  // 分配内存
        assert(node->name != NULL);
        strcpy(node->name, name);  // 复制字符串
    } else {
        node->name = NULL;
    }
    node->type = type;
    //node->text = strdup(text);
    if (text != NULL) {
        node->text = malloc(strlen(text) + 1);  // 分配内存
        assert(node->text != NULL);
        strcpy(node->text, text);  // 复制字符串
    } else {
        node->text = NULL;
    }
    node->pos = pos;
    node->up = NULL;
    node->down = NULL;
    node->next = NULL;
    return node;
}

Node* build_cfg(Node* S, int cnt, ...){   //创建文法 S -> ABC...
    va_list args;  // 定义一个va_list类型的变量
    va_start(args, cnt);  // 初始化args，使其指向第一个可变参数
    Node *tem = NULL;
    for (int i = 0; i < cnt; i++) {
        Node* p = va_arg(args, Node*);  // 访问当前参数，并将args指向下一个参数
        if(p != NULL){
            p->up = S;
            if(tem != NULL) tem->next = p;
            else S->down = p;
            tem = p;
        }
        else{
            continue; //panic模式的容限
        }
    }
    va_end(args);
    return S;
}

void print_tree_rec(Node* node, int depth){ 
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");  // 每层缩进两个空格
    }
    if (node->type == UNTERMINAL) {
        printf("%s (%d)\n", node->name, node->pos);
    } else {
        if ((!strcmp(node->name, "TYPE")) || (!strcmp(node->name, "ID"))){
            printf("%s: %s\n", node->name, node->text);
        }
        else if(!strcmp(node->name, "INT")){
            char* end;
            unsigned int p = strtoul(node->text, &end, 10);
            printf("INT: %u\n", p);
        }
        else if(!strcmp(node->name, "FLOAT")){
            char* end;
            float p = strtof(node->text, &end);
            printf("FLOAT: %f\n", p);
        }
        else{
            printf("%s\n", node->name);
        }
    }
    if(node->down != NULL && node->type == UNTERMINAL) print_tree_rec(node->down, depth + 1);
    if(node->next != NULL) print_tree_rec(node->next, depth);
}

void print_tree() {   // 打印树的结构
    print_tree_rec(root, 0);
}