#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

#include "functions.h"

void addProduct(Node **head) {
    Node *newNode = malloc(sizeof(Node));

    if (!newNode) return;

    printf("Enter Product ID: ");
    scanf("%d", &newNode->data.productId);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", newNode->data.productName);

    printf("Enter Category: ");
    scanf(" %[^\n]", newNode->data.category);

    printf("Enter Price: ");
    scanf("%f", &newNode->data.price);

    printf("Enter Quantity: ");
    scanf("%d", &newNode->data.quantity);

    newNode->data.isAvailable = (newNode->data.quantity > 0);

    newNode->next = *head;
    *head = newNode;
}

void displayProducts(Node *head) {
    if (head == NULL) {
        printf("No products available.\n");
        return;
    }

    Node *temp = head;

    printf("\n--- Product List ---\n");
    while (temp != NULL) {
        printf("ID: %d\n", temp->data.productId);
        printf("Name: %s\n", temp->data.productName);
        printf("Category: %s\n", temp->data.category);
        printf("Price: %.2f\n", temp->data.price);
        printf("Quantity: %d\n", temp->data.quantity);
        printf("Available: %s\n\n",
               temp->data.isAvailable ? "Yes" : "No");
        temp = temp->next;
    }
}

void removeProduct(Node **head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    int id;
    printf("Enter Product ID to remove: ");
    scanf("%d", &id);

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->data.productId != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found.\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Product removed successfully.\n");
}

void updateProduct(Node **head) {
    if (head == NULL) {
        printf("No products to update.\n");
        return;
    }

    int id;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);

    Node *temp = head;

    while (temp != NULL && temp->data.productId != id) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Product not found.\n");
        return;
    }

    printf("Enter new Product Name: ");
    scanf(" %[^\n]", temp->data.productName);

    printf("Enter new Category: ");
    scanf(" %[^\n]", temp->data.category);

    printf("Enter new Price: ");
    scanf("%f", &temp->data.price);

    printf("Enter new Quantity: ");
    scanf("%d", &temp->data.quantity);

    temp->data.isAvailable = (temp->data.quantity > 0);

    printf("Product updated successfully.\n");
}

void sortProductList(Node *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    Node *current;
    Node *index;
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
