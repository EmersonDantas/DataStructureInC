#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "magictree.h"

void magictree_init(MagicTree **tree) {
    (*tree) = (MagicTree*) malloc(sizeof(MagicTree));
    (*tree) -> root = NULL;
    (*tree) -> size = 0;

    return;
}

MagicTreeNode* magicnode_init(String name, int mimWeather) {
    MagicTreeNode *z;
    z = (MagicTreeNode*) malloc(sizeof(MagicTreeNode));
    z -> name = malloc(sizeof(char));

    strcpy(z -> name, name);

    z -> minWeather = mimWeather;
    z -> father = NULL;
    z -> left = NULL;
    z -> right = NULL;
    
    return z;
}

void preorder(MagicTreeNode *node) {
    if (node != NULL) {
        printf("City: %s\nMin.Weather: %d\n\n", node -> name, node -> minWeather);
        preorder(node -> left);
        preorder(node -> right);
    }
}

void inorder(MagicTreeNode *node) {
    if (node != NULL) {
        inorder(node -> left);
        printf("City: %s\nMin.Weather: %d\n\n", node -> name, node -> minWeather);
        inorder(node -> right);
    }
}

void posorder(MagicTreeNode *node) {
    if (node != NULL) {
        posorder(node -> left);
        posorder(node -> right);
        printf("City: %s\nMin.Weather: %d\n\n", node -> name, node -> minWeather);
    }
}

MagicTreeNode* magictree_search(MagicTree *tree, String name) {
    return magicnode_search(tree -> root, name);
}

MagicTreeNode* magicnode_search(MagicTreeNode *node, String name) {
    if ((node == NULL) || strcmp(node -> name, name) == 0) {
        return node;
    }

    if (strcmp(node -> name, name) == 0) {
        return magicnode_search(node -> left , name);

    } else {
        return magicnode_search(node -> right, name);
    }  
}

MagicTreeNode* tree_max(MagicTreeNode *node) {
    if (node == NULL) return 0;

    while(node -> right != NULL) {
        node = node -> right;
    }

    return node;
}

MagicTreeNode* tree_min(MagicTreeNode *node) {
    if (node == NULL) return 0;

    while (node -> left != NULL) {
        node = node -> left;
    }
    return node;
}

void tree_insert(MagicTree **tree, String name, int weather) {
    MagicTreeNode *y;
    MagicTreeNode *x;
    MagicTreeNode *z;

    y = NULL;
    x = (*tree) -> root;

    while (x != NULL) {
        y = x;
        if (x -> minWeather > weather) {
            x = x -> left;
        
        } else {
            x = x -> right;
        }
    }
    z = magicnode_init(name, weather);
    z -> father = y;
    
    if (y == NULL) {
        (*tree) -> root = z;
    
    } else {
        if ((z -> minWeather) < (y -> minWeather)) {
            y -> left = z;
        
        } else {
            y -> right = z;
        }
    }
    (*tree) -> size++;
}

void tree_transplant(MagicTree **tree, MagicTreeNode *u, MagicTreeNode *v) {
    if (u -> father == NULL) {
        (*tree) -> root = v;
    
    } else {

        if (u == (u -> father) -> left) {
            (u -> father) -> left = v;
        
        } else {
            (u -> father) -> right = v;
        }
    }

    if (v!=NULL) {
        v -> father = u -> father;
    }
}

void tree_remove(MagicTree **tree, MagicTreeNode *z) {
    MagicTreeNode* y;

    if (z -> left == NULL) {
        tree_transplant(tree, z, z -> right);
    
    } else {

        if (z -> right == NULL) {
            tree_transplant(tree, z, z -> left);
        
        } else {
            y = tree_min(z -> right);

            if (y -> father != z) {
                tree_transplant(tree, y, y -> right);
                y -> right = z -> right;
                y -> right -> father = y;
            }

            tree_transplant(tree, z, y);
            y -> left = z -> left;
            y -> left -> father = y;
        }
    }
}

void node_destroy(MagicTreeNode *node) {
    if (node != NULL) {
        node_destroy(node->left);
        node_destroy(node->right);
        
        free(node);
    }
}

void tree_destroy(MagicTree ** tree) {
    node_destroy((*tree)->root);
    (*tree)->size = 0;

    free((*tree));
}