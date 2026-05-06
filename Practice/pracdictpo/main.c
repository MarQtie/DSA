#include <stdio.h>

#define MAX 10
#define PRIMARY_SIZE 5
#define Empty -2
#define Delete -1

typedef struct {
    int elem;
    int next;
} node;

typedef struct {
    node table[MAX];
    int Avail;
} Dictionary;

// Initialize
void initDict(Dictionary *D) {
    D->Avail = PRIMARY_SIZE;
    
    for(int i = 0; i < MAX; i++){
        if(i < PRIMARY_SIZE){
            D->table[i].elem = Empty;
            D->table[i].next = -1;
        }else {
            D->table[i].elem = 0;
            D->table[i].next = i + 1;
        }
    }
    D->table[MAX - 1].next = -1;
}

// Hash
int hash(int x) {
    return x % PRIMARY_SIZE;
}

// Allocate from Avail
int allocSpace(Dictionary *D) {
    int temp = D->Avail;
    if (temp != -1) {
        D->Avail = D->table[temp].next;
    }
    return temp;
}

// Return node to Avail
void freeSpace(Dictionary *D, int index) {
    D->table[index].next = D->Avail;
    D->table[index].elem = Empty;
    D->Avail = index;
}

// Insert
void insert(Dictionary *D, int x) {
    int idx = hash(x);

    if (D->table[idx].elem == Empty) {
        D->table[idx].elem = x;
        D->table[idx].next = -1;
        return;
    }

    int newNode = allocSpace(D);
    if (newNode == -1) return;

    D->table[newNode].elem = x;
    D->table[newNode].next = -1;

    int trav = idx;

    while (D->table[trav].next != -1) {
        trav = D->table[trav].next;
    }

    D->table[trav].next = newNode;
}

// Search
int search(Dictionary D, int x) {
    int idx = hash(x);
    
    int trav = idx;
    
    while(trav != -1){
        if(D.table[trav].elem == x){
            return 1;
        }
        trav = D.table[trav].next;
    }
    return 0;
}

// Delete
void deleteElem(Dictionary *D, int x) {
    int idx = hash(x);

    int trav = idx;
    int prev = -1;

    while (trav != -1) {

        if (D->table[trav].elem == x) {

            if (prev == -1) {

                if (D->table[trav].next == -1) {
                    D->table[trav].elem = Empty;
                } 
                else {
                    int next = D->table[trav].next;

                    D->table[trav].elem = D->table[next].elem;
                    D->table[trav].next = D->table[next].next;

                    freeSpace(D, next);
                }

            } 

            else {
                D->table[prev].next = D->table[trav].next;
                freeSpace(D, trav);
            }

            return;
        }

        prev = trav;
        trav = D->table[trav].next;
    }
}

// Display
void display(Dictionary D) {
    printf("Index | Elem | Next\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d]   | %4d | %4d\n", i, D.table[i].elem, D.table[i].next);
    }
    printf("Avail: %d\n", D.Avail);
}

// Main
int main() {
    Dictionary D;
    initDict(&D);

    insert(&D, 10);
    insert(&D, 15);
    insert(&D, 20);
    insert(&D, 7);
    insert(&D, 12);

    printf("Initial Table:\n");
    display(D);

    printf("\nSearch 15: %s\n", search(D, 15) ? "Found" : "Not Found");

    deleteElem(&D, 15);
    printf("\nAfter deleting 15:\n");
    display(D);

    return 0;
}