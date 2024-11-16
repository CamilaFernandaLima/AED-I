#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir(No *cabeca, int num){
    No *novo;
    novo = malloc(sizeof(No));

    novo->valor = num; 
    novo->proximo = NULL;

    //inserção sempre no final
    //verificar se a fila esta vazia:
    
    No *atual = cabeca;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    
    atual->proximo = novo;
}


int main(){
    No *cabeca = (No*)malloc(sizeof(No));
    cabeca->proximo = NULL;

    inserir(cabeca, 6);

}

/* SEM PONTEIROS 

struct{
    int vetor[tam];
    int fim;
} fila;

main: 
    fila f;
    f.fim = 0;
    
inserir:
    f.vetor[f.fim] = num;
    f.fim++;

remover: 
    for(int i=0; i<f.fim; i++){
        f.vetor[i] = f.vetor[i+1];
    }
    f.fim--;

imprimir: 
    for(int i=0; i<f.fim; i++){
        printf("%d", f.vetor[i]);
    }
*/