#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define MAX 4

/* CELL */
typedef struct {
    int elem;
    int next;
} Cell;

/* VIRTUAL HEAP */
typedef struct {
    Cell HeapSpace[MAX];
    int avail;
} VHeap;

/* LIST HEAD INDEX */
typedef int List;


/* initialize */
void initialize(VHeap *V) {
    int i;

    V->avail = 0;

    for (i = 0; i < MAX - 1; i++) {
        V->HeapSpace[i].next = i + 1;
    }

    V->HeapSpace[MAX - 1].next = -1;
}


/* allocate space */
int allocSpace(VHeap *V) {
    int index;

    if (V->avail == -1)
        return -1;

    index = V->avail;
    V->avail = V->HeapSpace[index].next;

    return index;
}


/* deallocate space */
void deallocSpace(VHeap *V, int index) {
    V->HeapSpace[index].next = V->avail;
    V->avail = index;
}


/* insert first */
void insertFirst(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);

    if (newCell == -1)
        return;

    V->HeapSpace[newCell].elem = elem;
    V->HeapSpace[newCell].next = *L;
    *L = newCell;
}


/* insert last */
void insertLast(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    int temp;

    if (newCell == -1)
        return;

    V->HeapSpace[newCell].elem = elem;
    V->HeapSpace[newCell].next = -1;

    if (*L == -1) {
        *L = newCell;
        return;
    }

    temp = *L;

    while (V->HeapSpace[temp].next != -1) {
        temp = V->HeapSpace[temp].next;
    }

    V->HeapSpace[temp].next = newCell;
}


/* insert at position (1-based position) */
void insertPos(List *L, VHeap *V, int elem, int pos) {
    int newCell = allocSpace(V);
    int temp, i;

    if (newCell == -1)
        return;

    V->HeapSpace[newCell].elem = elem;

    if (pos <= 1 || *L == -1) {
        V->HeapSpace[newCell].next = *L;
        *L = newCell;
        return;
    }

    temp = *L;

    for (i = 1; i < pos - 1 && V->HeapSpace[temp].next != -1; i++) {
        temp = V->HeapSpace[temp].next;
    }

    V->HeapSpace[newCell].next = V->HeapSpace[temp].next;
    V->HeapSpace[temp].next = newCell;
}


/* insert sorted ascending */
void insertSorted(List *L, VHeap *V, int elem) {
    int newCell = allocSpace(V);
    int temp;

    if (newCell == -1)
        return;

    V->HeapSpace[newCell].elem = elem;

    if (*L == -1 || elem < V->HeapSpace[*L].elem) {
        V->HeapSpace[newCell].next = *L;
        *L = newCell;
        return;
    }

    temp = *L;

    while (V->HeapSpace[temp].next != -1 &&
           V->HeapSpace[V->HeapSpace[temp].next].elem < elem) {
        temp = V->HeapSpace[temp].next;
    }

    V->HeapSpace[newCell].next = V->HeapSpace[temp].next;
    V->HeapSpace[temp].next = newCell;
}


/* delete first occurrence */
void delete(List *L, VHeap *V, int elem) {
    int temp, del;

    if (*L == -1)
        return;

    if (V->HeapSpace[*L].elem == elem) {
        del = *L;
        *L = V->HeapSpace[del].next;
        deallocSpace(V, del);
        return;
    }

    temp = *L;

    while (V->HeapSpace[temp].next != -1 &&
           V->HeapSpace[V->HeapSpace[temp].next].elem != elem) {
        temp = V->HeapSpace[temp].next;
    }

    if (V->HeapSpace[temp].next != -1) {
        del = V->HeapSpace[temp].next;
        V->HeapSpace[temp].next = V->HeapSpace[del].next;
        deallocSpace(V, del);
    }
}


/* delete all occurrences */
void deleteAllOccurrence(List *L, VHeap *V, int elem) {
    int del;

    while (*L != -1 && V->HeapSpace[*L].elem == elem) {
        del = *L;
        *L = V->HeapSpace[del].next;
        deallocSpace(V, del);
    }

    if (*L == -1)
        return;

    int temp = *L;

    while (V->HeapSpace[temp].next != -1) {
        if (V->HeapSpace[V->HeapSpace[temp].next].elem == elem) {
            del = V->HeapSpace[temp].next;
            V->HeapSpace[temp].next = V->HeapSpace[del].next;
            deallocSpace(V, del);
        } else {
            temp = V->HeapSpace[temp].next;
        }
    }
}


/* display */
void display(List L, VHeap V) {
    int temp = L;

    printf("List: ");

    while (temp != -1) {
        printf("%d ", V.HeapSpace[temp].elem);
        temp = V.HeapSpace[temp].next;
    }

    printf("\n");
}



#endif