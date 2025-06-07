//
// Created by hby on 22-12-2.
//

#include <IR_optimize.h>
#include <live_variable_analysis.h>
#include <constant_propagation.h>
#include <available_expressions_analysis.h>
#include <copy_propagation.h>
#include <loop_invariant_code_motion.h>

void remove_dead_block(IR_function *func) {
    // remove
    for(ListNode_IR_block_ptr *i = func->blocks.head; i;) {
        IR_block *blk = i->val;
        if(blk->dead) { // remove dead block
            RDELETE(IR_block, blk); // IR_block_teardown(blk); free(blk);
            i = VCALL(func->blocks, delete, i);
        } else i = i->nxt;
    }
}

void remove_dead_stmt(IR_block *blk) {
    for(ListNode_IR_stmt_ptr *j = blk->stmts.head; j;) {
        IR_stmt *stmt = j->val;
        if(stmt->dead) { // remove dead stmt
            RDELETE(IR_stmt, stmt); // IR_stmt_teardown(stmt); free(stmt);
            j = VCALL(blk->stmts, delete, j);
            continue;
        } else j = j->nxt;
    }
}


void IR_optimize() {
    ConstantPropagation *constantPropagation;
    AvailableExpressionsAnalysis *availableExpressionsAnalysis;
    CopyPropagation *copyPropagation;
    LiveVariableAnalysis *liveVariableAnalysis;
    for_vec(IR_function_ptr, i, ir_program_global->functions) {
        IR_function *func = *i;

        //// 全局公共表达式消除, 可替换为局部
        {
            //// Constant Propagation
            constantPropagation = NEW(ConstantPropagation);
            worklist_solver((DataflowAnalysis*)constantPropagation, func);
            VCALL(*constantPropagation, printResult, func);
            ConstantPropagation_constant_folding(constantPropagation, func);
            DELETE(constantPropagation);

            //// Available Expressions Analysis
            availableExpressionsAnalysis = NEW(AvailableExpressionsAnalysis);
            AvailableExpressionsAnalysis_merge_common_expr(availableExpressionsAnalysis, func);
            worklist_solver((DataflowAnalysis*)availableExpressionsAnalysis, func); // 将子类强制转化为父类
            VCALL(*availableExpressionsAnalysis, printResult, func);
            AvailableExpressionsAnalysis_remove_available_expr_def(availableExpressionsAnalysis, func);
            DELETE(availableExpressionsAnalysis);
            //// Copy Propagation
            copyPropagation = NEW(CopyPropagation);
            worklist_solver((DataflowAnalysis*)copyPropagation, func);
            VCALL(*copyPropagation, printResult, func);
            CopyPropagation_replace_available_use_copy(copyPropagation, func);
            DELETE(copyPropagation);
        }
        

        //// Constant Propagation (2nd)
        constantPropagation = NEW(ConstantPropagation);
        worklist_solver((DataflowAnalysis*)constantPropagation, func);
        VCALL(*constantPropagation, printResult, func);
        ConstantPropagation_constant_folding(constantPropagation, func);
        DELETE(constantPropagation);

        //// Live Variable Analysis
        while(true) {
            liveVariableAnalysis = NEW(LiveVariableAnalysis);
            worklist_solver((DataflowAnalysis*)liveVariableAnalysis, func); // 将子类强制转化为父类
            VCALL(*liveVariableAnalysis, printResult, func);
            bool updated = LiveVariableAnalysis_remove_dead_def(liveVariableAnalysis, func);
            DELETE(liveVariableAnalysis);
            if(!updated) break;
        }
        
        //// Loop Invariant Code Motion
        build_and_debug_dom_tree(func);
    }
}


static bool is_supported_op(IR_OP_TYPE op) {
    return op == IR_OP_ADD || op == IR_OP_SUB || op == IR_OP_MUL;
}

static int fold_constants(IR_OP_TYPE op, int c1, int c2) {
    switch(op) {
        case IR_OP_ADD: return c1 + c2;
        case IR_OP_SUB: return c1 + c2;
        case IR_OP_MUL: return c1 * c2;
        default: return 0; // 不会执行到这里
    }
}

void peephole_optimize(IR_function *func) {
    for_list(IR_block_ptr, block_iter, func->blocks) {
        IR_block *block = block_iter->val;
        List_IR_stmt_ptr *stmts = &block->stmts;
        
        ListNode_IR_stmt_ptr *prev = NULL;
        ListNode_IR_stmt_ptr *current = stmts->head;
        
        while(current != NULL && current->nxt != NULL) {
            IR_stmt *stmt1 = current->val;
            IR_stmt *stmt2 = current->nxt->val;
            
            if(stmt1->stmt_type == IR_OP_STMT && stmt2->stmt_type == IR_OP_STMT) {
                IR_op_stmt *op_stmt1 = (IR_op_stmt*)stmt1;
                IR_op_stmt *op_stmt2 = (IR_op_stmt*)stmt2;
                
                if(is_supported_op(op_stmt1->op) && 
                   op_stmt1->op == op_stmt2->op) {
                    
                    if(op_stmt1->rs2.is_const) {
                        // =第一个操作数是上一条语句的目标变量，第二个操作数是常量
                        if(!op_stmt2->rs1.is_const && 
                           op_stmt2->rs1.var == op_stmt1->rd && 
                           op_stmt2->rs2.is_const) {
                            
                            int c1 = op_stmt1->rs2.const_val;
                            int c2 = op_stmt2->rs2.const_val;
                            int new_const = fold_constants(op_stmt1->op, c1, c2);
                            
                            // 修改第二条语句的操作数
                            op_stmt2->rs1 = op_stmt1->rs1;
                            op_stmt2->rs2.is_const = true;
                            op_stmt2->rs2.const_val = new_const;
                            
                            // 更新use_vec=
                            op_stmt2->use_vec[0] = op_stmt2->rs1;
                            op_stmt2->use_vec[1] = op_stmt2->rs2;
                            
                            // 跳过下一条语句（已优化）
                            //current = current->nxt;
                        }
                    }
                }
            }
            
            prev = current;
            current = current->nxt;
        }
    }
}

void peephole_optimize_assign_op(IR_function *func) {
    // 遍历函数的所有基本块
    for_list(IR_block_ptr, block_iter, func->blocks) {
        IR_block *block = block_iter->val;
        List_IR_stmt_ptr *stmts = &block->stmts;
        
        ListNode_IR_stmt_ptr *current = stmts->head;
        
        while(current != NULL && current->nxt != NULL) {
            IR_stmt *stmt1 = current->val;
            IR_stmt *stmt2 = current->nxt->val;
            
            // 检查第一条语句是否为二元操作，第二条语句是否为赋值操作
            if(stmt1->stmt_type == IR_OP_STMT && stmt2->stmt_type == IR_ASSIGN_STMT) {
                IR_op_stmt *op_stmt1 = (IR_op_stmt*)stmt1;
                IR_assign_stmt *assign_stmt2 = (IR_assign_stmt*)stmt2;
                
                // 检查二元操作的目标变量是否与赋值操作的源操作数匹配
                if(!assign_stmt2->rs.is_const && 
                   assign_stmt2->rs.var == op_stmt1->rd) {
                    
                    IR_val original_rs = assign_stmt2->rs;
                    IR_var original_rd = op_stmt1->rd;
                    
                    // 修改二元操作的目标变量为赋值操作的目标变量
                    op_stmt1->rd = assign_stmt2->rd;
                    
                    // 修改赋值操作为将结果赋给原始临时变量
                    assign_stmt2->rd = original_rd;
                    assign_stmt2->rs = op_stmt1->rs1;  // 使用二元操作的第一个操作数
                    
                    // 更新use_vec
                    assign_stmt2->use_vec[0] = assign_stmt2->rs;
                    
                    
                    // 跳过下一条语句（已优化）
                    current = current->nxt;
                }
            }
            
            // 移动到下一条语句
            current = current->nxt;
        }
    }
}

// 在整个程序上应用窥孔优化
void apply_peephole_optimization() {
    for_vec(IR_function_ptr, i, ir_program_global->functions) {
        IR_function *func = *i;
        peephole_optimize(func);
        //peephole_optimize_assign_op(func);
    }
}
