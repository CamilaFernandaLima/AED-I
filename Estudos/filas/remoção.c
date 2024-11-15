#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void remover(No **fila){
    No *remover = NULL;

    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }
}


int main(){
    

}

void remover(item *cabeca, int num){
    item *no = cabeca;
    item *aux = cabeca->proximo;

    while(aux != NULL && aux->valor != num){
        no = aux;
        aux = aux->proximo;
    }
    if (aux != NULL){
        no->proximo = aux->proximo;
        free(no);
    }

}