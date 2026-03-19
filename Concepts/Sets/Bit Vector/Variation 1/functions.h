#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void initializeSet(unsigned char *set);
void insertElem(unsigned char *set, int element);
void deleteElem(unsigned char *set, int element);
bool findElem(unsigned char set, int element);
unsigned char getUnion(unsigned char A, unsigned char B);
unsigned char getIntersection(unsigned char A, unsigned char B);
unsigned char getDifference(unsigned char A, unsigned char B);
void displaySet(unsigned char set);

void initializeSet(unsigned char *set){
    *set = 0;
}

void insertElem(unsigned char *set, int element){
    if(element < sizeof(char) * 8){
        char unsigned mv = 1 << element;
        *set |= mv;
    } else {
        printf("Element Out of Bounds!\n");
    }
}

void deleteElem(unsigned char *set, int element){
    if(element < sizeof(char) * 8){
        char unsigned mv = 1 << element;
        *set &= ~mv;
    } else {
        printf("Element Out of Bounds!\n");
    }
}

bool findElem(unsigned char set, int element){
    unsigned char mv = 1 << element;
    return set & mv != 0;
}

unsigned char getUnion(unsigned char A, unsigned char B){
    unsigned char unionSet = A | B;
    return unionSet;
}

unsigned char getIntersection(unsigned char A, unsigned char B){
    unsigned char interSet = A & B;
    return interSet;
}

unsigned char getDifference(unsigned char A, unsigned char B){
    unsigned char diffSet = A & ~B;
    return diffSet;
}

void displaySet(unsigned char set) {
    int first = 1;

    for (int i = 0; i < 8; i++) {
        if (set & (1 << i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
}

#endif