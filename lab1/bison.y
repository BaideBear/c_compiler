%{
#include "syn_tree.h"
#include <stdio.h>
extern int yylex();
extern void yyrestart(FILE *input_file);
extern int yylineno;
extern bool flex_has_error;
extern bool is_flex_error[9999];
void yyerror(const char *s);
extern Node* root;
bool bison_has_error = 0;
%}

%union {
    Node* node_ins;
}

%token <node_ins> FLOAT INT TYPE STRUCT RETURN IF ELSE WHILE ID SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC

/*TODO： 加入所有非终结符*/
//%type <node_ins> Program ExtDefList ExtDef Specifier ExtDecList FunDec CompSt 


%%

/*
TODO: 完成语法分析的二义性以及语法层面的错误查找
接口使用事例：
S: A B {
    $$ = create_node("S", UNTERMINAL, "\0", @$.first_line)
    build_cfg($$, 2, $1, $2)
    }
错误处理：
S : A error {$$ = NULL; bison_has_error = 1;}
*/


Program: ;

%%

int main(int argc, char **argv) {
    if (argc <= 1) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);

    //use bison
    //yyparse();
    //if(!flex_has_error && !bison_has_error){
    //    print_tree();
    //}


    //unuse bison
    int token;
    while ((token = yylex()) != 0) {
    }


    fclose(f);
    return 0;
}

void yyerror(const char *s) {
    if(!is_flex_error[yylineno]){
        printf("Error type B at Line %d: %s\n", yylineno, s);
        bison_has_error = 1;
    }
}
