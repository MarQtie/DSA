#include "functions.h"
#include <stdio.h>

int main() {
    int choice;
    Node *head = NULL;

    do {
        printf("\n--- Product Management System ---\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Remove Product\n");
        printf("4. Update Product\n");
        printf("5. Sort Products by ID\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(&head); 
                    break;
            case 2: displayProducts(head); 
                    break;
            case 3: removeProduct(&head); 
                    break;
            case 4: updateProduct(&head); 
                    break;
            case 5: sortProductList(head); 
                    printf("Products sorted successfully.\n");
                    break;
            case 0: printf("Exiting program...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}