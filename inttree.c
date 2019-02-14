#include <stdlib.h>
#include <stdio.h>

#include "Inttree.h"

void inttree_int(IntTree **tree)
{
    (*tree) = (IntTree*) malloc(sizeof(IntTree));
    (*tree) -> root = NULL;
    (*tree) -> size = 0;
    return;
}

IntTreeNode* intnode_init(int val)
{
    IntTreeNode *z;

    z = (IntTreeNode*) malloc(sizeof(IntTreeNode));

    z -> data = val;
    z -> father = NULL;
    z -> left = NULL;
    z -> right = NULL;

    return z;
}

void preorder(IntTreeNode *node)
{
    if(node != NULL){
        printf("%5d", node -> data);
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(IntTreeNode *node)
{
    if(node != NULL){
        inorder(node -> left);
        printf("%5d", node -> data);
        inorder(node -> right);
    }
}

IntTreeNode* intnode_search(IntTree *tree, int val)
{
    return intnode_search(tree -> root, val);
}

