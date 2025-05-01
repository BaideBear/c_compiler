#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "syn_tree.h"
#include "syn_hash_list.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

void Program(Node* now);
void ExtDefList(Node* now);
void ExtDef(Node* now);  

Type* Specifier(Node* now);
Type* StructSpecifier(Node* now);
void DefList_struct(Node *now, Type* struct_);
void Def_struct(Node *now, Type* struct_);
void DecList_struct(Node *now, Type *struct_, Type *ty);
void Dec_struct(Node *now, Type *struct_, Type *ty);
void VarDec_struct(Node *now, Type *struct_, Type *ty);

void ExtDecList(Node *now, Type *ty);
void VarDec(Node *now, Type *ty);
Func* FunDec(Node* now, Type* return_type);
void VarList(Node* now, Func* func_);
void ParamDec(Node* now, Func* func_);
Type* VarDec_func(Node* now, Type *ty);

void CompSt(Node *now, Func* func);
void DefList(Node *now);
void Def(Node *now);
void DecList(Node *now, Type* ty);
void Dec(Node *now, Type* ty);

void StmtList(Node *now, Func* func_);
void Stmt(Node *now, Func* func_);
Type* Exp(Node *now);
void Args(Node *now, Func* func_);

void define_lib_func();

#endif