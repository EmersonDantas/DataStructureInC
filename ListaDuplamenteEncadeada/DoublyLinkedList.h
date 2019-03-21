/**
* @file doublylinkedlist.h
* @brief Arquivo de cabeçalho para a Lista Duplamente Encadeada com Sentinela
*
*/

/*****************************************
*   Defines
******************************************/
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

/*****************************************
*   Includes
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************
*   Typedefs
******************************************/


typedef char *String;

/**
* @brief Variável para armazenar o tamanho da lista
*/
int listSize;

/**
* @brief Estrutura do Nó da Lista Duplamente Encadeada com Sentinela,
com apelido "node_t"
*/
typedef struct node {
    int temp; /**<Variável que armazena a temperatura da cidade #temp*/
    String nome; /**<Variável que armazena o nome da cidade #nome*/
    struct node *next; /**<Estrutura que armazena o próximo Nó #next*/
    struct node *previous; /**<Estrutura que armazena o Nó anterior #previous*/
} node_t;

/**
* @brief Estrutura de Nó da Sentinela
*/
node_t *sentinela;

/**
* @brief Protótipo para inicializar o nó da Lista Duplamente Encadeada com Sentinela
* @param name - Ponteiro do nome da Cidade
* @param temp - Temperatura da Cidade
* @return Ponteiro do tipo Nó
*
*/
node_t *init_node(char *name, int temp);

/**
* @brief Protótipo inicializar a Lista Duplamente Encadeada com Sentinela
* @return Ponteiro do tipo Nó da Lista
*
*/
node_t *init_lista();

void push_front(char *name, int temp);

void push_back(char *name, int temp);

void popFront();

void popLast();

void print_list();

void findName(char *name);

#endif