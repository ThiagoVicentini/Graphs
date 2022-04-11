#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(){
    Queue* queue = newQueue();

    enqueue(queue, 2);
    enqueue(queue, 5);
    enqueue(queue, 1);
    enqueue(queue, 7);
    
    while(!isEmpty(queue)){
        printf("%d\n", peek(queue));
        dequeue(queue);
    }

    freeQueue(&queue);
    
    return 0;
}