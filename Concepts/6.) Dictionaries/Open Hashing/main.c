#include <stdio.h>
#include "function.h"

int main() {
    Dictionary D[T_SIZE];

    // Initialize table
    initTable(D);

    printf("=== Inserting Elements (insertLast) ===\n");
    insertLast(D, 20);
    insertLast(D, 91);
    insertLast(D, 22);
    insertLast(D, 72);
    insertLast(D, 5);
    insertLast(D, 65);
    insertLast(D, 6);
    insertLast(D, 47);

    displayTable(D);

    printf("\n=== Inserting Elements (insertFirst) ===\n");
    insertFirst(D, 12);   // same bucket as 2
    insertFirst(D, 32);   // same bucket as 2

    displayTable(D);

    printf("\n=== Member Check ===\n");
    if (memberElem(D, 72)) {
        printf("72 is FOUND\n");
    } else {
        printf("72 is NOT FOUND\n");
    }

    if (memberElem(D, 100)) {
        printf("100 is FOUND\n");
    } else {
        printf("100 is NOT FOUND\n");
    }

    printf("\n=== Delete First (bucket of key 22) ===\n");
    deleteFirst(D, 22);
    displayTable(D);

    printf("\n=== Delete Last (bucket of key 22) ===\n");
    deleteLast(D, 22);
    displayTable(D);

    printf("\n=== Delete First (bucket of key 5) ===\n");
    deleteFirst(D, 5);
    displayTable(D);

    printf("\n=== Delete Last (bucket of key 5) ===\n");
    deleteLast(D, 5);
    displayTable(D);

    return 0;
}