#include <stdio.h>
#include "inttree.c"

int main(int argc, char** argv){
    IntTree *mytree;
    int i;
    int myarray[8] = {18,01,23,11,89,71,12,43};

    inttree_init(&mytree);

    for(i = 0; i < 8; i++){
        tree_insert(&mytree, myarray[i]);
    }

    printf("\nPre-Order");
    preorder(mytree -> root);

    printf("\nIn-Order");
    inorder(mytree -> root);

    printf("\nPos-Order");
    posorder(mytree -> root);
    
    return EXIT_SUCCESS;
}