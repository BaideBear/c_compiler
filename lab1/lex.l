%option yylineno
%{
    //#define DEBUG_MODE
    //#define NO_BISON
    #include "syn_tree.h"
    #include "bison.tab.h"
    int yycolumn = 1;
    bool flex_has_error = 0;
    bool is_flex_error[9999] = {0};

    #ifdef NO_BISON
    typedef struct YYLTYPE {
    int first_line;
    int first_column;
    int last_line;
    int last_column;
    } YYLTYPE;
    #endif

    YYLTYPE yylloc;

    #define YY_USER_ACTION \
            yylloc.first_line = yylloc.last_line = yylineno; \
            yylloc.first_column = yycolumn; \
            yylloc.last_column = yycolumn + yyleng - 1; \
            yycolumn += yyleng;
%}


INT ([1-9][0-9]*)|0
FLOAT {INT}"."[0-9]+
ID (_|[a-zA-Z])(_|[0-9]|[a-zA-Z])*
SEMI ";"
COMMA ","
ASSIGNOP "="
RELOP ">"|"<"|">="|"<="|"=="|"!="
PLUS "+"
MINUS "-"
STAR "*"
DIV "/"
AND "&&"
OR "||"
DOT "."
NOT "!"
TYPE "int"|"float"
LP "("
RP ")"
LB "["
RB "]"
LC "{"
RC "}"
STRUCT "struct"
RETURN "return"
IF "if"
ELSE "else"
WHILE "while"

%%

"\n"  { 
    yycolumn = 1; 
    #ifdef DEBUG_MODE 
    printf("enter\n"); 
    #endif
} 

[ \t\r]+ {
    #ifdef DEBUG_MODE 
    printf("BLANK\n"); 
    #endif
}

"//" {
    while(input() != '\n') ;
    #ifdef DEBUG_MODE 
    printf("ANO_A\n"); 
    #endif
}

"/*" {
    while (1) {
        int c = input();
        if (c == '*') {
            c = input();
            if (c == '/') {
                break; /* End of comment */
            } else {
                unput(c); /* Not the end, put back the character */
            }
        } else if (c == EOF || c == '\0') {
            /* Handle unexpected EOF within a comment */
            printf("Error type A at Line %d: Miss match \'*/\'\n", yylineno);
            flex_has_error = 1;
            is_flex_error[yylineno] = 1;
            break;
        }
    }
    #ifdef DEBUG_MODE 
    printf("ANO_B\n"); 
    #endif
}

"*/" {
    printf("Error type A at Line %d: Miss match \'*/\'\n", yylineno);
    flex_has_error = 1;
    is_flex_error[yylineno] = 1;
}

{INT}"." {
    printf("Error type A at Line %d: Undifined float number\n", yylineno);
    flex_has_error = 1;
    is_flex_error[yylineno] = 1;
}

{FLOAT} {
    yylval.node_ins = create_node("FLOAT", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("FLOAT: %s\n", yytext); 
    #endif
    return FLOAT;
}

{INT} {
    yylval.node_ins = create_node("INT", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("INT: %s\n", yytext); 
    #endif
    return INT;
}

{TYPE} {
    yylval.node_ins = create_node("TYPE", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("TYPE\n"); 
    #endif
    return TYPE;
}

{STRUCT} {
    yylval.node_ins = create_node("STRUCT", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("STRUCT\n"); 
    #endif
    return STRUCT;
}

{RETURN} {
    yylval.node_ins = create_node("RETURN", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("RETURN\n"); 
    #endif
    return RETURN;
}

{IF} {
    yylval.node_ins = create_node("IF", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("IF\n"); 
    #endif
    return IF;
}

{ELSE} {
    yylval.node_ins = create_node("ELSE", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("ELSE\n"); 
    #endif
    return ELSE;
}

{WHILE} {
    yylval.node_ins = create_node("WHILE", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("WHILE\n"); 
    #endif
    return WHILE;
}

{ID} {
    yylval.node_ins = create_node("ID", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("ID: %s\n", yytext); 
    #endif
    return ID;
}

{SEMI} {
    yylval.node_ins = create_node("SEMI", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("SEMI\n"); 
    #endif
    return SEMI;
}

{COMMA} {
    yylval.node_ins = create_node("COMMA", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("COMMA\n"); 
    #endif
    return COMMA;
}

{RELOP} {
    yylval.node_ins = create_node("RELOP", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("RELOP: %s\n", yytext); 
    #endif
    return RELOP;
}

{ASSIGNOP} {
    yylval.node_ins = create_node("ASSIGNOP", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("ASSIGNOP\n"); 
    #endif
    return ASSIGNOP;
}

{PLUS} {
    yylval.node_ins = create_node("PLUS", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("PLUS\n"); 
    #endif
    return PLUS;
}

{MINUS} {
    yylval.node_ins = create_node("MINUS", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("MINUS\n"); 
    #endif
    return MINUS;
}

{STAR} {
    yylval.node_ins = create_node("STAR", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("STAR\n"); 
    #endif
    return STAR;
}

{DIV} {
    yylval.node_ins = create_node("DIV", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("DIV\n"); 
    #endif
    return DIV;
}

{AND} {
    yylval.node_ins = create_node("AND", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("AND\n"); 
    #endif
    return AND;
}

{OR} {
    yylval.node_ins = create_node("OR", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("OR\n"); 
    #endif
    return OR;
}

{DOT} {
    yylval.node_ins = create_node("DOT", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("DOT\n"); 
    #endif
    return DOT;
}

{NOT} {
    yylval.node_ins = create_node("NOT", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("NOT\n"); 
    #endif
    return NOT;
}

{LP} {
    yylval.node_ins = create_node("LP", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("LP\n"); 
    #endif
    return LP;
}

{RP} {
    yylval.node_ins = create_node("RP", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("RP\n"); 
    #endif
    return RP;
}

{LB} {
    yylval.node_ins = create_node("LB", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("LB\n"); 
    #endif
    return LB;
}

{RB} {
    yylval.node_ins = create_node("RB", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("RB\n"); 
    #endif
    return RB;
}

{LC} {
    yylval.node_ins = create_node("LC", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("LC\n"); 
    #endif
    return LC;
}

{RC} {
    yylval.node_ins = create_node("RC", TERMINAL, yytext, yylineno);
    #ifdef DEBUG_MODE 
    printf("RC\n"); 
    #endif
    return RC;
}

. { 
    printf("Error type A at Line %d: Mysterious characters \'%s\'\n", yylineno, yytext);
    flex_has_error = 1;
    is_flex_error[yylineno] = 1;
}


%%
