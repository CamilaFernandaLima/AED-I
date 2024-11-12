#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;

void inserir_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));  // alocação de memória para um novo nó

    if(novo){
        novo->valor = num;    // valor do novo nó
        novo->prox = *lista;  // próximo do novo nó = início da lista atual
        *lista = novo;        // incício da lista atual = novo nó (valor)
    }
}

int main(){
    
    return 0;
}