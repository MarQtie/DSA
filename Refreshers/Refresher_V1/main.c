#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int productId;
    char productName[100];
    char category[30];
    float price;
    int quantity;
    bool isAvailable;
} Product;

typedef struct Node {
    Product data;
    struct Node *next;
} Node;

void displayProducts(Node *head);
void sortProductList(Node *head);

int main() {
    Node *head = NULL;

    Node *p1 = malloc(sizeof(Node));
    p1->data.productId = 3;
    strcpy(p1->data.productName, "Notebook");
    strcpy(p1->data.category, "School");
    p1->data.price = 45.50;
    p1->data.quantity = 10;
    p1->data.isAvailable = true;
    p1->next = NULL;

    Node *p2 = malloc(sizeof(Node));
    p2->data.productId = 1;
    strcpy(p2->data.productName, "Pen");
    strcpy(p2->data.category, "School");
    p2->data.price = 12.00;
    p2->data.quantity = 0;
    p2->data.isAvailable = false;
    p2->next = NULL;

    Node *p3 = malloc(sizeof(Node));
    p3->data.productId = 2;
    strcpy(p3->data.productName, "USB Flash Drive");
    strcpy(p3->data.category, "Electronics");
    p3->data.price = 499.75;
    p3->data.quantity = 5;
    p3->data.isAvailable = true;
    p3->next = NULL;

    head = p1;
    p1->next = p2;
    p2->next = p3;

    printf("Before sorting:\n");
    displayProducts(head);

    sortProductList(head);

    printf("\nAfter sorting by Product ID:\n");
    displayProducts(head);

    return 0;
}

void displayProducts(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        printf("ID: %d | Name: %s | Price: %.2f | Qty: %d\n",
               temp->data.productId,
               temp->data.productName,
               temp->data.price,
               temp->data.quantity);
        temp = temp->next;
    }
}

void sortProductList(Node *head) {
    if (head == NULL || head->next == NULL) return;

    Node *current, *index;
    Product temp;

    for (current = head; current->next != NULL; current = current->next) {
        for (index = current->next; index != NULL; index = index->next) {
            if (current->data.productId > index->data.productId) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }
}