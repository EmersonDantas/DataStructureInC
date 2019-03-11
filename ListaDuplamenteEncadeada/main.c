#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {

    char *name;
    int temp;
   
    // Inicializando Lista Duplamente Encadeada
    node_t *init = init_lista(0);
    while (fscanf(op, "%s %d", name, &temp) != EOF) {
        push_back(name, temp);
    }

    print_list();

    free(init);

    return 0;
}