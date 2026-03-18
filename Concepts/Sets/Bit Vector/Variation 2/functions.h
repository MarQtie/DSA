#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int field : 8;
} Set;

void initialize(Set Set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void Union(Set A, Set B);
void Intersection(Set A, Set B);
void Difference(Set A, Set B);
void display(Set set);


#endif