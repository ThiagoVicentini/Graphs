#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

NodeObject* newNode(data_type val){
    NodeObject* node = malloc(sizeof *node);
    node->next = NULL;
    node->data = val;

    return node;
}

Queue* newQueue(void){
    Queue* queue = malloc(sizeof *queue);
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    
    return queue;
}

void freeQueue(Queue** _queue){
    Queue* queue = *_queue;
    
    NodeObject *node = queue->first;
    while(node != NULL){
        NodeObject *auxiliar = node;
        node = node->next;
        free(auxiliar);
    }

    free(queue);
    *_queue = NULL;
}

size_t getSize(Queue* queue){
    return queue->size;
}

bool isEmpty(Queue* queue){
    if(getSize(queue) == 0)
        return true;
    return false;
}

void enqueue(Queue* queue, int vertex){

    NodeObject* node = newNode(vertex);
    if(isEmpty(queue)){
        queue->first = node;
        queue->last = node;
    }else{
        queue->last->next = node;
        queue->last = node;
    }
    queue->size++;
}

void dequeue(Queue* queue){
    if(!isEmpty(queue)){
        NodeObject* node = queue->first;
        if(queue->size == 1){
            queue->first = NULL;
            queue->last = NULL;
        }else{
            queue->first = queue->first->next;
        }

        free(node);
        queue->size--;
    }
}

data_type peek(Queue* queue){
    return queue->first->data;
}