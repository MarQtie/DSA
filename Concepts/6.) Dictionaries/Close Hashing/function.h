#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY ""
#define Delete -1

typedef struct {
    int elem;
    int next;
} Node;

typedef struct {
    Node table[MAX];
    int Avail;
} Dictionary;

int hash(int key);
void initDict(Dictionary *D);
int allocSpace(Dictionary *D);
void freeSpace(Dictionary *D, int index);
void insertFirst(Dictionary D[], int key);
void insertLast(Dictionary D[], int key);
void deleteFirst(Dictionary D[], int key);
void deleteLast(Dictionary D[], int key);
int memberElem(Dictionary D[], int key);
void displayDict(Dictionary D);

int hash(int key){
    return key % MAX;
}

void initDict(Dictionary *D) {
    for (int i = 0; i < MAX; i++) {
        D->table[i].elem = -1;
        D->table[i].next = -1;
    }

    D->Avail = MAX - 1;

    for (int i = MAX - 1; i >= 0; i--) {
        D->table[i].next = i - 1;
    }
}

int allocSpace(Dictionary *D) {
    if (D->Avail == -1) return -1;

    int temp = D->Avail;
    D->Avail = D->table[temp].next;

    return temp;
}

void freeSpace(Dictionary *D, int index) {
    D->table[index].next = D->Avail;
    D->Avail = index;
}

void insertFirst(Dictionary *D, int key) {
    int index = hash(key);
    int newIndex = allocSpace(D);

    if (newIndex == -1) {
        printf("Dictionary FULL\n");
        return;
    }

    D->table[newIndex].elem = key;
    D->table[newIndex].next = D->table[index].next;

    D->table[index].next = newIndex;
}

void insertLast(Dictionary *D, int key) {
    int index = hash(key);
    int newIndex = allocSpace(D);

    if (newIndex == -1) {
        printf("Dictionary FULL\n");
        return;
    }

    D->table[newIndex].elem = key;
    D->table[newIndex].next = -1;

    int temp = index;

    while (D->table[temp].next != -1) {
        temp = D->table[temp].next;
    }

    D->table[temp].next = newIndex;
}

void deleteFirst(Dictionary *D, int key) {
    int index = hash(key);

    int first = D->table[index].next;

    if (first == -1) {
        printf("EMPTY\n");
        return;
    }

    D->table[index].next = D->table[first].next;

    freeSpace(D, first);
}

void deleteLast(Dictionary *D, int key) {
    int index = hash(key);

    int temp = index;
    int prev = -1;

    if (D->table[temp].next == -1) {
        printf("EMPTY\n");
        return;
    }

    while (D->table[temp].next != -1) {
        prev = temp;
        temp = D->table[temp].next;
    }

    if (prev != -1) {
        D->table[prev].next = -1;
    }

    freeSpace(D, temp);
}

int memberElem(Dictionary *D, int key) {
    int index = hash(key);

    int temp = D->table[index].next;

    while (temp != -1) {
        if (D->table[temp].elem == key) {
            return 1;
        }
        temp = D->table[temp].next;
    }

    return 0;
}

void displayDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        printf("%d: ", i);

        int temp = D.table[i].next;

        while (temp != -1) {
            printf("%d -> ", D.table[temp].elem);
            temp = D.table[temp].next;
        }

        printf("NULL\n");
    }

    printf("Avail = %d\n", D.Avail);
}

#endif