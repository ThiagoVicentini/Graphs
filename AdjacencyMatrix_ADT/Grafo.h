struct graph{
    int V;
    int A;
    int **mat;
};
typedef struct graph* ptGr;
ptGr create_Graph(int v);
void insert_Edge(ptGr gr, int v1, int v2);
void remove_Edge(ptGr gr, int v1, int v2);
void show_MatrixADJ(ptGr gr);
void delete_Graph(ptGr gr);
