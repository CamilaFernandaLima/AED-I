#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} No;

void imprimir(No *cabeca){
    No *atual = cabeca->proximo;

    while(atual != NULL){ 
        printf("%d ", atual->valor); 
        atual = atual->proximo; 
    }
    printf("\n");

}

int main(){
    No *cabeca = malloc(sizeof(No));
    imprimir(cabeca);
}