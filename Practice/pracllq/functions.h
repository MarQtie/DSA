#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* STUDENT RECORD */
typedef struct {
    int id;
    char name[50];
    float gwa;
} Student;

/* NODE */
typedef struct node {
    Student data;
    struct node *next;
} Node;

/* QUEUE */
typedef struct {
    Node *front;
    Node *rear;
} Queue;


/* initialize */
Queue* initialize() {
    Queue *q = (Queue*) malloc(sizeof(Queue));

    if (q == NULL)
        return NULL;

    q->front = NULL;
    q->rear = NULL;

    return q;
}


/* linked list queue is never full */
bool isFull(Queue *q) {
    return false;
}


/* empty if front is NULL */
bool isEmpty(Queue *q) {
    return q->front == NULL;
}


/* enqueue student */
void enqueue(Queue *q, Student value) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}


/* dequeue student */
Student dequeue(Queue *q) {
    Student empty = {0, "", 0};
    Node *temp;
    Student value;

    if (isEmpty(q))
        return empty;

    temp = q->front;
    value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    return value;
}


/* view front student */
Student front(Queue *q) {
    Student empty = {0, "", 0};

    if (isEmpty(q))
        return empty;

    return q->front->data;
}


/* display queue */
void display(Queue *q) {
    Node *temp;

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    temp = q->front;

    printf("\nFRONT\n");
    printf("------\n");

    while (temp != NULL) {
        printf("ID: %d | %s | GWA: %.2f\n",
               temp->data.id,
               temp->data.name,
               temp->data.gwa);

        temp = temp->next;
    }

    printf("------\nREAR\n");
}


/* free queue */
void destroy(Queue *q) {
    while (!isEmpty(q))
        dequeue(q);

    free(q);
}

#endif