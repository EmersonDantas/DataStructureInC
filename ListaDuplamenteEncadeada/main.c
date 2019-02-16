#include <stdio.h>
#include "listaDuplamenteEncadeada.h"

int main(){
    node_t *init = init_lista(0);
    char teste[10] = "timbauba";
    push_back("timbauba",32);
    push_back("Hot",200);
    push_back("cold",-273);
    push_back("Waterloo",0);
    print_list();
    printf("encontrar a cidade cold\n");
    findName("cold");
    popFront();
    printf("nova lista\n");
    print_list();
    return 0;
}