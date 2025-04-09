%{
#include "syn_tree.h"
#include <stdio.h>
#include "lex.yy.c"
// extern int yylex();
// extern void yyrestart(FILE *input_file);
// extern int yylineno;
// extern bool flex_has_error;
// extern bool is_flex_error[9999];
void yyerror(const char *s);
extern Node* root;
bool bison_has_error = 0;
%}
%locations
%union {
    Node* node_ins;
}

/*终结符*/
%token <node_ins> FLOAT INT TYPE STRUCT RETURN IF ELSE WHILE ID SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC

/*非终结符*/
%type <node_ins> Program
%type <node_ins> ExtDecList ExtDef ExtDefList 
%type <node_ins> Specifier StructSpecifier OptTag Tag 
%type <node_ins> VarDec FunDec VarList ParamDec 
%type <node_ins> CompSt StmtList Stmt
%type <node_ins> DefList Def DecList Dec
%type <node_ins> Exp Args

/*算符优先级*/
%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left UMINUS
%left LP RP LB RB DOT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE



%%
//flex检查用：
//Program: ;

/*
TODO: 完成语法分析的二义性以及语法层面的错误查找
接口使用样例：
S: A B {
    $$ = create_node("S", UNTERMINAL, "\0", @$.first_line)
    build_cfg($$, 2, $1, $2)
    }
错误处理：
S : A error {$$ = NULL; bison_has_error = 1;}
*/

Program: 
ExtDefList{
    $$ = create_node("Program", UNTERMINAL, "\0", @$.first_line);
    set_root($$);
    build_cfg($$, 1, $1);
}
;

ExtDefList: 
ExtDef ExtDefList{
    $$ = create_node("ExtDefList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| /*epsilong*/{
    $$ = NULL;
}
;

ExtDef:
Specifier ExtDecList SEMI{
    $$ = create_node("ExtDef", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Specifier SEMI{
    $$ = create_node("ExtDef", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| Specifier FunDec CompSt{
    $$ = create_node("ExtDef", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Specifier error{$$ = NULL; bison_has_error = 1;printf("Invalid ExtDef1\n");}
| error Specifier SEMI{$$ = NULL; bison_has_error = 1;printf("Invalid ExtDef2\n");}
| error FunDec CompSt{$$ = NULL; bison_has_error = 1;printf("Invalid ExtDef3\n");}
;

ExtDecList:
VarDec{
    $$ = create_node("ExtDecList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| VarDec COMMA ExtDecList{
    $$ = create_node("ExtDecList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| VarDec error ExtDecList{$$ = NULL; bison_has_error = 1;printf("Invalid ExtDecList1\n");}
| error ExtDecList{$$ = NULL; bison_has_error = 1;printf("Invalid ExtDecList2\n");}
;

Specifier: 
TYPE{
    $$ = create_node("Specifier", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| StructSpecifier{
    $$ = create_node("Specifier", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
;

StructSpecifier:
STRUCT OptTag LC DefList RC{
    $$ = create_node("StructSpecifier", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 5, $1, $2, $3, $4, $5);
}
| STRUCT Tag{
    $$ = create_node("StructSpecifier", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
;

OptTag:
ID{
    $$ = create_node("OptTag", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| /*epsilong*/{
    $$ = NULL;
}
;

Tag:
ID{
    $$ = create_node("Tag", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
;

VarDec:
ID{
    $$ = create_node("VarDec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| VarDec LB INT RB{
    $$ = create_node("VarDec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 4, $1, $2, $3, $4);
}
| VarDec LB INT RB RB{yyerror("syntax error");$$ = NULL; bison_has_error = 1;printf("Invalid VarDec1\n");}
| VarDec LB error RB{$$ = NULL; bison_has_error = 1;printf("Invalid VarDec2\n");}
;

FunDec:
ID LP VarList RP{
    $$ = create_node("FunDec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 4, $1, $2, $3, $4);
}
| ID LP RP{
    $$ = create_node("FunDec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| ID error RP{$$ = NULL; bison_has_error = 1;printf("Invalid FunDec1\n");}
| ID LP error RP{$$ = NULL; bison_has_error = 1;printf("Invalid FunDec2\n");}
;

VarList:
ParamDec COMMA VarList{
    $$ = create_node("VarList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| ParamDec{
    $$ = create_node("VarList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| ParamDec error VarList{$$ = NULL; bison_has_error = 1;printf("Invalid VarList1\n");}
| ParamDec error{$$ = NULL; bison_has_error = 1;printf("Invalid VarList2\n");}
;

ParamDec:
Specifier VarDec{
    $$ = create_node("ParamDec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
;

CompSt:
LC DefList StmtList RC{
    $$ = create_node("CompSt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 4, $1, $2, $3, $4);
}
| LC error RC{$$ = NULL; bison_has_error = 1;printf("Invalid Compst\n");}
;

StmtList:
Stmt StmtList{
    $$ = create_node("StmtList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| /*epsilong*/{
    $$ = NULL;
}
| error StmtList{$$ = NULL; bison_has_error = 1;printf("Invalid StmtList\n");}
;

Stmt:
Exp SEMI{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| CompSt{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| RETURN Exp SEMI{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| IF LP Exp RP Stmt %prec LOWER_THAN_ELSE{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 5, $1, $2, $3, $4, $5);
}
| IF LP Exp RP Stmt ELSE Stmt{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 7, $1, $2, $3, $4, $5, $6, $7);
}
| WHILE LP Exp RP Stmt{
    $$ = create_node("Stmt", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 5, $1, $2, $3, $4, $5);
}
| WHILE error RP{$$ = NULL; bison_has_error = 1;printf("Invalid Stmt1\n");}
| WHILE error RC{$$ = NULL; bison_has_error = 1;printf("Invalid Stmt2\n");}
/*| Exp error{
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: syntax error, ", @1.first_line);
        bison_has_error = 1;
    }
    $$ = NULL; bison_has_error = 1;printf("Invalid Stmt3\n");
}*/
| WHILE LP Exp Stmt{
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: syntax error, ", @1.first_line);
        bison_has_error = 1;
    }
    $$ = NULL; bison_has_error = 1;printf("Invalid Stmt4\n");
}
| RETURN Exp error{$$ = NULL; bison_has_error = 1;printf("Invalid Stmt5\n");}
| RETURN error SEMI{$$ = NULL; bison_has_error = 1;printf("Invalid Stmt6\n");}
| error SEMI{$$ = NULL; bison_has_error = 1;printf("Invalid Stmt7\n");}
;

DefList:
Def DefList{
    $$ = create_node("DefList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| /*epsilong*/{
    $$ = NULL;
}
| error DefList{$$ = NULL; bison_has_error = 1;printf("Invalid DefList\n");}
;

Def:
Specifier DecList SEMI{
    $$ = create_node("Def", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| error DecList SEMI{$$ = NULL; bison_has_error = 1;printf("Invalid Def1\n");}
| Specifier DecList error{$$ = NULL; bison_has_error = 1;printf("Invalid Def2\n");}
| Specifier error SEMI{$$ = NULL; bison_has_error = 1;printf("Invalid Def3\n");}
;

DecList:
Dec{
    $$ = create_node("DecList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| Dec COMMA DecList{
    $$ = create_node("DecList", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Dec error DecList{$$ = NULL; bison_has_error = 1;printf("Invalid DecList\n");}
;

Dec:
VarDec{
    $$ = create_node("Dec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| VarDec ASSIGNOP Exp{
    $$ = create_node("Dec", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
|VarDec error{$$ = NULL; bison_has_error = 1;printf("Invalid Dec\n");}
;

Exp:
Exp ASSIGNOP Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp AND Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp OR Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp RELOP Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp PLUS Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp MINUS Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp STAR Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp DIV Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| LP Exp RP{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| MINUS Exp %prec UMINUS{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| NOT Exp{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 2, $1, $2);
}
| ID LP Args RP{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 4, $1, $2, $3, $4);
}
| ID LP RP{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp LB Exp RB{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 4, $1, $2, $3, $4);
}
| Exp DOT ID{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| ID{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| INT{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| FLOAT{
    $$ = create_node("Exp", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| LP error RP{$$ = NULL; bison_has_error = 1;printf("Invalid Exp1\n");}
| MINUS error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp2\n");}
| ID LP error RP{$$ = NULL; bison_has_error = 1;printf("Invalid Exp3\n");}
| NOT error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp4\n");}
| Exp LB error RB{$$ = NULL; bison_has_error = 1;printf("Invalid Exp5\n");}
| Exp ASSIGNOP error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp6\n");}
| Exp AND error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp7\n");}
| Exp OR error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp8\n");}
| Exp RELOP error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp9\n");}
| Exp PLUS error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp10\n");}
| Exp MINUS error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp11\n");}
| Exp STAR error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp12\n");}
| Exp DIV error{$$ = NULL; bison_has_error = 1;printf("Invalid Exp13\n");}
| Exp error Exp{$$ = NULL; bison_has_error = 1;printf("Invalid Exp15\n");}

;

Args:
Exp COMMA Args{
    $$ = create_node("Args", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 3, $1, $2, $3);
}
| Exp{
    $$ = create_node("Args", UNTERMINAL, "\0", @$.first_line);
    build_cfg($$, 1, $1);
}
| Exp COMMA error{$$ = NULL; bison_has_error = 1;printf("Invalid Args\n");}
;






%%
void yyerror(const char *s) {
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: %s, \n", yylineno, s);
        bison_has_error = 1;
    }
}