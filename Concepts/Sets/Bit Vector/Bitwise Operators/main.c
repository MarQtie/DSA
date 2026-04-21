#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayBinary(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main() {
    
unsigned char a = 5;  // 00000101
    unsigned char b = 3;  // 00000011

    printf("a = %u (", a);
    displayBinary(a);
    printf(")\n");

    printf("b = %u (", b);
    displayBinary(b);
    printf(")\n\n");

    // AND, Sets bit to 1 if both bits are 1
    printf("a & b = %u (", a & b);
    displayBinary(a & b);
    printf(")\n");

    // OR
    printf("a | b = %u (", a | b);
    displayBinary(a | b);
    printf(")\n");

    // XOR, Sets bit to 1 if bits are different
    printf("a ^ b = %u (", a ^ b);
    displayBinary(a ^ b);
    printf(")\n");

    // NOT, Flips all bits
    printf("~a = %u (", (unsigned char)(~a));
    displayBinary((unsigned char)(~a));
    printf(")\n");

    // Left Shift, Shifts bits left (multiplies by 2 each shift)
    printf("a << 1 = %u (", (unsigned char)(a << 1));
    displayBinary((unsigned char)(a << 1));
    printf(")\n");

    // Right Shift, Shifts bits right (divides by 2 each shift)
    printf("a >> 1 = %u (", a >> 1);
    displayBinary(a >> 1);
    printf(")\n");

    return 0;
}