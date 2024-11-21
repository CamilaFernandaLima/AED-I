#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *proximo;
} pilha;

void desepilha(pilha *p){
    int x;
    pilha *aux;

    aux = p->proximo;
    x = aux->valor;
    p->proximo = aux->proximo;
    free(aux);
}

int main(){
    pilha cabeca;
    pilha *p;

    p = &cabeca;
    p->proximo = NULL;

    desempilha(&p);
}