#include <stdio.h>
#include "functions.h"

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 'A');
    enqueue(&q, 'B');
    enqueue(&q, 'C');

    printf("Front: %c\n", peekQueue(&q));
    printf("Dequeued: %c\n", dequeue(&q));
    printf("Dequeued: %c\n", dequeue(&q));

    return 0;
}