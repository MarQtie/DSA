#include <stdio.h>
#include "functions.h"

int main() {
    Set A, B, C;

    // Initialize
    initializeSet(&A);
    initializeSet(&B);

    printf("Initial sets:\n");
    printf("A (raw): %u\n", A);
    printf("B (raw): %u\n", B);

    // Insert 
    insertElem(&A, 1);
    insertElem(&A, 3);
    insertElem(&A, 4);
    insertElem(&A, 5);

    insertElem(&B, 3);
    insertElem(&B, 4);
    insertElem(&B, 5);
    insertElem(&B, 6);

    printf("\nAfter insertion:\n");
    printf("A: "); displaySet(A);   // expected: 1, 3, 5
    printf("B: "); displaySet(B);   // expected: 3, 4, 6

    // Find
    printf("\nFind tests:\n");
    printf("Is 3 in A? %s\n", findElem(A, 3) ? "Yes" : "No");
    printf("Is 2 in A? %s\n", findElem(A, 2) ? "Yes" : "No");

    // Delete
    deleteElem(&A, 3);
    printf("\nAfter deleting 3 from A:\n");
    printf("A: "); displaySet(A);   // expected: 1, 5

    // Union
    C = getUnion(A, B);
    printf("\nUnion (A U B): ");
    displaySet(C);

    // Intersection
    C = getIntersection(A, B);
    printf("Intersection (A ∩ B): ");
    displaySet(C);

    // Difference
    C = getDifference(A, B);
    printf("Difference (A - B): ");
    displaySet(C);

    return 0;
}