#ifndef LOOP_INVARIANT_CODE_MOTION_H
#define LOOP_INVARIANT_CODE_MOTION_H

#include <dataflow_analysis.h>  // 包含项目已有的集合/链表实现

#define MAX_BLOCKS 3000
#define IS_DEBUG_PRINT_OPEN true // 是否开启调试输出

// 循环结构体（使用已有数据结构替换）
typedef struct Loop {
    IR_block *header;           // 循环头块
    Map_IR_block_ptr_int body;  // 循环体集合（键:块指针, 值:占位符）[8,9](@ref)
    List_IR_block_ptr exits;    // 出口块列表
    IR_block *preheader;        // 预头块（用于外提不变式）
} Loop, *Loop_ptr;

DEF_LIST(Loop_ptr);

// 函数声明
bool is_dominate(IR_block* a, IR_block* b); // 判断a是否支配b
bool is_child_loop(int parent_idx, int child_idx); // 判断子循环关系

int List_IR_block_ptr_size(List_IR_block_ptr* list); // 获取列表大小

void build_dominator_tree(IR_function* func);// 构建支配树
void find_loops(IR_function* func);         // 检测循环
void insert_preheaders(IR_function* func); // 插入预头块

void DEBUG_PRINT_DOM_TREE(IR_function* func);// 调试输出支配树信息
void DEBUG_PRINT_LOOPS(IR_function* func); // 调试输出循环信息
void DEBUG_PRINT_EDGES(IR_function* func); // 调试输出控制流边信息
void verify_predecessors(IR_function* func); // 验证前驱关系

void build_and_debug_dom_tree(IR_function* func);  //主函数，在IR_optimize中调用



/* ====================== 支配树数据结构 ====================== */
typedef struct DomTreeNode {
    IR_block* block;
    struct DomTreeNode* idom;
    int dominated_count;
    IR_block* dominated[MAX_BLOCKS];
} DomTreeNode;

/* ====================== 循环检测数据结构 ====================== */
typedef struct {
    IR_block* header;          // 循环头节点
    int body_count;            // 循环体中基本块的数量
    IR_block* body[MAX_BLOCKS]; // 循环体包含的基本块
    int exit_count;            // 出口块数量
    IR_block* exits[MAX_BLOCKS]; // 循环出口块
    int depth;                 // 嵌套深度
    int children_count;        // 子循环数量
    int children_loops[MAX_BLOCKS]; // 子循环索引
} LoopInfo;

/* ====================== 预头块管理 ====================== */
typedef struct {
    IR_block* header;      // 循环头节点
    IR_block* preheader;    // 对应的预头块
} PreheaderRecord;

#endif // LOOP_INVARIANT_CODE_MOTION_H