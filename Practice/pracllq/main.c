#include "functions.h"
#include <stdio.h>
/* MAIN */
int main() {
    Queue *line = initialize();

    Student s1 = {101, "John Cruz", 1.75};
    Student s2 = {102, "Maria Santos", 1.50};
    Student s3 = {103, "Kevin Reyes", 2.00};

    enqueue(line, s1);
    enqueue(line, s2);
    enqueue(line, s3);

    display(line);

    Student first = front(line);
    printf("\nFront Student:\n");
    printf("%d %s %.2f\n",
           first.id,
           first.name,
           first.gwa);

    Student served = dequeue(line);
    printf("\nDequeued:\n");
    printf("%d %s %.2f\n",
           served.id,
           served.name,
           served.gwa);

    printf("\nAfter Dequeue:\n");
    display(line);

    destroy(line);

    return 0;
}