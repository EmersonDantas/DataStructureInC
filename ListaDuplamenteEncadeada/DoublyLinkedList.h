#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definir o tipo string como char
typedef char *String;

// tamanho da lista
int tamanho;

// no 
typedef struct node {
    int temp;
    String nome;
    struct node * next;
    struct node * previous;
}node_t;

// sentinela
node_t* sentinela;

// inicializa a lista
node_t* init_node(char * name,int temp);

// inicializar lista
node_t* init_lista();

// add no inicio da lista
void push_front(char * name,int temp);

// add no fim da lista
void push_back(char * name,int temp);

// remove no inicio
void popFront();

// remove no fim
void popLast();

// imprimir lista
void print_list();

// busca pelo nome
void findName(char * name);

#endif