#include <stdio.h>
#include "DoublyLinkedList.c"

int main() {

    char *name;
    int temp;
   
    // Inicializando Lista Duplamente Encadeada
    node_t *init = init_lista();
    while (scanf("%s %d", name, &temp) != EOF) {
        push_back(name, temp);
    }

    printf("Buscando pela Cidade: Waterloo\n\n");
    findName("Waterloo");

    free(init);

    return 0;
}