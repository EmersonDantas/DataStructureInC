#include <stdio.h>
#include "magictree.c"

int main(int argc, char** argv){
    MagicTree *mytree;
    magictree_init(&mytree);

    /* file reading here */
    String name;
    int minWeather;

    tree_insert(&mytree,"timbauba", 32);
    tree_insert(&mytree, "Hot", 200);
    tree_insert(&mytree, "cold", -273);
    tree_insert(&mytree, "Waterloo", 0);

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