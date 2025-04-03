#include <stdio.h>
#include "syn_tree.h"
#include "syn_hash_list.h"
extern bool bison_has_error;
extern bool flex_has_error;
extern Node *root;
extern void yyrestart(FILE * f);
extern void yyparse();
extern void Program(Node* root);

int main(int argc, char **argv) {
    if (argc <= 1) return 1;
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
    }

    fclose(f);
    return 0;
}