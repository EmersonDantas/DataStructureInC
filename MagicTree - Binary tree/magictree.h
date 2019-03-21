/**
* @file magictree.h
* @brief Arquivo de cabeçalho para a Árvore de Busca Binária
*
*/

/*****************************************
*   Defines
******************************************/
#ifndef MAGICTREE_H
#define MAGICTREE_H
#define MAXLENGTH 1000

#define magictree_size(tree) ((tree) -> size)

#define magictree_root(tree) ((tree) -> root)

#define magictree_is_leaf(node) ((node) -> left == NULL && (node) -> right == NULL)

#define magictree_name(node) ((node) -> name)

#define magictree_minWeather(node) ((node) -> minWeather)

#define magictree_left(node) ((node) -> left)

#define magictree_right(node) ((node) -> right)


/*****************************************
*   Includes
******************************************/
#include <stdlib.h>

/*****************************************
*   Typedefs
******************************************/

/**
* @brief Typedef utilizado para definir o pseudotipo "String" como um ponteiro de char
*/
typedef char *String;

/**
* @brief Estrutura do Nó da Árvore de Busca Binária, com apelido "MagicTreeNode"
*/
typedef struct MagicTreeNode_{
    String name; /**<Variável que armazena o nome da cidade #name*/
    int minWeather; /**<Variável que armazena a temperatura da cidade #minWeather*/

    struct MagicTreeNode_ *left;  /**<Estrutura que armazena o Nó a esquerda #left*/
    struct MagicTreeNode_ *right; /**<Estrutura que armazena o Nó a direita #right*/
    struct MagicTreeNode_ *father;  /**<Estrutura que armazena o Nó Pai #father*/
} MagicTreeNode;

/**
* @brief Estrutura da Árvore de Busca Binária, com apelido "MagicTree"
*/
typedef struct MagicTree_{
    int size;  /**<Variável que armazena o tamanho da Árvore #size*/
    MagicTreeNode *root;  /**<Variável que armazena o Nó Raiz #root*/
} MagicTree;


void magictree_init(MagicTree **tree);

MagicTreeNode *magicnode_init(String name, int minWeather);

void preorder(MagicTreeNode *node);

void inorder(MagicTreeNode *node);

void posorder(MagicTreeNode *node);

MagicTreeNode *magictree_search(MagicTree *tree, String name);

MagicTreeNode *magicnode_search(MagicTreeNode *node, String name);

MagicTreeNode *tree_max(MagicTreeNode *node);

MagicTreeNode* tree_min(MagicTreeNode *node);

void tree_insert(MagicTree **tree, String name, int minWeather);

void tree_transplant(MagicTree **tree, MagicTreeNode *u, MagicTreeNode *v);

void tree_remove(MagicTree **tree, MagicTreeNode *z);

void node_destroy(MagicTreeNode *node);

void tree_destroy(MagicTree **tree);

#endif