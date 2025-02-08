#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int V; 
    int A; 
    int **adj; 
}grafo;


static int **MATRIXint( int r, int c, int val) { 
    int **m = malloc( r * sizeof (int *));
    for (int i = 0; i < r; ++i) 
       m[i] = malloc( c * sizeof (int));
    for (int i = 0; i < r; ++i)
       for (int j = 0; j < c; ++j)
          m[i][j] = val;
    return m;
}

grafo *GRAPHinit(int V) { 
    grafo *G = malloc( sizeof *G);
    G->V = V; 
    G->A = 0;
    G->adj = MATRIXint( V, V, 0);
    return G;
}

void GRAPHinsertArc(grafo *G, int v, int w) { 
    if (G->adj[v][w] == 0) {
       G->adj[v][w] = 1; 
       G->A++;
    }
}

void GRAPHremoveArc(grafo *G, int v, int w) { 
    if (G->adj[v][w] == 1) {
       G->adj[v][w] = 0; 
       G->A--;
    }
}

void GRAPHshow(grafo *G) { 
    for (int v = 0; v < G->V; ++v) {
       printf( "%2d:", v);
       for (int w = 0; w < G->V; ++w)
          if (G->adj[v][w] == 1) 
             printf( " %2d", w);
       printf( "\n");
    }
}

void print(grafo *G){
    for (int v = 0; v < G->V; v++) {
        for (int w = 0; w < G->V; w++){
            printf("%d", G->adj[v][w]);
        }
       printf("\n");
    }
}

int main(){
    grafo *g;
    g = GRAPHinit(4);
    GRAPHinsertArc(g,2,2);
    GRAPHinsertArc(g,3,1);

    GRAPHshow(g);
    print(g);
}