#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(){
    Stack* stack = newStack();

    push(stack, 2);
    push(stack, 5);
    push(stack, 1);
    push(stack, 7);
    showStack(stack);
    
    while(!isStackEmpty(stack)){
        printf("%d\n", top(stack));
        pop(stack);
    }

    freeStack(&stack);
    
    return 0;
}