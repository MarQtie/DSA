#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#define T_SIZE 10

typedef struct node{
    int key;
    struct node* next;
} Node;

typedef Node* Dictionary;

int hash(int key);
void initTable(Dictionary D[]);
void insertFirst(Dictionary D[], int key);
void insertLast(Dictionary D[], int key);
void deleteFirst(Dictionary D[], int key);
void deleteLast(Dictionary D[], int key);
int memberElem(Dictionary D[], int key);
void displayTable(Dictionary D[]);

int hash(int key){
    return key % T_SIZE;
}

void initTable(Dictionary D[]){
    for(int i = 0; i < T_SIZE; i++){
        D[i] = NULL;
    }
}

void insertFirst(Dictionary D[], int key){
    int index = hash(key);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    newNode->next = D[index];
    D[index] = newNode;
}

void insertLast(Dictionary D[], int key){
    int index = hash(key);

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    if(D[index] == NULL){
        D[index] = newNode;
    } else {
        Node* temp = D[index];

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void deleteFirst(Dictionary D[], int key){
    int index = hash(key);

    if(D[index] == NULL){
        printf("EMPTY!!!\n");
        return;
    }

    Node* temp = D[index];
    D[index] = temp->next;
    free(temp);
}

void deleteLast(Dictionary D[], int key){
    int index = hash(key);

    if(D[index] == NULL){
        printf("EMPTY!!!\n");
        return;
    }

    Node* temp = D[index];

    if (temp->next == NULL) {
        free(temp);
        D[index] = NULL;
        return;
    }

        Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

int memberElem(Dictionary D[], int key) {
    int index = hash(key);

    Node* temp = D[index];

    while (temp != NULL) {
        if (temp->key == key) {
            return 1;
        }
        temp = temp->next;
    }
    
    return 0; 
}

void displayTable(Dictionary D[]) {
    for (int i = 0; i < T_SIZE; i++) {
        printf("%d: ", i);
        Node* temp = D[i];

        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
#endif