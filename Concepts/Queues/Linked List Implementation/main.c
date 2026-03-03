#include <stdio.h>
#include "functions.h"

int main() {
    QueueLL q;
    initQueueLL(&q);

    enqueueLL(&q, 'A');
    enqueueLL(&q, 'B');
    enqueueLL(&q, 'C');

    printf("Front: %c\n", peekQueueLL(&q));
    printf("Dequeued: %c\n", dequeueLL(&q));
    printf("Dequeued: %c\n", dequeueLL(&q));

    return 0;
}