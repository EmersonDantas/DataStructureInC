#ifndef MAGICTREE_H
#define MAGICTREE_H

#include <stdlib.h>

typedef char String;

typedef struct MagicTreeNode_{
    String* name;
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

MagicTreeNode* magicnode_init(int val);

void preorder(MagicTreeNode *node);