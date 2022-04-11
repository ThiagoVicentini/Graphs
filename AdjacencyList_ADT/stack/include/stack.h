#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef int data_type;

typedef struct _node{
    data_type data;
    struct _node *prev;
    struct _node *next;
} NodeObject;

typedef struct _stack{
    struct _node* first;
    struct _node* last;
    size_t size;
} Stack;

NodeObject* newNode(data_type val);

Stack* newStack(void);
void freeStack(Stack** stack);

size_t getSize(Stack* stack);
bool isEmpty(Stack* stack);

void push(Stack* stack, int vertex);
void pop(Stack* stack);
data_type top(Stack* stack);
void showStack(Stack* stack);