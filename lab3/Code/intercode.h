#ifndef INTERCODE_H
#define INTERCODE_H

#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "syn_hash_list.h"
#include "semantic.h"
#include "syn_tree.h"

typedef struct InterRelop InterRelop;
typedef struct InterCode InterCode;
typedef struct InterCodeList InterCodeList;
typedef struct Offset Offset;
typedef struct ArgID ArgID;
typedef struct ArgList ArgList;

struct InterRelop{
    enum{
        LT, GT, LEQ, GEQ, EQ, NEQ, NEG
    }kind;
};

struct InterCode{
    enum { LABEL, FUNCTION, ASSIGN, PLUS, MINUS, STAR, DIV, GET_ADDR, READ_ADDR, WRITE_ADDR, IF_GOTO, GOTO, RETURN, DEC, ARGS, CALL, PARAM, READ, WRITE} kind;
    char* op1, *op2, *result;
    InterRelop* relop;
    int size;
    InterCode* prev;
    InterCode* next;
};

struct InterCodeList{
    InterCode* head;
    InterCode* tail;
};

struct Offset{
    InterCodeList* code;
    Type* ty;
};

struct ArgID{
    char* name;
    struct ArgID* next;
};

struct ArgList{
    ArgID* head;
};

char* new_temp();
char* new_label();

InterCodeList* empty_InterCodeList();
InterCode* newintercode(int kind, ...);
InterCodeList* getInterCodewrapped(InterCode* code);
void appendInterCode(InterCodeList* codes, InterCode* code);
void appendInterCodeList(InterCodeList* codes, InterCodeList* codes2);

InterCodeList* translateExtDefList(Node* now);
InterCodeList* translateExtDef(Node* now);
InterCodeList* translateCompSt(Node* now);
InterCodeList* translateStmtList(Node* now);
InterCodeList* translateStmt(Node* now);
InterCodeList* translateDefList(Node* now);
InterCodeList* translateDef(Node* now);
InterCodeList* translateFunDec(Node* now);
InterCodeList* translateVarList(Node* now);
InterCodeList* translateParamDec(Node* now);
InterCodeList* translateArgs(Node* now, ArgList* arglist);
InterCodeList* translateExp(Node* now, char* place);
InterCodeList* translateCond(Node* now, char* label_true, char* label_false);
InterCodeList* translateVarDecfunction(Node* now);
InterCodeList* translateDec(Node* now);
InterCodeList* translateDecList(Node* now);
Offset translateExpOffset(Node* now, char* place);

void writeonParam(char *name);
bool isonParam(char *name);

void printInterRelop(InterRelop* relop, FILE* file);
void printInterCode(InterCode* code, FILE* file);
void printInterCodeList(InterCodeList* codes, FILE* file);

#endif