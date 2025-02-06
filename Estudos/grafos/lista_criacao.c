#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

GRAFO *criagrafo(int v){
    GRAFO *g = malloc(sizeof(GRAFO));
    g->vertice = v;
    g->arestas = 0;
    
    g->adj = malloc(v * sizeof(VERTICE));

    for(int i=0; i<v; i++){
        g->adj[i].cabeca = NULL;
    }

    return g;
}

ADJ *criaadj(int v, int peso){
    ADJ *aux = (ADJ *) malloc(sizeof(ADJ));
    aux->vertice = v;
    aux->peso = peso;
    aux->prox = NULL;
    return aux;
}

bool criaaresta(GRAFO *gr, int vi, int vf, int p){
    ADJ *novo = criaadj(vf, p);

    novo->prox = gr->adj[vi].cabeca;
    gr->adj[vi].cabeca = novo;
    gr->arestas++;

    return true;
}

void imprime(GRAFO *g){
    int i;
    for(i=0; i<g->vertice; i++){
        printf("v(%d):", i);
        ADJ *ad = g->adj[i].cabeca;
        while(ad){
            printf("v%d(%d) ",ad->vertice, ad->peso);
            ad = ad->prox;
        }
        printf("\n");
    }
} 