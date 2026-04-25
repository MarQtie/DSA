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

/* STACK */
typedef struct {
    Node *top;
} Stack;


/* initialize */
Stack* initialize() {
    Stack *s = (Stack*) malloc(sizeof(Stack));

    if (s == NULL)
        return NULL;

    s->top = NULL;
    return s;
}


/* linked list stack is never full */
bool isFull(Stack *s) {
    return false;
}


/* empty if top is NULL */
bool isEmpty(Stack *s) {
    return s->top == NULL;
}


/* push student */
void push(Stack *s, Student value) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL)
        return;

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}


/* pop student */
Student pop(Stack *s) {
    Student empty = {0, "", 0};
    Node *temp;
    Student value;

    if (isEmpty(s))
        return empty;

    temp = s->top;
    value = temp->data;

    s->top = temp->next;
    free(temp);

    return value;
}


/* peek top student */
Student peek(Stack *s) {
    Student empty = {0, "", 0};

    if (isEmpty(s))
        return empty;

    return s->top->data;
}


/* display stack */
void display(Stack *s) {
    Node *temp;

    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    temp = s->top;

    printf("\nTOP\n");
    printf("----\n");

    while (temp != NULL) {
        printf("ID: %d | %s | GWA: %.2f\n",
               temp->data.id,
               temp->data.name,
               temp->data.gwa);

        temp = temp->next;
    }

    printf("----\n");
}


/* free stack */
void destroy(Stack *s) {
    while (!isEmpty(s))
        pop(s);

    free(s);
}


#endif