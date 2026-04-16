#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

// Initialize queue
Queue* initialize() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    q->list.count = 0;
    q->front = 1;
    q->rear = 0;

    return q;
}

// Check if full
bool isFull(Queue* q) {
    return q->list.count == MAX;
}

// Check if empty
bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

// Enqueue
void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }

    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

// Dequeue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1; // or handle error differently
    }

    int value = q->list.items[q->front];

    if (q->list.count == 1) {
        // Reset to initial state
        q->front = 1;
        q->rear = 0;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;
    return value;
}

// Get front value
int frontValue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }

    return q->list.items[q->front];
}

// Display queue
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int i = q->front;
    for (int c = 0; c < q->list.count; c++) {
        printf("%d ", q->list.items[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}