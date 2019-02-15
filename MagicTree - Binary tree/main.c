#include <stdio.h>
#include "magictree.c"

int main(int argc, char** argv){
    MagicTree *mytree;
    magictree_init(&mytree);

    /* file reading here */


    /* prints here */
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