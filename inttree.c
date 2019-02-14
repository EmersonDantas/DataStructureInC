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

IntTreeNode* intnode_search(IntTreeNode *node, int val)
{
    if ((node == NULL) || (node -> data == val)) {
        return node;
    }
    if (node -> data > val)
    {
        return intnode_search(node -> left , val);
    }
    else
    {
        return intnode_search(node -> right, val);
    }
    
}

IntTreeNode* tree_max(IntTreeNode *node){
    if(node == NULL) return 0;

    while(node -> right != NULL){
        node = node -> right;
    }
    return node;
}

IntTreeNode* tree_min(IntTreeNode *node){
    if(node == NULL) return 0;

    while(node -> left != NULL){
        node = node -> left;
    }

    return node;
}

void tree_remove(IntTree **tree, IntTreeNode *z){
    IntTreeNode* y;

    if(z -> left == NULL){
        tree_transplant(tree, z, z->right);
    }else{
        if(z -> right == NULL){
            tree_transplant(tree, z, z->left);
        }else{
            y = tree_min(z -> right);

            if(y -> father != z){
                tree_transplant(tree, y, y->right);
                y->right = z->right;
                y->right->father = y;
            }

            tree_transplant(tree, z, y);
            y-> left = z-> left;
            y-> left-> father = y;
        }
    }
}

void node_destry(IntTreeNode *node){
    if(node != NULL){
        node_destroy(node->left);
        node_destroy(node->right);
        free(node);
    }
}

void tree_destroy(IntTree ** tree){
    node_destroy((*tree)->root);
    (*tree)->size = 0;
    free((*tree));
}

