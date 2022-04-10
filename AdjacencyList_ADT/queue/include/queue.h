#pragma once
#include <stdlib.h>
#include <stdbool.h>

typedef int data_type;

typedef struct _node{
    data_type data;
    struct _node *next;
} NodeObject;

typedef struct _queue{
    struct _node* first;
    struct _node* last;
    size_t size;
} Queue;

NodeObject* newNode(data_type val);

Queue* newQueue(void);
void freeQueue(Queue** queue);

size_t getSize(Queue* queue);
bool isEmpty(Queue* queue);

void enqueue(Queue* queue, int vertex);
void dequeue(Queue* queue);
data_type peek(Queue* queue);