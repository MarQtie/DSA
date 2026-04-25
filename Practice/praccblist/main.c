#include <stdio.h>
#include "function.h"

/* main */
int main() {
    VHeap VH;
    List L = -1;

    initialize(&VH);

    insertFirst(&L, &VH, 30);
    insertFirst(&L, &VH, 20);
    insertLast(&L, &VH, 40);
    insertPos(&L, &VH, 25, 2);

    display(L, VH);

    delete(&L, &VH, 20);
    display(L, VH);

    return 0;
}