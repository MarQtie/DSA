#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct {
    char arr[MAX];
    int top;
} SA;

void initStack(SA *s);
void push(SA *s, char value);
char pop(SA *s);
char peek(SA *s);
int compareStacks(SA *s1, SA *s2);

void initStack(SA *s) {
    s->top = -1;
}

void push(SA *s, char value) {

    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    s->top++;
    s->arr[s->top] = value;
}

char pop(SA *s) {

    if (s->top == -1) {
        printf("Stack Underflow\n");
        return '\0';   // null character
    }

    char value = s->arr[s->top];
    s->top--;

    return value;
}

char peek(SA *s) {

    if (s->top == -1) {
        return '\0';
    }

    return s->arr[s->top];
}

int compareStacks(SA *s1, SA *s2) {

    // First check length
    if (s1->top != s2->top) {
        return 0;
    }

    // Compare elements from bottom to top
    for (int i = 0; i <= s1->top; i++) {
        if (s1->arr[i] != s2->arr[i]) {
            return 0;
        }
    }

    return 1;   // All elements match
}

#endif