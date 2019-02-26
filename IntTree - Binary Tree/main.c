#include <stdio.h>
#include "inttree.c"

int main(int argc, char** argv){
    IntTree *mytree;

    inttree_init(&mytree);

    tree_insert(&mytree, 32);
    tree_insert(&mytree, 200);
    tree_insert(&mytree, -273);
    tree_insert(&mytree, 0);

    printf("\nPre-Order");
    preorder(mytree -> root);

    printf("\nIn-Order");
    inorder(mytree -> root);

    printf("\nPos-Order");
    posorder(mytree -> root);
    
    tree_destroy(&mytree);
    
    printf("\n");
    fflush(stdout);
    
    return EXIT_SUCCESS;
}
