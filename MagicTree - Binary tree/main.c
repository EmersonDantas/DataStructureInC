#include <stdio.h>
#include "magictree.c"

int main(){
    MagicTree *mytree;
    magictree_init(&mytree);

    /* file reading here 
    String name;
    int minWeather;*/

    tree_insert(&mytree, "timbauba", 32);
    tree_insert(&mytree, "Hot", 200);
    tree_insert(&mytree, "cold", -273);
    tree_insert(&mytree, "Waterloo", 0);

    /* prints here */
    printf("\nPre-Order:\n");
    preorder(mytree -> root);

    printf("\nIn-Order:\n");
    inorder(mytree -> root);

    printf("\nPos-Order:\n");
    posorder(mytree -> root);
    
    tree_destroy(&mytree);
    
    printf("\n");
    fflush(stdout);
    
    return EXIT_SUCCESS;
}