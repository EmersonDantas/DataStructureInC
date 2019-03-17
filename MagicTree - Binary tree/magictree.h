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

/**
* @brief Protótipo para inicializar a Árvore de Busca Binária
* @param tree - Ponteiro para ponteiro da árvore
* @return void
*
*/
void magictree_init(MagicTree **tree);

/**
* @brief Protótipo para inicializar o Nó da Árvore de Busca Binária
* @param name - Ponteiro tipo char do nome da Cidade
* @param minWeather - Temperatura da Cidade
* @return Ponteiro do tipo Nó de Árvore
*
*/
MagicTreeNode *magicnode_init(String name, int minWeather);

/**
* @brief Protótipo percorrer a Árvore de Busca Binária em Pre-Order
* @param node - Ponteiro de um Nó da Árvore
* @return void
*
*/
void preorder(MagicTreeNode *node);

/**
* @brief Protótipo percorrer a Árvore de Busca Binária em In-Order
* @param node - Ponteiro de um Nó da Árvore
* @return void
*
*/
void inorder(MagicTreeNode *node);

/**
* @brief Protótipo percorrer a Árvore de Busca Binária em Pos-Order
* @param node - Ponteiro de um Nó da Árvore
* @return void
*
*/
void posorder(MagicTreeNode *node);

/**
* @brief REVER: Protótipo para procurar a cidade pelo nome
* @param tree - Ponteiro da árvore associada a cidade
* @param name - Nome da Cidade
* @return Ponteiro do tipo Nó
*
*/
MagicTreeNode *magictree_search(MagicTree *tree, String name);

/**
* @brief REVER: Protótipo para procurar a cidade pelo nome
* @param node - Ponteiro da árvore associada a cidade
* @param name - Nome da Cidade
* @return Ponteiro do tipo Nó
*
*/
MagicTreeNode *magicnode_search(MagicTreeNode *node, String name);

/**
* @brief Protótipo para retornar o maior Nó da Árvore
* @param node - Ponteiro do Nó
* @return Ponteiro do maior Nó da Árvore
*
*/
MagicTreeNode *tree_max(MagicTreeNode *node);

/**
* @brief Protótipo para retornar o menor Nó da Árvore
* @param node - Ponteiro do Nó
* @return Ponteiro do menor Nó da Árvore
*
*/
MagicTreeNode* tree_min(MagicTreeNode *node);

/**
* @brief Protótipo para inserir uma cidade na Árvore
* @param tree - Ponteiro para ponteiro da Árvore associada a cidade
* @param name - Ponteiro do nome da cidade
* @param node - Temperatura da cidade
* @return void
*
*/
void tree_insert(MagicTree **tree, String name, int minWeather);

/**
* @brief Protótipo para realizar o transplante na Árvore
* @param tree - Ponteiro para ponteiro da Árvore associada a cidade
* @param u - IRINEU
* @param v - IRINEU
* @return void
*
*/
void tree_transplant(MagicTree **tree, MagicTreeNode *u, MagicTreeNode *v);

/**
* @brief Protótipo para remover uma cidade da Árvore
* @param tree - Ponteiro para ponteiro da Árvore associada a cidade
* @param z - Ponteiro da cidade a remover
* @return void
*
*/
void tree_remove(MagicTree **tree, MagicTreeNode *z);

/**
* @brief Protótipo destruir um nó da Árvore
* @param node - Ponteiro do Nó a destruir
* @return void
*
*/
void node_destroy(MagicTreeNode *node);

/**
* @brief Protótipo para destruir a Árvore
* @param node - Ponteiro da Árvore a destruir
* @return void
*
*/
void tree_destroy(MagicTree **tree);

#endif