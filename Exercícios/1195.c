#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    int chave;
    struct cel *esq;
    struct cel *dir;
} no;

no *insere(int v, no *novo){
    no *novo;
    novo = malloc (sizeof (no));
    novo->chave = v;
    novo->esq = novo->dir = NULL;
}

no *busca(no *r, int k) {
    if (r == NULL || r->chave == k)
       return r;
    if (r->chave > k)
       return busca (r->esq, k);
    else
       return busca (r->dir, k);
}