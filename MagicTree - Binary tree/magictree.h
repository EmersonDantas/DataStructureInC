#ifndef MAGICTREE_H
#define MAGICTREE_H
#define MAXLENGTH 1000

#include <stdlib.h>

typedef char *String;

typedef struct MagicTreeNode_{
    String name;
    int minWeather;

    struct MagicTreeNode_ *left;
    struct MagicTreeNode_ *right;
    struct MagicTreeNode_ *father;
} MagicTreeNode;

/*Definir Estrutura da Arvore Binaria Magica*/

typedef struct MagicTree_{
    int size;
    MagicTreeNode *root;
} MagicTree;

/*Interface publica*/

void magictree_init(MagicTree **tree);

MagicTreeNode* magicnode_init(String name, int minWeather);

void preorder(MagicTreeNode *node);

void inorder(MagicTreeNode *node);

void posorder(MagicTreeNode *node);

MagicTreeNode* magictree_search(MagicTree *tree, String name);

MagicTreeNode* magicnode_search(MagicTreeNode *node, String name);

MagicTreeNode* tree_max(MagicTreeNode *node);

MagicTreeNode* tree_min(MagicTreeNode *node);

void tree_insert(MagicTree **tree, String name, int minWeather);

void tree_transplant(MagicTree **tree, MagicTreeNode *u, MagicTreeNode *v);

void tree_remove(MagicTree **tree, MagicTreeNode *z);

void node_destroy(MagicTreeNode *node);

void tree_destroy(MagicTree **tree);

#define magictree_size(tree) ((tree) -> size)

#define magictree_root(tree) ((tree) -> root)

#define magictree_is_leaf(node) ((node) -> left == NULL && (node) -> right == NULL)

#define magictree_name(node) ((node) -> name)

#define magictree_minWeather(node) ((node) -> minWeather)

#define magictree_left(node) ((node) -> left)

#define magictree_right(node) ((node) -> right)

#endif