#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if (novo){
        novo->valor = num;
        novo->proximo = NULL;

        //inserção sempre no final
        //verificar se a fila esta vazia:
        if (*fila == NULL){
            *fila = novo;
        } else{
            aux = *fila;
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novo;

        }
    }
}


int main(){
    

}