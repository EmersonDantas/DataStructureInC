/**
* @file main.c
* @brief Arquivo para testar a Lista Duplamente Encadeada com Sentinela
*
*/

#include <stdio.h>
#include "doublylinkedlist.c"

/**
* @brief Função main
*/
int main() {

    char *name;
    int temp;
   
    // Inicializando Lista Duplamente Encadeada
    node_t *init = init_lista();
    while (scanf("%s %d", name, &temp) != EOF) {
        push_back(name, temp);
    }

    print_list();

    printf("Buscando pela Cidade: Waterloo\n\n");
    findName("Waterloo");

    free(init);

    return 0;
}