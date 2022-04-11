#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

NodeObject* newNode(data_type val){
    NodeObject* node = malloc(sizeof *node);
    node->next = NULL;
    node->prev = NULL;
    node->data = val;

    return node;
}

Stack* newStack(void){
    Stack* stack = malloc(sizeof *stack);
    stack->first = NULL;
    stack->last = NULL;
    stack->size = 0;
    
    return stack;
}

void freeStack(Stack** _stack){
    Stack* stack = *_stack;
    
    NodeObject *node = stack->first;
    while(node != NULL){
        NodeObject *auxiliar = node;
        node = node->next;
        free(auxiliar);
    }

    free(stack);
    *_stack = NULL;
}

size_t getStackSize(Stack* stack){
    return stack->size;
}

bool isStackEmpty(Stack* stack){
    if(getSize(stack) == 0)
        return true;
    return false;
}

void push(Stack* stack, int vertex){

    NodeObject* node = newNode(vertex);
    if(isEmpty(stack)){
        stack->first = node;
        stack->last = node;
    }else{
        stack->last->next = node;
        node->prev = stack->last;
        stack->last = node;
    }
    stack->size++;
}

void pop(Stack* stack){
    if(!isEmpty(stack)){
        NodeObject* node = stack->last;
        if(stack->size == 1){
            stack->first = NULL;
            stack->last = NULL;
        }else{
            stack->last = stack->last->prev;
            stack->last->next = NULL;
        }

        free(node);
        stack->size--;
    }
}

data_type top(Stack* stack){
    return stack->last->data;
}

void showStack(Stack* stack){
    NodeObject* node = stack->first;
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");
}