#ifndef INTTREE_H
#define INTTREE_H

#include <stdlib.h>

typedef struct IntTreeNode_
{
    int data;

    struct IntTreeNode_ *left;
    struct IntTreeNode_ *right;
    struct IntTreeNode_ *father;

} IntTreeNode;

/*Definir Estrutura da Arvore Binaria de inteiros*/
typedef struct IntTree_
{
    int size;

    IntTreeNode *root;
} IntTree;


/*Interface publica*/
void inttree_init(IntTree **tree);

IntTreeNode* intnode_init(int val);

void preorder(IntTreeNode *node);

void inorder(IntTreeNode *node);

void posorder(IntTreeNode *node);

IntTreeNode* inttree_search(IntTree *tree, int val);

IntTreeNode* intnode_search(IntTreeNode *node, int val);

IntTreeNode* tree_max(IntTreeNode *node);

IntTreeNode* tree_mim(IntTreeNode *node);

void tree_insert(IntTree **tree, int val);

void tree_remove(IntTree **tree, IntTreeNode *z);

void node_destroy(IntTreeNode *node);

void tree_destroy(IntTree **tree);

#define inttree_size(tree) ((tree) -> size)

#define inttree_root(tree) ((tree) -> root)

#define inttree_is_leaf(node) ((node) -> left == NULL && (node) -> right == NULL)

#define inttree_data(node) ((node) -> data)

#define inttree_right(node) ((node) -> right)

#endif