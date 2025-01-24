#include <stdio.h>
#include <stdlib.h>

typedef struct elementolista{
    int valor;
    struct elementolista *prox;
    struct elementolista *ant;
} item;

void inserir(item *cabeca, int num){
    item *novo;
    novo = malloc(sizeof(item));
    
    novo->valor = num;
    novo->prox = NULL;
    novo->ant = NULL;

    item *aux = cabeca;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux;
}

void imprimir(item *cabeca){
    item *atual;
    atual = cabeca;

    while(atual->prox != NULL){
        printf("%d\n", atual->prox->valor);
        atual = atual->prox;
    }
}

void imprimir_reverso(item *cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) return; // Lista vazia
    item *ultimo = cabeca;
    while (ultimo->prox != NULL) {
        ultimo = ultimo->prox; // Encontra o último nó
    }
    while (ultimo != cabeca) { // Imprime de trás para frente
        printf("%d\n", ultimo->valor);
        ultimo = ultimo->ant;
    }
}

void insertionsort(item *cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) return; // Lista vazia ou com um único elemento

    item *ordenado = NULL;
    item *atual = cabeca->prox;

    while (atual != NULL) {
        item *proximo = atual->prox;

        // Inserir "atual" na posição correta na lista ordenada
        if (ordenado == NULL || atual->valor <= ordenado->valor) {
            atual->prox = ordenado;
            if(ordenado != NULL) ordenado->ant = atual;
            atual->ant = NULL;
            ordenado = atual;
        } else {
            item *aux = ordenado;
            while (aux->prox != NULL && aux->prox->valor < atual->valor) {
                aux = aux->prox;
            }
            atual->prox = aux->prox;
            if (aux->prox != NULL) aux->prox->ant = atual;
            aux->prox = atual;
            atual->ant = aux;
        }
        atual = proximo;
    }

    cabeca->prox = ordenado; // Atualiza a cabeça para apontar para a lista ordenada
    if(ordenado != NULL) ordenado->ant = cabeca;
}


int main(){

    //lista vazia
    item *pares = (item*)malloc(sizeof(item));
    pares->prox = NULL;

    item *impares = (item*)malloc(sizeof(item));
    impares->prox = NULL;

    int n,x;
    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &x);
        if(x%2 == 0){
            inserir(pares, x);
        } else{
            inserir(impares, x);
        }
    }

    insertionsort(pares);
    insertionsort(impares);

    imprimir(pares);
    imprimir_reverso(impares);
}