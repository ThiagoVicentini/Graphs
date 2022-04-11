#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "list.h"

/**
    Aloca espaço para o grafo e para a lista de adjacencia (inicialmente vazia) e inicializa a quantidade de vertices e arestas
    @param int numberOfVertices: Numero de vertices do grafo
    @return Graph* graph: Ponteiro para o objeto grafo
*/
Graph* newGraph(int _numberOfVertices){
	Graph* graph = malloc(sizeof *graph);
	graph->numberOfVertices = _numberOfVertices;
	graph->numberOfEdges = 0;
	graph->adjList = malloc(_numberOfVertices * sizeof (List));
    for(int i=0; i < _numberOfVertices; i++)
        graph->adjList[i] = newList();
    return graph;
}

/**
    Libera espaço de memoria alocado previamente para o objeto 
    @param Graph* graph: Ponteiro para o objeto grafo
*/
void freeGraph(Graph* graph){
    for(int i=0; i < graph->numberOfVertices; i++)
        freeList(graph->adjList[i]);
    free(graph->adjList);
    free(graph);
}

/**
    Insere o nodo com o valor do vertice de destino na lista de adjacencia do vertice de origem.
    @param Graph* graph: Ponteiro para o grafo que deseja inserir a aresta
    @param int vOrig: Valor numerico do vertice de saida da aresta
    @param int vDest: Valor numerico do vertice de chegada da aresta
*/
void insertEdge(Graph* graph, int vOrig, int vDest){
    insertListOrd(graph->adjList[vOrig], vDest);
}

/**
    Remove o nodo com o valor do vertice de destino na lista de adjacencia do vertice de origem.
    @param Graph* graph: Ponteiro para o grafo que deseja inserir a aresta
    @param int vOrig: Valor numerico do vertice de saida da aresta
    @param int vDest: Valor numerico do vertice de chegada da aresta
*/
void removeEdge(Graph* graph, int vOrig, int vDest ){
    removeFromList(graph->adjList[vOrig], vDest);
}

/**
    Exibe a lista de adjacencia do grafo com os valores numericos
    @param Graph* graph: Ponteiro para o grafo que deseja exibir a lista de adjacencia
*/
void showAdjList(Graph* graph){
    for(int i=0; i < graph->numberOfVertices; i++){
        printf("%d: ", i);
        showList(graph->adjList[i]);
    }
    printf("\n");
}

/**
    Transpoe um grafo (inverte as arestas direcionadas) e retorna o grafo transposto
    @param Graph* graph: Ponteiro para o grafo que deseja calcular o grafo transposto
    @return Graph* newGraph: Ponteiro para o grafo transposto calculado a partir da entrada
*/
Graph* transpose(Graph* graph){
    Graph* graphT = newGraph(graph->numberOfVertices);
    NodeObject* node;
    for(int i=0; i < graph->numberOfVertices; i++){
        //strcpy(newG->pessoas[i], g->pessoas[i]);
        node = *(graph->adjList[i]);
        while (node != NULL){
            insertEdge(graphT, node->data, i);
            node = node->next;
        }
    }
    return graphT;
}