/**
* @file doublylinkedlist.c
* @brief Arquivo contendo as implementações das funções da Lista Duplamente Encadeada com Sentinela
*
*/

/*****************************************
*   Includes
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublylinkedlist.h"


/**
* @brief Função para inicializar o nó da Lista Duplamente Encadeada com Sentinela
* @param name - Ponteiro do nome da Cidade
* @param temp - Temperatura da Cidade
* @return Ponteiro do Nó criado
*
*/
node_t *init_node(char *name, int temp) {
    node_t *my_node = NULL;

    my_node = malloc(sizeof(node_t));
    my_node -> temp = temp;
    my_node -> nome = malloc(sizeof(char));

    strcpy(my_node -> nome,name);

    my_node -> next = NULL;
    my_node -> previous = NULL;

    return my_node;
}

/**
* @brief Função para inicializar a Lista Duplamente Encadeada com Sentinela
* @return Estrutura de Nó da Sentinela
*
*/
node_t *init_lista() {
    sentinela = init_node("",0);   
    return sentinela;
}

/**
* @brief Função para inserir no início da Lista Duplamente Encadeada com Sentinela
* @param name - Ponteiro do nome da Cidade
* @param temp - Temperatura da Cidade
* @return void
*
*/
void push_front(char *name, int temp) { 
    node_t * new_node = init_node(name,temp);

    if (listSize == 0) {
        sentinela -> next = new_node;
        sentinela -> previous = new_node;

    } else {
        new_node -> next = sentinela -> next;
        sentinela -> next -> previous = new_node;
        sentinela -> next = new_node;
        new_node -> previous = sentinela;    
    }
    listSize += 1;
}

/**
* @brief Função para inserir no fim da Lista Duplamente Encadeada com Sentinela
* @param name - Ponteiro do nome da Cidade
* @param temp - Temperatura da Cidade
* @return void
*
*/
void push_back(char *name ,int temp) {
    node_t * new_node = init_node(name,temp);

    if (listSize == 0) {
        sentinela -> next = new_node;
        sentinela -> previous = new_node;
    
    } else {
        sentinela -> previous -> next = new_node;
        new_node -> previous = sentinela -> previous;
        new_node -> next = sentinela;
        sentinela -> previous = new_node;
    }
    listSize++;
}

/**
* @brief Função para remover no fim da Lista Duplamente Encadeada com Sentinela
* @return void
*
*/
void popFront() {   
    node_t * teste = sentinela -> next -> next;
    sentinela -> next = teste;
    sentinela -> next -> previous = sentinela;
    listSize--;

    free(teste);
}

/**
* @brief Função para remover no início da Lista Duplamente Encadeada com Sentinela
* @return void
*
*/
void popLast() {
    node_t * teste = sentinela -> previous -> previous;
    sentinela -> previous = teste;
    sentinela -> previous -> next = sentinela;
    listSize--;
    free(teste);
}

/**
* @brief Função para imprimir a Lista Duplamente Encadeada com Sentinela
* @return void
*
*/
void print_list() {
    node_t *current = sentinela -> next;

    while (current != sentinela) {   
        printf("City: %s\nTemperature: %d\n\n",current -> nome,current -> temp);             
        current = current -> next;
    }
}

/**
* @brief Função para buscar a cidade pelo nome, na Lista Duplamente Encadeada com Sentinela
* @param name - Ponteiro do nome da Cidade
* @return void
*
*/
void findName(char *name) {
    node_t * current = sentinela -> next;

    for (; current != sentinela; current = current -> next) {  
        
        if (strcmp(current -> nome,name) == 0) {
            printf("City: %s\nTemperature: %d\n",current -> nome,current -> temp);
            break;

        } else if (current -> next == sentinela) {
            printf("%s City was not found!", name);
        }
    }
}