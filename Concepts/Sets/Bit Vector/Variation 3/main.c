#include "functions.h"

int main() {
    Set A, B, C;

    // initialize sets
    initializeSet(A);
    initializeSet(B);
    initializeSet(C);

    // insert elements into A
    insertElem(A, 1);
    insertElem(A, 3);
    insertElem(A, 5);

    // insert elements into B
    insertElem(B, 3);
    insertElem(B, 4);
    insertElem(B, 5);

    printf("Set A: ");
    displaySet(A);

    printf("Set B: ");
    displaySet(B);

    // union
    getUnion(A, B, C);
    printf("Union (A ∪ B): ");
    displaySet(C);

    // intersection
    getIntersection(A, B, C);
    printf("Intersection (A ∩ B): ");
    displaySet(C);

    // difference
    getDifference(A, B, C);
    printf("Difference (A - B): ");
    displaySet(C);

    // delete element
    deleteElem(A, 3);
    printf("Set A after deleting 3: ");
    displaySet(A);

    // find element
    if(find(A, 5)) {
        printf("5 is in Set A\n");
    } else {
        printf("5 is not in Set A\n");
    }

    return 0;
}