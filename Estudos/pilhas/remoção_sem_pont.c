#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vetor[200];
    int topo;
} pilha;

void desempilha(pilha *pilha){

    if (pilha->topo > 0){
        pilha->topo--;
    } else{
        printf("A pilha está vazia.");
    }
}