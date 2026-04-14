#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

typedef int List;

void initialize(VHeap *V) {
    V->avail = 0;
    for (int i = 0; i < MAX - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX - 1].next = -1;
}

int allocSpace(VHeap* V) {
    int ret = -1;

    if (V->avail != -1) {
        ret = V->avail;
        V->avail = V->H[ret].next;
    }

    return ret;
}

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int idx = allocSpace(V);

    if (idx != -1) {
        V->H[idx].elem = elem;
        V->H[idx].next = *L;
        *L = idx;
    }
}

void insertLast(int* L, VHeap* V, int elem) {
    int idx = allocSpace(V);

    if (idx != -1) {
        V->H[idx].elem = elem;
        V->H[idx].next = -1;

        if (*L == -1) {
            *L = idx;
        } else {
            int temp = *L;
            while (V->H[temp].next != -1) {
                temp = V->H[temp].next;
            }
            V->H[temp].next = idx;
        }
    }
}

void insertPos(int* L, VHeap* V, int elem, int pos) {
    int idx = allocSpace(V);
    if (idx == -1) return;

    V->H[idx].elem = elem;

    if (pos == 1) {
        V->H[idx].next = *L;
        *L = idx;
    } else {
        int temp = *L;
        for (int i = 1; i < pos - 1 && temp != -1; i++) {
            temp = V->H[temp].next;
        }

        if (temp != -1) {
            V->H[idx].next = V->H[temp].next;
            V->H[temp].next = idx;
        }
    }
}

void insertSorted(int* L, VHeap* V, int elem) {
    int idx = allocSpace(V);
    if (idx == -1) return;

    V->H[idx].elem = elem;

    int *trav = L;

    while (*trav != -1 && V->H[*trav].elem < elem) {
        trav = &V->H[*trav].next;
    }

    V->H[idx].next = *trav;
    *trav = idx;
}

void deleteElem(int* L, VHeap* V, int elem) {
    int *trav = L;

    while (*trav != -1 && V->H[*trav].elem != elem) {
        trav = &V->H[*trav].next;
    }

    if (*trav != -1) {
        int temp = *trav;
        *trav = V->H[temp].next;
        deallocSpace(V, temp);
    }
}

void deleteAllOccurrence(int* L, VHeap* V, int elem) {
    int *trav = L;

    while (*trav != -1) {
        if (V->H[*trav].elem == elem) {
            int temp = *trav;
            *trav = V->H[temp].next;
            deallocSpace(V, temp);
        } else {
            trav = &V->H[*trav].next;
        }
    }
}

void display(int L, VHeap V) {
    int temp = L;

    while (temp != -1) {
        printf("%d ", V.H[temp].elem);
        temp = V.H[temp].next;
    }
    printf("\n");
}

#include <stdio.h>
#include <string.h>
#define MAX 100
#define NULL_INDEX -1

// Employee structure
typedef struct {
    int id;
    char name[50];
    float salary;
    char department[30];
} Employee;

// Cell (node) in cursor-based system
typedef struct {
    Employee elem;
    int next;
} Cell, HeapSpace[MAX];

// Virtual Heap
typedef struct {
    HeapSpace H;
    int avail;
} VHeap;

// List is just an index
typedef int List;

void promoteByDepartment(VHeap *VH, List head, char dept[], float percentIncrease) {
    int temp = head;
    int count = 0;

    while (temp != NULL_INDEX) {
        if (strcmp(VH->H[temp].elem.department, dept) == 0) {
            count++;

            VH->H[temp].elem.salary += 
                VH->H[temp].elem.salary * (percentIncrease / 100);
        }
        temp = VH->H[temp].next;
    }

    if (count <= 0) {
        printf("\nNo employees found in the department: %s\n", dept);
    } else {
        printf("\nEmployees in %s department promoted by %.2f%%\n", dept, percentIncrease);
    }
}

#endif