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

    print_list();

    free(init);

    return 0;
}