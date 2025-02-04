#include <stdio.h>
#include <stdlib.h>

#define vertex int

struct noh{
    vertex w;
    no *prox;
};
typedef struct noh no;

struct grafo{
    int V;
    int A;
    no **adj;
};
typedef struct grafo *graph;

graph inicializa(int V){
    int i;
    graph g = malloc(sizeof *g);
    g->V = V;
    g->A = 0;
    g->adj = malloc(V * sizeof (no*));

    for(i=0; i<V; i++){
        g->adj[i] = NULL;
    }
    return g;
}
