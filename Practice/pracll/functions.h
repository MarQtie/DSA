#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STUDENT RECORD */
typedef struct {
    int id;
    char name[50];
    float gwa;
} Student;

/* NODE */
typedef struct node {
    Student data;
    struct node *next;
} Node;

/* LIST */
typedef struct {
    Node *head;
    int count;
} List;


/* initialize */
List* initialize() {
    List *list = (List*) malloc(sizeof(List));

    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->count = 0;

    return list;
}


/* insert first */
void insertFirst(List *list, Student s) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->data = s;
    newNode->next = list->head;
    list->head = newNode;

    list->count++;
}


/* insert last */
void insertLast(List *list, Student s) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    Node *current;

    newNode->data = s;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        current = list->head;

        while (current->next != NULL)
            current = current->next;

        current->next = newNode;
    }

    list->count++;
}


/* display all students */
void display(List *list) {
    Node *current = list->head;

    printf("\nSTUDENT RECORDS:\n");

    while (current != NULL) {
        printf("ID: %d\n", current->data.id);
        printf("Name: %s\n", current->data.name);
        printf("GWA: %.2f\n", current->data.gwa);
        printf("-------------------\n");

        current = current->next;
    }
}


/* locate student by ID */
int locate(List *list, int id) {
    Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data.id == id)
            return index;

        current = current->next;
        index++;
    }

    return -1;
}


/* retrieve student at index */
Student retrieve(List *list, int index) {
    Node *current = list->head;
    int i;
    Student empty = {0, "", 0};

    if (index < 0 || index >= list->count)
        return empty;

    for (i = 0; i < index; i++)
        current = current->next;

    return current->data;
}


/* delete first */
void deleteStart(List *list) {
    Node *temp;

    if (list->head == NULL)
        return;

    temp = list->head;
    list->head = temp->next;

    free(temp);
    list->count--;
}


/* empty list */
void empty(List *list) {
    while (list->head != NULL)
        deleteStart(list);
}

#endif