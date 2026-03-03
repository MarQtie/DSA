#include "functions.h"
#include <stdio.h>

int main() {
    SA s1, s2;
    initStack(&s1);
    initStack(&s2);

    push(&s1, 'A');
    push(&s1, 'B');
    push(&s1, 'C');

    push(&s2, 'A');
    push(&s2, 'C');
    push(&s2, 'C');

    if (compareStacks(&s1, &s2))
        printf("Stacks are identical\n");
    else
        printf("Stacks are NOT identical\n");

    return 0;
}