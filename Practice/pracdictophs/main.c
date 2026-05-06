#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int elem;
    struct node *next;
} *List;

typedef List Dictionary[MAX];

// Hash function
int hash(int x) {
    return ((x * x) / 10) % 10;
}
    
// Initialize dictionary
void initDict(Dictionary D) {
    for(int i = 0; i < MAX; i++){
        D[i] = NULL;
    }
}

// Insert
void insert(Dictionary D, int x) {
    // Hash Function
    int idx = hash(x);
    
    // Populate New Node
    List newNode = (List)malloc(sizeof(struct node));
    newNode->elem = x;
    newNode->next = NULL;
    
    // Set *Trav to D[index]
    List *trav = &D[idx];
    
    // Traverse while:
    // 1.) Trav is not null
    // 2.) Trav->elem is less than x
    while(*trav != NULL && (*trav)->elem < x){
        trav = &(*trav)->next;
    }
    
    // Checker for when there is a duped elem
    if(*trav != NULL && (*trav)->elem == x){
        return;
    }
    
    newNode->next = *trav;
    *trav = newNode;
}

// Delete element
void deleteElem(Dictionary D, int x) {
    // Hash Function
    int idx = hash(x);
    
    // Set *Trav to D[index]
    List *trav = &D[idx];
    
    // Traverse while:
    // 1.) Trav is not null
    // 2.) Trav->elem is less than x
    while(*trav != NULL && (*trav)->elem < x){
        trav = &(*trav)->next;
    }
    
    // Checker for whether the element is actually found 
    if(*trav != NULL && (*trav)->elem == x){
        List temp = *trav;
        *trav = temp->next;
        free(temp);
    }
}

// Search element
int search(Dictionary D, int x) {
    // Hash Function
    int idx = hash(x);
    
    // Set temp to D[index]
    List temp = D[idx];
    
    while (temp != NULL){
        // Condition for when temp finds the intended elem
        if(temp->elem == x){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Display dictionary
void display(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        printf("[%d]: ", i);
        List curr = D[i];
        while (curr != NULL) {
            printf("%d -> ", curr->elem);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// Main
int main() {
    Dictionary D;
    initDict(D);

    insert(D, 15);
    insert(D, 25);
    insert(D, 35);
    insert(D, 5);
    insert(D, 12);
    insert(D, 25); // duplicate (ignored)

    printf("Dictionary:\n");
    display(D);

    printf("\nSearch 25: %s\n", search(D, 25) ? "Found" : "Not Found");
    printf("\nSearch 55: %s\n", search(D, 55) ? "Found" : "Not Found");

    deleteElem(D, 5);
    printf("\nAfter deleting 5:\n");
    display(D);

    deleteElem(D, 60);
    printf("\nAfter deleting 60:\n");
    display(D);

    return 0;
}