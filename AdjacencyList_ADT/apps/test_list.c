#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(){
    List* list = newList();

    insertEndList(list, 3);
    insertEndList(list, 5);
    insertEndList(list, 1);
    showList(list);

    removeFromList(list, 2);
    removeFromList(list, 3);
    removeFromList(list, 4);
    showList(list);

    removeFromList(list, 5);
    removeFromList(list, 1);
    showList(list);

    insertListOrd(list, 7);
    insertListOrd(list, 3);
    insertListOrd(list, 3);
    insertListOrd(list, 9);
    insertListOrd(list, 0);
    showList(list);

    freeList(list);
    
    return 0;
}