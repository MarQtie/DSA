#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define ARRAY_SIZE 8

typedef bool Set[ARRAY_SIZE];

void initializeSet(Set set);
void insertElem(Set set, int element);
void deleteElem(Set set, int element);
void getUnion(Set A, Set B, Set C);
void getIntersection(Set A, Set B, Set C);
void getDifference(Set A, Set B, Set C);
void displaySet(Set set);


#endif