%{
#include "syn_tree.h"
#include <stdio.h>
// 其他 C 代码或宏定义
extern int yylex();
extern void yyrestart(FILE *input_file);
void yyerror(const char *s);
%}

%union {
    Node* node_ins;
}

%token <node_ins> FLOAT INT TYPE STRUCT RETURN IF ELSE WHILE ID SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV AND OR DOT NOT LP RP LB RB LC RC



%%

program: ;

%%

int main(int argc, char **argv) {
    if (argc <= 1) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    fclose(f);
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
