#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;


void remover(No *cabeca, int num){
    No *no = cabeca;
    No *anterior = NULL;

    while(no != NULL && no->valor != num){
        anterior = no;
        no = no->proximo;
    }

    if (no != NULL){
        if(anterior != NULL){
            anterior->proximo = no->proximo;
        } else{
            cabeca->proximo = no->proximo;
        }
        free(no);
    }
}


int main(){
    No *cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;

    remover(cabeca, 6);

}

