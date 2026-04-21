#define FUNCTIONS_H
#ifndef FUNCTIONS_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void displaySet(unsigned char set) {
    int first = 1;

    for (int i = 0; i < 8; i++) {
        if (set & (1 << i)) {
            if (!first) {
                printf(", ");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("\n");
}

#endif