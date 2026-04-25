#include "functions.h"
#include <stdio.h>

/* MAIN */
int main() {
    Stack *records = initialize();

    Student s1 = {101, "John Cruz", 1.75};
    Student s2 = {102, "Maria Santos", 1.50};
    Student s3 = {103, "Kevin Reyes", 2.00};

    push(records, s1);
    push(records, s2);
    push(records, s3);

    display(records);

    Student topStudent = peek(records);
    printf("\nPeek:\n%d %s %.2f\n",
           topStudent.id,
           topStudent.name,
           topStudent.gwa);

    Student removed = pop(records);
    printf("\nPopped:\n%d %s %.2f\n",
           removed.id,
           removed.name,
           removed.gwa);

    printf("\nAfter Pop:\n");
    display(records);

    destroy(records);

    return 0;
}