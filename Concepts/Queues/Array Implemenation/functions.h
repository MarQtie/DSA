#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#define MAX 20

typedef struct {
    char arr[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, char value) {
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue Overflow\n");
        return;
    }

    if (q->front == -1) {  // first element
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }

    q->arr[q->rear] = value;
}

char dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue Underflow\n");
        return '\0';
    }

    char value = q->arr[q->front];

    if (q->front == q->rear) {  // only one element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    return value;
}

char peekQueue(Queue *q) {
    if (q->front == -1) return '\0';
    return q->arr[q->front];
}

#endif