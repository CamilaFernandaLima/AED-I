#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int vetor[200];
    int topo;
} pilha;

void imprime(pilha *pilha){
    for(int i=pilha->topo; i>0; i--){
       printf("%d\n", pilha->vetor[i]); 
    }
}