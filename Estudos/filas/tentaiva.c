#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó
typedef struct no {
    int num;
    struct no *prox;
} No;

void inserir(No **fila, int num){
    No *aux, *novo = malloc(sizeof(No));
    if(novo){
        novo->num = num;
        novo->prox = NULL;

        if (novo->prox == NULL){
            *fila = novo;
        } else {
            aux = *fila;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
}

int main(){
    int n, m, x;
    No **lista = malloc(sizeof(No));
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &x);
        inserir(lista,x);
    }

    printf("%d", **lista);
    scanf("%d", &m);
    

}
