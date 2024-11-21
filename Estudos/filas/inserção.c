#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir(No **cabeca, int num){
    No *novo;
    novo = malloc(sizeof(No));

    novo->valor = num; 
    novo->proximo = NULL;

    //inserção sempre no final
    //verificar se a fila esta vazia:
    
    if (*cabeca == NULL){
        *cabeca = novo;
    } else{
        No *atual = *cabeca;
        while(atual->proximo != NULL){
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    
}


int main(){
    No *cabeca = NULL;

    inserir(&cabeca, 6);

}

