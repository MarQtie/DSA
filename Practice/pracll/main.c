#include <stdio.h>
#include "functions.h"

int main() {
    List *students = initialize();

    Student s1 = {101, "John Cruz", 1.75};
    Student s2 = {102, "Maria Santos", 1.50};
    Student s3 = {103, "Kevin Reyes", 2.00};

    insertLast(students, s1);
    insertLast(students, s2);
    insertFirst(students, s3);

    display(students);

    printf("Maria index: %d\n", locate(students, 102));

    Student found = retrieve(students, 1);
    printf("\nRetrieved Student:\n");
    printf("%d %s %.2f\n", found.id, found.name, found.gwa);

    deleteStart(students);

    printf("\nAfter deleting first:\n");
    display(students);

    empty(students);
    free(students);

    return 0;
}