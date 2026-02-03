#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

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
void addProduct(Node **head);
void removeProduct(Node **head);
void updateProduct(Node **head);
void sortProductList(Node *head);

#endif