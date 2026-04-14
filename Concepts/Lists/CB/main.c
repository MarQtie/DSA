#include <stdio.h>
#include "functions.h"

#include <stdio.h>

int main() {
    VHeap V;
    List L = -1;   // initialize list as empty

    // Initialize virtual heap
    initialize(&V);

    // Insert elements
    insertFirst(&L, &V, 10);
    insertFirst(&L, &V, 5);
    insertLast(&L, &V, 20);
    insertLast(&L, &V, 25);

    printf("List after insertFirst and insertLast:\n");
    display(L, V);

    // Insert at position
    insertPos(&L, &V, 15, 3);
    printf("After insertPos (15 at position 3):\n");
    display(L, V);

    // Insert sorted
    insertSorted(&L, &V, 18);
    printf("After insertSorted (18):\n");
    display(L, V);

    // Delete first occurrence
    deleteElem(&L, &V, 20);
    printf("After deleteElem (20):\n");
    display(L, V);

    // Insert duplicates for testing deleteAllOccurrence
    insertLast(&L, &V, 15);
    insertLast(&L, &V, 15);
    printf("After inserting duplicates (15):\n");
    display(L, V);

    // Delete all occurrences
    deleteAllOccurrence(&L, &V, 15);
    printf("After deleteAllOccurrence (15):\n");
    display(L, V);

    return 0;
}