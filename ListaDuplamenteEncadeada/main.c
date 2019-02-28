#include <stdio.h>
#include "listaDuplamenteEncadeada.h"

#define EXIT 5


int main() {

    char *name;
    int temp, choice = 0;
    FILE *op;
    op = fopen("Teste-01.in", "r");


    // Inicializando Lista Duplamente Encadeada
    node_t *init = init_lista(0);
    while (fscanf(op, "%s %d", name, &temp) != EOF) {
        push_back(name, temp);
    }


    while (choice != EXIT) {

        printf("MENU\n\n");
        printf("1. Find City\n");
        printf("2. Print Linked List\n");
        printf("3. Remove first city\n");
        printf("4. Remove last city\n");
        printf("5. Exit\n\n");

        printf("Your Choice: ");
        scanf("%d", &choice);

        
        switch (choice) {

            case 1:

                printf("Find for: ");
                scanf("%s", name);
                findName(name);

                break;

            case 2:
                print_list();
                break;

            case 3:
                popFront();
                break;

            case 4:
                popLast();
                break;

            case 5:
                break;

            default:
                printf("Your choice is invalid!");
                break;

        }
        printf("\n\n\n\n");


    }
    free(init);
    return 0;
    
}