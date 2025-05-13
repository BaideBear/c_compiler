#include <stdio.h>
#include "syn_tree.h"
#include "semantic.h"
#include "syn_hash_list.h"
#include "intercode.h"
#include "mips.h"
extern bool bison_has_error;
extern bool flex_has_error;
extern Node *root;
extern int semantic_error;
extern int has_array;
extern void yyrestart(FILE * f);
extern void yyparse();
extern void define_lib_func();
extern void Program(Node* root);
extern InterCodeList* translateExtDefList(Node* root);
extern void printInterCodeList(InterCodeList* icnow, FILE* out);

int main(int argc, char **argv) {

    if (argc <= 2) return 1;
    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }

    yyrestart(f);
    yyparse();
    if(!flex_has_error && !bison_has_error){
       //print_tree();
       Program(root);
       if(!semantic_error){
            if(has_array){
                printf("multi-dimensional array\n");
                return 0;
            }
            InterCodeList *icnow = translateExtDefList(root->down);
            if(icnow == NULL) {
                printf("Error: Translation returned NULL\n");
                return 1;
            }
            FILE *out = fopen(argv[2], "w");
            if(!out){
                printf("Error: Unable to open output file\n");
                return 1;
            }
            FILE *out1 = fopen(argv[3], "w");
            printInterCodeList(icnow, out1);
            fclose(out1);
            //MipsCodeList* mcl = translate_icl(icnow);
            //output_mipscode(out, mcl);
            fclose(out);
       }
    }

    fclose(f);
    return 0;
}