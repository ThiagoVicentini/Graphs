#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main(){
    Graph* graph = newGraph(4);

    insertEdge(graph, 0, 1);
    insertEdge(graph, 0, 2);
    insertEdge(graph, 2, 3);
    showAdjList(graph);

    removeEdge(graph, 0, 1);
    removeEdge(graph, 0, 1);
    removeEdge(graph, 0, 3);
    showAdjList(graph);

    Graph* graphT = transpose(graph);
    showAdjList(graphT);

    freeGraph(graph);
    freeGraph(graphT);
    return 0;
}