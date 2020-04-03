#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

ptGr create_Graph(int v){
    //creating a pointer
    ptGr gr = (ptGr)malloc(sizeof(struct graph));
    gr->V = v;
    gr->A = 0;
    //creating the adj matrix
    int** matrix = (int**)calloc(v, sizeof(int*));
    for(int i = 0; i < v; i++)
        matrix[i] = (int*)calloc(v, sizeof(int));
    gr->mat = matrix;
    return gr;
}

void insert_Edge(ptGr gr, int v1, int v2){
    if(gr->mat[v1][v2] == 0){
        gr->mat[v1][v2] = 1;
        gr->mat[v2][v1] = 1;
        gr->A++;
    }
}

void remove_Edge(ptGr gr, int v1, int v2){
    if(gr->mat[v1][v2] == 1){
        gr->mat[v1][v2] = 0;
        gr->mat[v2][v1] = 0;
        gr->A--;
    }
}

void show_MatrixADJ(ptGr gr){
    for(int i = 0; i < gr->V; i++){
        for(int j = 0; j < gr->V; j++){
            if(j != (gr->V - 1))
                printf("%d ", gr->mat[i][j]);
            else
                printf("%d\n", gr->mat[i][j]);
        }
    }
    printf("\n");
}

void delete_Graph(ptGr gr){
    for(int i = 0; i < gr->V; i++){
        free(gr->mat[i]);
    }
    free(gr->mat);
}
