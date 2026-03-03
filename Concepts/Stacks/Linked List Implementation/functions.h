#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char elem;
    struct Node *link;
} *SL;

void initStack(SL *top);
void push(SL *top, char value);
char pop(SL *top);
char peek(SL top);
int areIdenticalStacks(SL s1, SL s2);

void initStack(SL *top) {
    *top = NULL;
}

void push(SL *top, char value) {
    SL newNode = (SL)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newNode->elem = value;
    newNode->link = *top;
    *top = newNode;
}

char pop(SL *top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }

    SL temp = *top;
    char value = temp->elem;
    *top = temp->link;
    free(temp);

    return value;
}

char peek(SL top) {
    if (top == NULL) {
        return '\0';
    }
    return top->elem;
}

int areIdenticalStacks(SL s1, SL s2) {

    // Traverse both stacks together
    while (s1 != NULL && s2 != NULL) {
        if (s1->elem != s2->elem) {
            return 0;  // mismatch found
        }
        s1 = s1->link;
        s2 = s2->link;
    }

    // If both reached NULL, lengths are equal
    return (s1 == NULL && s2 == NULL) ? 1 : 0;
}

#endif