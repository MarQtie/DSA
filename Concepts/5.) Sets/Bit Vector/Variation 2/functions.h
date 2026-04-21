#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 8

typedef struct {
    unsigned int field : SIZE;
} Set;

void initializeSet(Set *set);
void insertElem(Set *set, int element);
void deleteElem(Set *set, int element);
bool findElem(Set set, int element);
Set getUnion(Set A, Set B);
Set getIntersection(Set A, Set B);
Set getDifference(Set A, Set B);
void displaySet(Set set);

void initializeSet(Set *set){
    set->field = 0;
}

void insertElem(Set *set, int element){
    if(element < SIZE) {
        unsigned int mv = 1 << element;
        set->field |= mv;
    }else {
        printf("Element Out of Bounds!\n");
    }
}

void deleteElem(Set *set, int element){
    if(element >= 0 && element < 8) {
        unsigned int mv = 1 << element;
        set->field &= ~mv;
    }else {
        printf("Element Out of Bounds!\n");
    }
}

bool findElem(Set set, int element){
    unsigned int mv = 1 << element;
    return (set.field & mv) ? true : false;
}

Set getUnion(Set A, Set B){
    Set C;
    C.field = A.field | B.field;
    return C;
}

Set getIntersection(Set A, Set B){
    Set C;
    C.field = A.field & B.field;
    return C;
}

Set getDifference(Set A, Set B){
    Set C;
    C.field = A.field & ~B.field;
    return C;
}

void displaySet(Set set){
    int first = 1;

    for (int i = 0; i < 8; i++){
        if(set.field & (1 << i)){
            if(!first){
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
}

#endif