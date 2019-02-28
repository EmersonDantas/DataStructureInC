#include <stdio.h>
#include "magictree.c"

int main(){
    MagicTree *mytree;
    magictree_init(&mytree);

    //file reading here 
    String name;
    int minWeather;
    FILE *op;
    op = fopen("Teste-03.in", "r");

    while (fscanf(op, "%s %d", name, &minWeather) != EOF) {
        tree_insert(&mytree, name, minWeather);
    }

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