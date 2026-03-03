#include <stdio.h>
#include "functions.h"

int main() {
    SL stack1, stack2;
    initStack(&stack1);
    initStack(&stack2);

    push(&stack1, 'A');
    push(&stack1, 'B');
    push(&stack1, 'C');

    push(&stack2, 'A');
    push(&stack2, 'B');
    push(&stack2, 'C');

    if (areIdenticalStacks(stack1, stack2))
        printf("Stacks are identical\n");
    else
        printf("Stacks are NOT identical\n");

    pop(&stack2);
    push(&stack2, 'D');

    if (areIdenticalStacks(stack1, stack2))
        printf("Stacks are identical\n");
    else
        printf("Stacks are NOT identical\n");

    return 0;
}