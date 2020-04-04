#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

ptGr create_Graph(int v){
    //creating a pointer
    ptGr gr = (ptGr)malloc(sizeof(struct graph));
    gr->V = v;
    gr->A = 0;
    //allocating the adj matrix
    int** matrix = (int**)calloc(v, sizeof(int*));
    for(int i = 0; i < v; i++)
        matrix[i] = (int*)calloc(v, sizeof(int));
    gr->mat = matrix;
    return gr;
}

void insert_Edge(ptGr gr, int v1, int v2){
    if(gr->mat[v1][v2] == 0){ //if the edge between v1 and v2
        gr->mat[v1][v2] = 1;  //doesn't exist, create it
        gr->mat[v2][v1] = 1;  //and increment the number of edges
        gr->A++;              //ps: undirected graph has a symmetrical matrix
    }
}

void remove_Edge(ptGr gr, int v1, int v2){
    if(gr->mat[v1][v2] == 1){   //ps: undirected graph has a symmetrical matrix
        gr->mat[v1][v2] = 0;
        gr->mat[v2][v1] = 0;
        gr->A--;
    }
}

int has_Edge(ptGr gr, int v1, int v2){
    if(gr->mat[v1][v2] == 1)    //ps: undirected graph has a symmetrical matrix
        return 1;
    return 0;
}

void show_MatrixADJ(ptGr gr){
    for(int i = 0; i < gr->V; i++){
        for(int j = 0; j < gr->V; j++){     //run through the matrix with a for loop
            if(j != (gr->V - 1))            //check if it's the last column
                printf("%d ", gr->mat[i][j]);
            else
                printf("%d\n", gr->mat[i][j]);
        }
    }
    printf("\n");
}

int* list_byDegree(ptGr gr, int degree, int* lengh_list) //lengh_list is useful to print the items of the list with a loop
{
    int* list = (int*)malloc(sizeof(int)); //allocate memory for the list of vertices
    int count = 1; //count the vertices that has the desirable degree (starts with "1" to avoid problems in the realloc)
    int aux = 0;   //assistant variable to count the number of edges
    for(int i = 0; i < gr->V; i++){
        for(int j = 0; j < gr->V; j++){ //run through the matrix
            if(gr->mat[i][j] == 1)
                aux++; //if the edge between i and j exists, count it
        }
        if(aux == degree){ //before moves to the next column check if the the vertices has the desirable degree
            list[count - 1] = i; //if has, save the id of the vertice
            count++;
            list = (int*)realloc(list, count*sizeof(int));//increase the lengh of the list
        }
        aux = 0;
    }
    *lengh_list = count-1; //decrease 1 because it starts at 1 (variable change)
    return list;
}


void delete_Graph(ptGr gr){
    for(int i = 0; i < gr->V; i++){
        free(gr->mat[i]);
    }
    free(gr->mat);
    free(gr);
}
