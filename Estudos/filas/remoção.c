#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;


void remover(No **cabeca){
    No *aux;
    
    aux = *cabeca;
    *cabeca = aux->proximo;
    free(aux);
   
}


int main(){
    int x = 0;
    No *cabeca = malloc(sizeof(No));

    cabeca->valor = x;
    cabeca->proximo = NULL;

    remover(&cabeca);
    return 0;
}

