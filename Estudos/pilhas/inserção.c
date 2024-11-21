#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *proximo;
} pilha;

void empilha(int num, pilha *p){
    pilha *nova;
    nova = malloc(sizeof(pilha));

    nova->valor = num;
    nova->proximo = p->proximo;
    p->proximo = nova;
}

int main(){
    pilha cabeca;
    pilha *p;

    p = &cabeca;
    p->proximo = NULL;

    empilha(6, &p);
}