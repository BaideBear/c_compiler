#include <loop_invariant_code_motion.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// 全局存储
DomTreeNode* dom_tree_nodes[MAX_BLOCKS];
int block_count = 0;
IR_block* block_array[MAX_BLOCKS];

LoopInfo loops[MAX_BLOCKS];  // 存储检测到的循环
int loop_count = 0;          // 检测到的循环数量

PreheaderRecord preheader_records[MAX_BLOCKS];  // 存储预头块映射
int preheader_record_count;

/* ====================== 支配关系判断函数 ====================== */
bool is_dominate(IR_block* a, IR_block* b) {
    if (a == b) return true;
    
    int a_idx = -1, b_idx = -1;
    for (int i = 0; i < block_count; i++) {
        if (block_array[i] == a) a_idx = i;
        if (block_array[i] == b) b_idx = i;
    }
    if (a_idx == -1 || b_idx == -1) return false;
    
    DomTreeNode* node = dom_tree_nodes[b_idx];
    while (node != NULL && node->idom != NULL) {
        if (node->idom->block == a) return true;
        node = node->idom;
    }
    return false;
}

int List_IR_block_ptr_size(List_IR_block_ptr* list) {
    int count = 0;
    ListNode_IR_block_ptr* current = list->head;
    while (current != NULL) {
        count++;
        current = current->nxt;
    }
    return count;
}

/* ====================== 支配树构建算法 ====================== */
void build_dominator_tree(IR_function* func) {
    // 初始化全局数组
    memset(dom_tree_nodes, 0, sizeof(dom_tree_nodes));
    block_count = 0;
    // 步骤1: 收集所有基本块并建立索引映射
    for_list(IR_block_ptr, blk, func->blocks) {
        if (block_count >= MAX_BLOCKS) break;
        
        block_array[block_count] = blk->val;
        block_array[block_count]->num = block_count;
        
        // 创建支配树节点
        DomTreeNode* node = malloc(sizeof(DomTreeNode));
        node->block = blk->val;
        node->idom = NULL;
        node->dominated_count = 0;
        memset(node->dominated, 0, sizeof(node->dominated));
        
        dom_tree_nodes[block_count] = node;
        block_count++;
    }
    // 步骤2: 初始化IDom数组
    int idoms[MAX_BLOCKS];
    for (int i = 0; i < block_count; i++) {
        idoms[i] = -1;
    }
    
    // 查找入口块索引
    int entry_index = -1;
    for (int i = 0; i < block_count; i++) {
        if (block_array[i] == func->entry) {
            entry_index = i;
            idoms[i] = i;
            break;
        }
    }
    // 步骤3: 迭代计算直接支配者
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < block_count; i++) {
            if (i == entry_index) continue;
            
            // 获取当前块的前驱
            List_IR_block_ptr *pred_list_ptr = VCALL(func->blk_pred, get, block_array[i]);
            if (!pred_list_ptr || !pred_list_ptr->head) continue;
            
            /*int pred_count = List_IR_block_ptr_size(pred_list_ptr);
            
            // 情况1：只有一个前驱
            if (pred_count == 1) {
                IR_block *pred_blk = pred_list_ptr->head->val;
                int pred_idx = -1;
                
                // 找到前驱块在数组中的索引
                for (int j = 0; j < block_count; j++) {
                    if (block_array[j] == pred_blk) {
                        pred_idx = j;
                        break;
                    }
                }
                
                // 直接设置前驱为IDom
                if (pred_idx != -1 && idoms[i] != pred_idx) {
                    idoms[i] = pred_idx;
                    changed = true;
                }
                continue; // 跳过后续处理
            }*/
            // 找到第一个有IDom的前驱作为初始候选
            int new_idom = -1;
            for_list(IR_block_ptr, pred_ptr, *pred_list_ptr) {
                IR_block *pred_blk = pred_ptr->val;
                for (int idx = 0; idx < block_count; idx++) {
                    if (block_array[idx] == pred_blk && idoms[idx] != -1) {
                        new_idom = idx;
                        break;
                    }
                }
                if (new_idom != -1) break;
            }
            
            if (new_idom == -1) continue;
            
            // 遍历其他前驱，找到共同支配者
            for_list(IR_block_ptr, pred_ptr, *pred_list_ptr) {
                IR_block *pred_blk = pred_ptr->val;
                for (int idx = 0; idx < block_count; idx++) {
                    if (block_array[idx] == pred_blk && idoms[idx] != -1) {
                        int p1 = new_idom;
                        int p2 = idx;
                        
                        // 向上遍历IDom链直到找到共同节点
                        while (p1 != p2) {
                            while (p1 > p2 && idoms[p1] != -1) p1 = idoms[p1];
                            while (p2 > p1 && idoms[p2] != -1) p2 = idoms[p2];
                        }
                        new_idom = p1;
                    }
                }
            }
            
            // 更新IDom
            if (idoms[i] != new_idom) {
                idoms[i] = new_idom;
                changed = true;
            }
        }
    }
    // 步骤4: 构建支配树结构
    for (int i = 0; i < block_count; i++) {
        if (i == entry_index || idoms[i] == -1) continue;
        
        DomTreeNode* node = dom_tree_nodes[i];
        DomTreeNode* idom_node = dom_tree_nodes[idoms[i]];
        node->idom = idom_node;
        
        // 添加到支配的孩子列表
        if (idom_node->dominated_count < MAX_BLOCKS) {
            idom_node->dominated[idom_node->dominated_count++] = node->block;
        }
    }
}

/* ====================== 循环检测函数 ====================== */
void find_loops(IR_function* func) {
    loop_count = 0; // 重置循环计数
    memset(loops, 0, sizeof(loops));
    
    // 1. 检测回边（back edges）
    for (int i = 0; i < block_count; i++) {
        IR_block* B = block_array[i];
        List_IR_block_ptr *succ_list = VCALL(func->blk_succ, get, B);
        if (!succ_list) continue;
        
        for_list(IR_block_ptr, succ_ptr, *succ_list) {
            IR_block* S = succ_ptr->val;
            
            // 如果S支配B，则B->S是回边
            if (is_dominate(S, B)) {
                // 2. 为每个循环头创建循环信息
                LoopInfo loop;
                loop.header = S;
                loop.body_count = 0;
                loop.depth = 0;
                loop.children_count = 0;
                loop.exit_count = 0;
                
                // 3. 收集循环体（使用栈进行DFS）
                int stack[MAX_BLOCKS];
                int top = 0;
                bool visited[MAX_BLOCKS] = {false};
                
                // 将当前块B加入循环体
                stack[top++] = B->num;
                visited[B->num] = true;
                
                // 循环头S始终在循环体中
                loop.body[loop.body_count++] = S;
                
                while (top > 0) {
                    int current_idx = stack[--top];
                    IR_block* current = block_array[current_idx];
                    
                    // 将当前块加入循环体（如果尚未加入）
                    bool already_in_body = false;
                    for (int j = 0; j < loop.body_count; j++) {
                        if (loop.body[j] == current) {
                            already_in_body = true;
                            break;
                        }
                    }
                    if (!already_in_body) {
                        loop.body[loop.body_count++] = current;
                    }
                    
                    // 遍历前驱节点
                    List_IR_block_ptr *pred_list = VCALL(func->blk_pred, get, current);
                    if (!pred_list) continue;
                    
                    for_list(IR_block_ptr, pred_ptr, *pred_list) {
                        IR_block* pred = pred_ptr->val;
                        int pred_idx = pred->num;
                        
                        // 跳过已访问节点和循环头（避免死循环）
                        if (visited[pred_idx] || pred == S) continue;
                        
                        // 将前驱加入栈
                        stack[top++] = pred_idx;
                        visited[pred_idx] = true;
                    }
                }
                
                // 4. 保存检测到的循环
                if (loop_count < MAX_BLOCKS) {
                    loops[loop_count++] = loop;
                }
            }
        }
    }
    
    // 5. 处理嵌套循环（确定嵌套深度）
    for (int i = 0; i < loop_count; i++) {
        for (int j = 0; j < loop_count; j++) {
            if (i == j) continue;
            
            // 检查循环j的头是否在循环i的体中
            bool header_in_body = false;
            for (int k = 0; k < loops[i].body_count; k++) {
                if (loops[i].body[k] == loops[j].header && loops[j].header != loops[i].header) {
                    header_in_body = true;
                    break;
                }
            }
            
            // 如果循环j的头在循环i的体中，增加嵌套深度
            if (header_in_body) {
                loops[j].depth = loops[i].depth + 1;
                
                // 记录子循环关系
                if (loops[i].children_count < MAX_BLOCKS) {
                    loops[i].children_loops[loops[i].children_count++] = j;
                }
            }
        }
    }
    
    // 6. 识别循环出口
    for (int i = 0; i < loop_count; i++) {
        loops[i].exit_count = 0;
        
        // 遍历循环体中的每个块
        for (int j = 0; j < loops[i].body_count; j++) {
            IR_block* blk = loops[i].body[j];
            List_IR_block_ptr* succ_list = VCALL(func->blk_succ, get, blk);
            if (!succ_list) continue;
            
            // 检查每个后继块
            for_list(IR_block_ptr, succ_ptr, *succ_list) {
                IR_block* succ = succ_ptr->val;
                bool in_loop = false;
                
                // 检查后继是否在循环体内
                for (int k = 0; k < loops[i].body_count; k++) {
                    if (loops[i].body[k] == succ) {
                        in_loop = true;
                        break;
                    }
                }
                
                // 如果后继不在循环体内，则是一个出口
                if (!in_loop) {
                    // 避免重复记录
                    bool already_exists = false;
                    for (int k = 0; k < loops[i].exit_count; k++) {
                        if (loops[i].exits[k] == succ) {
                            already_exists = true;
                            break;
                        }
                    }
                    
                    if (!already_exists && loops[i].exit_count < MAX_BLOCKS) {
                        loops[i].exits[loops[i].exit_count++] = succ;
                    }
                }
            }
        }
    }
}

/* ====================== 预头块插入函数 (修复版本) ====================== */
void insert_preheaders(IR_function* func) {
    preheader_record_count = 0;
    static IR_label next_label = 10000; // 预头块标签生成器
    
    for (int i = 0; i < loop_count; i++) {
        IR_block* header = loops[i].header;
        
        // 1. 创建预头块并分配唯一标签
        IR_block* preheader = malloc(sizeof(IR_block));
        IR_block_init(preheader, next_label++);
        
        // 2. 记录预头块映射关系
        preheader_records[preheader_record_count++] = (PreheaderRecord){
            .header = header,
            .preheader = preheader
        };
        
        // 3. 分离循环外前驱
        List_IR_block_ptr* outer_preds_ptr = malloc(sizeof(List_IR_block_ptr));
        List_IR_block_ptr_init(outer_preds_ptr);
        
        List_IR_block_ptr* new_header_preds_ptr = malloc(sizeof(List_IR_block_ptr));
        List_IR_block_ptr_init(new_header_preds_ptr);
        
        // 获取原始前驱列表的深拷贝
        List_IR_block_ptr* original_preds = VCALL(func->blk_pred, get, header);
        List_IR_block_ptr pred_list_copy;
        List_IR_block_ptr_init(&pred_list_copy);
        if (original_preds) {
            for_list(IR_block_ptr, ptr, *original_preds) {
                VCALL(pred_list_copy, push_back, ptr->val);
            }
        }
        
        // 4. 处理每个前驱
        for_list(IR_block_ptr, pred_ptr, pred_list_copy) {
            IR_block* pred = pred_ptr->val;
            bool in_loop = false;
            
            // 检查前驱是否在循环体内
            for (int j = 0; j < loops[i].body_count; j++) {
                if (loops[i].body[j] == pred) {
                    in_loop = true;
                    break;
                }
            }
            
            if (in_loop) {
                VCALL(*new_header_preds_ptr, push_back, pred);
            } else {
                VCALL(*outer_preds_ptr, push_back, pred);
                
                // ==== 修复1：使用正确的API重建后继关系 ====
                List_IR_block_ptr* succ_list_ptr = VCALL(func->blk_succ, get, pred);
                if (succ_list_ptr) {
                    // 创建新后继列表
                    List_IR_block_ptr* new_succs = malloc(sizeof(List_IR_block_ptr));
                    List_IR_block_ptr_init(new_succs);
                    
                    // 复制除header外的所有后继
                    for_list(IR_block_ptr, succ_ptr, *succ_list_ptr) {
                        if (succ_ptr->val != header) {
                            VCALL(*new_succs, push_back, succ_ptr->val);
                        }
                    }
                    // 添加指向预头块的新边
                    VCALL(*new_succs, push_back, preheader);
                    
                    // 替换后继列表
                    VCALL(func->blk_succ, set, pred, new_succs);
                    
                    // ==== 修复2：使用正确的API更新跳转指令 ====
                    if (pred->stmts.head != NULL) {  // 直接检查列表头指针
                        // 获取最后一条语句
                        IR_stmt* last_stmt = pred->stmts.tail->val;
                        // 使用正确的stmt_type成员
                        if (last_stmt->stmt_type == IR_GOTO_STMT) {
                            IR_goto_stmt* goto_stmt = (IR_goto_stmt*)last_stmt;
                            // 使用正确的label成员
                            if (goto_stmt->label == header->label) {
                                goto_stmt->label = preheader->label;
                            }
                        }
                    }
                }
            }
        }
        
        // 5. 设置预头块的前驱和后继
        VCALL(func->blk_pred, set, preheader, outer_preds_ptr);
        
        List_IR_block_ptr* preheader_succ_ptr = malloc(sizeof(List_IR_block_ptr));
        List_IR_block_ptr_init(preheader_succ_ptr);
        VCALL(*preheader_succ_ptr, push_back, header);
        VCALL(func->blk_succ, insert, preheader, preheader_succ_ptr);
        
        // 6. 更新循环头的前驱（强制清空旧前驱）
        List_IR_block_ptr* empty_preds = malloc(sizeof(List_IR_block_ptr));
        List_IR_block_ptr_init(empty_preds);
        
        // 添加循环内前驱和预头块
        VCALL(*new_header_preds_ptr, push_back, preheader);
        VCALL(func->blk_pred, set, header, new_header_preds_ptr);
        
        // 7. 在基本块链表中插入预头块
        ListNode_IR_block_ptr* prev = NULL;
        ListNode_IR_block_ptr* curr = func->blocks.head;
        while (curr) {
            if (curr->val == header) {
                ListNode_IR_block_ptr* new_node = malloc(sizeof(ListNode_IR_block_ptr));
                new_node->val = preheader;
                new_node->nxt = curr;
                
                if (prev) prev->nxt = new_node;
                else func->blocks.head = new_node;
                
                break;
            }
            prev = curr;
            curr = curr->nxt;
        }
        
        // 8. 添加跳转指令到预头块
        IR_goto_stmt* goto_stmt = malloc(sizeof(IR_goto_stmt));
        IR_goto_stmt_init(goto_stmt, header->label);
        VCALL(preheader->stmts, push_back, (IR_stmt*)goto_stmt);
        
        // 9. 更新基本块数组
        if (block_count < MAX_BLOCKS) {
            block_array[block_count] = preheader;
            preheader->num = block_count;
            
            DomTreeNode* node = malloc(sizeof(DomTreeNode));
            node->block = preheader;
            node->idom = NULL;
            node->dominated_count = 0;
            dom_tree_nodes[block_count] = node;
            block_count++;
        }
    }
}

/* ====================== 子循环关系判断接口 ====================== */
bool is_child_loop(int parent_idx, int child_idx) {
    if (parent_idx < 0 || parent_idx >= loop_count || 
        child_idx < 0 || child_idx >= loop_count) {
        return false;
    }
    
    // 检查child_idx是否是parent_idx的直接子循环
    for (int i = 0; i < loops[parent_idx].children_count; i++) {
        if (loops[parent_idx].children_loops[i] == child_idx) {
            return true;
        }
    }
    
    return false;
}

/* ====================== 调试输出函数 ====================== */
void DEBUG_PRINT_LOOPS(IR_function* func) {
    printf("\n===== Detected Loops =====\n");
    
    if (loop_count == 0) {
        printf("No loops found in the function.\n");
        return;
    }
    
    // 按嵌套深度分组输出
    int max_depth = 0;
    for (int i = 0; i < loop_count; i++) {
        if (loops[i].depth > max_depth) max_depth = loops[i].depth;
    }
    
    for (int depth = 0; depth <= max_depth; depth++) {
        printf("\n--- Nesting Depth %d ---\n", depth);
        
        for (int i = 0; i < loop_count; i++) {
            if (loops[i].depth != depth) continue;
            
            printf("Loop with header block #%d:\n", loops[i].header->num);
            
            // 输出循环体
            printf("  Body blocks: ");
            for (int j = 0; j < loops[i].body_count; j++) {
                printf("#%d ", loops[i].body[j]->num);
            }
            printf("\n");
            
            // 输出出口块
            printf("  Exit blocks: ");
            for (int j = 0; j < loops[i].exit_count; j++) {
                printf("#%d ", loops[i].exits[j]->num);
            }
            printf("\n");
            
            // 输出子循环
            printf("  Children loops: ");
            for (int j = 0; j < loops[i].children_count; j++) {
                int child_idx = loops[i].children_loops[j];
                printf("Loop#%d (header #%d) ", child_idx, loops[child_idx].header->num);
            }
            printf("\n");
            
            // 输出预头块
            for (int k = 0; k < preheader_record_count; k++) {
                if (preheader_records[k].header == loops[i].header) {
                    printf("  Preheader block: #%d\n", preheader_records[k].preheader->num);
                    break;
                }
            }
        }
    }
}

/* ====================== 调试输出函数 ====================== */
void DEBUG_PRINT_DOM_TREE(IR_function* func) {
    printf("\n===== Dominator Tree Structure =====\n");
    printf("%-8s %-8s %-20s\n", "Block", "IDom", "Dominated Children");
    
    for (int i = 0; i < block_count; i++) {
        DomTreeNode* node = dom_tree_nodes[i];
        IR_block* blk = block_array[i];
        
        printf("%-8d ", blk->num);
        
        if (node->idom) 
            printf("%-8d ", node->idom->block->num);
        else 
            printf("%-8s ", "ROOT");
        
        printf("[");
        for (int j = 0; j < node->dominated_count; j++) {
            printf("%d ", node->dominated[j]->num);
        }
        printf("]\n");
    }
}

void DEBUG_PRINT_EDGES(IR_function* func) {
    printf("\n===== Control Flow Edges =====\n");
    for (int i = 0; i < block_count; i++) {
        IR_block* blk = block_array[i];
        List_IR_block_ptr* succ_list = VCALL(func->blk_succ, get, blk);
        printf("Block #%d -> [", blk->num);
        if (succ_list) {
            for_list(IR_block_ptr, succ_ptr, *succ_list) {
                printf("#%d ", succ_ptr->val->num);
            }
        }
        printf("]\n");
    }
}

void verify_predecessors(IR_function* func) {
    for (int i = 0; i < block_count; i++) {
        IR_block* blk = block_array[i];
        List_IR_block_ptr* pred_list = VCALL(func->blk_pred, get, blk);
        
        printf("Block #%d 前驱: [", blk->num);
        if (pred_list) {
            for_list(IR_block_ptr, pred_ptr, *pred_list) {
                printf("#%d ", pred_ptr->val->num);
            }
        }
        printf("]\n");
    }
}

/* ====================== 循环不变式外提函数（API规范版） ====================== */
void hoist_invariant_code(IR_function* func) {
    // 1. 按嵌套深度排序（从深到浅）
    for (int i = 0; i < loop_count; i++) {
        for (int j = i + 1; j < loop_count; j++) {
            if (loops[i].depth < loops[j].depth) {
                LoopInfo temp = loops[i];
                loops[i] = loops[j];
                loops[j] = temp;
            }
        }
    }

    // 2. 遍历所有循环（从内层到外层）
    for (int i = 0; i < loop_count; i++) {
        IR_block* preheader = NULL;
        
        // 使用for循环查找预头块（符合API迭代规范）
        for (int k = 0; k < preheader_record_count; k++) {
            if (preheader_records[k].header == loops[i].header) {
                preheader = preheader_records[k].preheader;
                break;
            }
        }
        if (!preheader) continue;

        // 3. 遍历循环体中的所有基本块
        for (int j = 0; j < loops[i].body_count; j++) {
            IR_block* blk = loops[i].body[j];
            ListNode_IR_stmt_ptr* stmt_node = blk->stmts.head;
            ListNode_IR_stmt_ptr* prev_node = NULL;
            
            // 4. 遍历基本块中的所有语句
            while (stmt_node != NULL) {
                IR_stmt* stmt = stmt_node->val;
                ListNode_IR_stmt_ptr* next_node = stmt_node->nxt;
                
                // 5. 使用虚函数表获取def/use信息（严格遵循API）
                IR_var def_var = stmt->vTable->get_def(stmt);
                IR_use use_vec = stmt->vTable->get_use_vec(stmt);
                
                // 6. 跳过不可外提的语句类型
                if (stmt->stmt_type == IR_GOTO_STMT || 
                    stmt->stmt_type == IR_IF_STMT ||
                    stmt->stmt_type == IR_RETURN_STMT ||
                    stmt->stmt_type == IR_CALL_STMT ||
                    stmt->stmt_type == IR_READ_STMT ||
                    stmt->stmt_type == IR_WRITE_STMT ||
                    stmt->stmt_type == IR_STORE_STMT) {
                    prev_node = stmt_node;
                    stmt_node = next_node;
                    continue;
                }

                // 7. 检查循环不变式条件
                bool is_invariant = true;
                
                // 条件1: 循环不变（操作数不变）
                for (int u = 0; u < use_vec.use_cnt; u++) {
                    IR_val val = use_vec.use_vec[u];
                    if (!val.is_const) {
                        // 使用for_list宏遍历循环体
                        for (int k = 0; k < loops[i].body_count; k++) {
                            IR_block* inner_blk = loops[i].body[k];
                            for_list(IR_stmt_ptr, s_node, inner_blk->stmts) {
                                IR_stmt* s = s_node->val;
                                if (s == stmt) continue;
                                
                                // 使用虚函数表获取def
                                if (s->vTable->get_def(s) == val.var) {
                                    is_invariant = false;
                                    break;
                                }
                            }
                            if (!is_invariant) break;
                        }
                    }
                    if (!is_invariant) break;
                }

                // 条件2: 基本块支配所有出口
                if (is_invariant) {
                    for (int e = 0; e < loops[i].exit_count; e++) {
                        if (!is_dominate(blk, loops[i].exits[e])) {
                            is_invariant = false;
                            break;
                        }
                    }
                }

                // 条件3: 循环内无其他赋值
                if (is_invariant && def_var != IR_VAR_NONE) {
                    for (int k = 0; k < loops[i].body_count; k++) {
                        IR_block* inner_blk = loops[i].body[k];
                        for_list(IR_stmt_ptr, s_node, inner_blk->stmts) {
                            IR_stmt* s = s_node->val;
                            if (s == stmt) continue;
                            
                            if (s->vTable->get_def(s) == def_var) {
                                is_invariant = false;
                                break;
                            }
                        }
                        if (!is_invariant) break;
                    }
                }

                // 条件4: 支配所有使用点
                if (is_invariant && def_var != IR_VAR_NONE) {
                    for (int k = 0; k < loops[i].body_count; k++) {
                        IR_block* use_blk = loops[i].body[k];
                        for_list(IR_stmt_ptr, s_node, use_blk->stmts) {
                            IR_stmt* s = s_node->val;
                            IR_use s_use = s->vTable->get_use_vec(s);
                            
                            for (int u = 0; u < s_use.use_cnt; u++) {
                                if (!s_use.use_vec[u].is_const && 
                                    s_use.use_vec[u].var == def_var) {
                                    
                                    if (!is_dominate(blk, use_blk)) {
                                        is_invariant = false;
                                        break;
                                    }
                                }
                            }
                            if (!is_invariant) break;
                        }
                        if (!is_invariant) break;
                    }
                }

                // 8. 外提不变式到预头块（使用VCALL操作链表）
                if (is_invariant) {
                    // 从原基本块移除语句（使用链表API）
                    if (prev_node) {
                        prev_node->nxt = next_node;
                    } else {
                        blk->stmts.head = next_node;
                    }
                    
                    if (next_node) {
                        next_node->pre = prev_node;
                    } else {
                        blk->stmts.tail = prev_node;
                    }
                    
                    // 添加到预头块末尾（使用VCALL宏）
                    VCALL(preheader->stmts, push_back, stmt);
                    
                    // 更新迭代指针
                    stmt_node = next_node;
                } else {
                    prev_node = stmt_node;
                    stmt_node = next_node;
                }
            }
        }
    }
}

void verify_optimization(IR_function* func) {
    printf("===== 循环不变式外提验证 =====\n");
    
    for (int i = 0; i < preheader_record_count; i++) {
        IR_block* preheader = preheader_records[i].preheader;
        int invariant_count = 0;
        
        // 使用for_list统计外提语句
        for_list(IR_stmt_ptr, stmt_node, preheader->stmts) {
            IR_stmt* stmt = stmt_node->val;
            if (stmt->stmt_type != IR_GOTO_STMT) {
                invariant_count++;
            }
        }
        
        printf("预头块 L%d 外提了 %d 条不变式\n", 
               preheader->label, invariant_count);
    }
}

/* ====================== 主入口函数 ====================== */
void build_and_debug_dom_tree(IR_function* func) {
    // 初始构建支配树和循环检测
    printf("0\n");
    build_dominator_tree(func);
    DEBUG_PRINT_DOM_TREE(func);
    
    find_loops(func);
    DEBUG_PRINT_LOOPS(func);
    
    // 插入预头块
    insert_preheaders(func);
    build_dominator_tree(func); // 重建支配树
    
    // 重新检测循环（考虑新块）
    find_loops(func);

    hoist_invariant_code(func);// 执行循环不变式外提
    
    // 调试输出
    DEBUG_PRINT_DOM_TREE(func);
    DEBUG_PRINT_LOOPS(func);
    DEBUG_PRINT_EDGES(func);
    verify_predecessors(func);
    verify_optimization(func);
}