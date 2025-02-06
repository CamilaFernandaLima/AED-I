#include <stdio.h>
#include <stdlib.h>

typedef struct adjacencia{
    int vertice;
    int peso;
    struct adjacencia *prox;
} ADJ;

typedef struct vertice{
    ADJ *cabeca;
} VERTICE;

typedef struct grafo{
    int vertice;
    int arestas;
    VERTICE *adj;
} GRAFO;