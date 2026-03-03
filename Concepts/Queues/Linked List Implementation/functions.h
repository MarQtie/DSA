#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *link;
} *NodePtr;

typedef struct {
    NodePtr front;
    NodePtr rear;
} QueueLL;

void initQueueLL(QueueLL *q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueueLL(QueueLL *q, char value) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->elem = value;
    newNode->link = NULL;

    if (q->rear == NULL) {  // first element
        q->front = q->rear = newNode;
        return;
    }

    q->rear->link = newNode;
    q->rear = newNode;
}

char dequeueLL(QueueLL *q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return '\0';
    }

    NodePtr temp = q->front;
    char value = temp->elem;
    q->front = q->front->link;

    if (q->front == NULL) {  // queue is now empty
        q->rear = NULL;
    }

    free(temp);
    return value;
}

char peekQueueLL(QueueLL *q) {
    if (q->front == NULL) return '\0';
    return q->front->elem;
}

#endif