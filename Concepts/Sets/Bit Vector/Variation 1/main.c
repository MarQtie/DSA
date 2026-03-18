#include <stdio.h>
#include "functions.h"

int main() {
    unsigned char A, B, C;

    // Initialize
    initialize(&A);
    initialize(&B);

    printf("Initial sets:\n");
    printf("A (raw): %u\n", A);
    printf("B (raw): %u\n", B);

    // Insert 
    insert(&A, 1);
    insert(&A, 3);
    insert(&A, 5);

    insert(&B, 3);
    insert(&B, 4);
    insert(&B, 6);

    printf("\nAfter insertion:\n");
    printf("A: "); display(A);   // expected: 1, 3, 5
    printf("B: "); display(B);   // expected: 3, 4, 6

    // Find
    printf("\nFind tests:\n");
    printf("Is 3 in A? %s\n", find(A, 3) ? "Yes" : "No");
    printf("Is 2 in A? %s\n", find(A, 2) ? "Yes" : "No");

    // Delete
    delete(&A, 3);
    printf("\nAfter deleting 3 from A:\n");
    printf("A: "); display(A);   // expected: 1, 5

    // Union
    C = getUnion(A, B);
    printf("\nUnion (A U B): ");
    display(C);

    // Intersection
    C = getIntersection(A, B);
    printf("Intersection (A ∩ B): ");
    display(C);

    // Difference
    C = getDifference(A, B);
    printf("Difference (A - B): ");
    display(C);

    return 0;
}