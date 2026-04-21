#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initializeSet(Set set);
void insertElem(Set set, int element);
void deleteElem(Set set, int element);
bool find(Set set, int element);
void getUnion(Set A, Set B, Set C);
void getIntersection(Set A, Set B, Set C);
void getDifference(Set A, Set B, Set C);
void displaySet(Set set);

void initializeSet(Set set){
    for (int i = 0; i < ARRAY_SIZE; i++){
        set[i] = false;
    }
}

void insertElem(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[element] = true;
    }
}

void deleteElem(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[element] = false;
    }
}

bool find(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        return set[element];
    }
    return false;
}

void getUnion(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] || B[i];
    }
}

void getIntersection(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] && B[i];
    }
}

void getDifference(Set A, Set B, Set C){
    for(int i = 0; i < ARRAY_SIZE; i++){
        C[i] = A[i] && !B[i];
    }
}

void displaySet(Set set){
    printf("{ ");
    for (int i = 0; i < ARRAY_SIZE; i++){
        if(set[i]){
            printf("%d ", i);
        }
    }
    printf("}\n");
}

#endif