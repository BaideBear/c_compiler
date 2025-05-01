#include <stdio.h>
#include "syn_tree.h"
#include "semantic.h"
#include "syn_hash_list.h"
#include "intercode.h"
extern bool bison_has_error;
extern bool flex_has_error;
extern Node *root;
extern int semantic_error;
extern int has_array;
extern void yyrestart(FILE * f);
extern void yyparse();
extern void Program(Node* root);
extern InterCodeList* translateExtDefList(Node* root);
extern void printInterCodeList(InterCodeList* icnow, FILE* out);

int main(int argc, char **argv) {

    printf("1");
    if (argc <= 2) return 1;

    printf("1");
    FILE *f = fopen(argv[1], "r");

    printf("1");
    if (!f) {
        perror(argv[1]);
        return 1;
    }

    printf("1");
    yyrestart(f);

    printf("1");
    yyparse();

    printf("1");
    if(!flex_has_error && !bison_has_error){
       //print_tree();
       printf("0");
       define_lib_func();
       Program(root);
       printf("1");
       if(!semantic_error){
            if(has_array){
                printf("multi-dimensional array\n");
                return 0;
            }
            printf("2");
            InterCodeList *icnow = translateExtDefList(root->down);
            printf("3");
            if(icnow == NULL) {
                printf("Error: Translation returned NULL\n");
                return 1;
            }
            FILE *out = fopen(argv[2], "w");
            if(!out){
                printf("Error: Unable to open output file\n");
                return 1;
            }
            printInterCodeList(icnow, out);
            fclose(out);
            printf("Success!\n");
       }
    }

    fclose(f);
    return 0;
}