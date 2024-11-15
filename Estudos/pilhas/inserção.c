#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vetor[200];
    int topo;
} pilha;

void empilha(int valor, pilha *pilha){

    if (pilha->topo < 200){
        pilha->vetor[pilha->topo] = valor;
        pilha->topo ++;
    } else{
        printf("Não há mais espaço na pilha.");
    }
    
}