#include <stdio.h>
#include "function.h" 

int main() {
    Dictionary D;

    // Initialize
    initDict(&D);

    printf("=== Initial State ===\n");
    displayDict(D);

    // Insert using insertLast
    printf("\n=== InsertLast ===\n");
    insertLast(&D, 20);
    insertLast(&D, 91);
    insertLast(&D, 22);
    insertLast(&D, 72);
    insertLast(&D, 5);
    insertLast(&D, 65);
    insertLast(&D, 6);
    insertLast(&D, 47);

    displayDict(D);

    // Insert using insertFirst
    printf("\n=== InsertFirst ===\n");
    insertFirst(&D, 12);
    insertFirst(&D, 32);

    displayDict(D);

    // Member check
    printf("\n=== Member Check ===\n");
    printf("72: %s\n", memberElem(&D, 72) ? "FOUND" : "NOT FOUND");
    printf("100: %s\n", memberElem(&D, 100) ? "FOUND" : "NOT FOUND");

    // Delete First
    printf("\n=== Delete First (bucket of 22) ===\n");
    deleteFirst(&D, 22);
    displayDict(D);

    // Delete Last
    printf("\n=== Delete Last (bucket of 22) ===\n");
    deleteLast(&D, 22);
    displayDict(D);

    // More deletes
    printf("\n=== Delete First (bucket of 5) ===\n");
    deleteFirst(&D, 5);
    displayDict(D);

    printf("\n=== Delete Last (bucket of 5) ===\n");
    deleteLast(&D, 5);
    displayDict(D);

    return 0;
}