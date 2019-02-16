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
node_t* init_node(char * name,int temp){
    node_t *my_node = NULL;
    my_node = malloc(sizeof(node_t));
    my_node -> temp = temp;
    my_node -> nome = malloc(sizeof(char));
    strcpy(my_node -> nome,name);
    my_node -> next = NULL;
    my_node -> previous = NULL;
    return my_node;
}

// inicializar lista
node_t* init_lista(){
    sentinela = init_node("",0);   
    return sentinela;
}

// add no inicio da lista
void push_front(char * name,int temp){
    node_t * new_node = init_node(name,temp);
    if(tamanho == 0){
        sentinela -> next = new_node;
        sentinela -> previous = new_node;
    }else{
        new_node -> next = sentinela -> next;
        sentinela -> next -> previous = new_node;
        sentinela -> next = new_node;
        new_node -> previous = sentinela;    
    }
    tamanho += 1;
}

// add no fim da lista
void push_back(char * name,int temp){
    node_t * new_node = init_node(name,temp);
    if(tamanho == 0){
        sentinela -> next = new_node;
        sentinela -> previous = new_node;
    }else{
        sentinela -> previous -> next = new_node;
        new_node -> previous = sentinela -> previous;
        new_node -> next = sentinela;
        sentinela -> previous = new_node;
    }
    tamanho++;
}

// remove no inicio
void popFront(){   
    sentinela -> next = sentinela -> next -> next;
    sentinela -> next -> previous = sentinela;    
    tamanho--;
}

// remove no fim
void popLast(){
    sentinela -> previous = sentinela -> previous -> previous;
    sentinela -> previous -> next = sentinela;
    tamanho--;
}

// imprimir lista
void print_list(){
    node_t *current = sentinela -> next;
    while(current != sentinela){   
        printf("city: %s\ntemperature: %d\n",current -> nome,current -> temp);             
        current = current -> next;
    }
}

// busca pelo nome
void findName(char * name){
    node_t * current = sentinela -> next;
    for(;current != sentinela;current = current -> next){        
        if(strcmp(current -> nome,name) == 0){
            printf("city: %s\ntemperature: %d\n",current -> nome,current -> temp);
            break;
        }else if(current -> next == sentinela){
            printf("cidade não foi encontrada\n");
        }
    }
}