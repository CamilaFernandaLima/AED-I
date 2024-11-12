#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;


No* remove (No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->prox;
        } else{
            aux = *lista;  // criado para não alterar valor da lisat
            while(aux->prox && aux->prox->valor != num){
                aux = aux->prox;
            }
            if(aux->prox){
                remover = aux-> prox;
                aux->prox = remover->prox;
            }
        }
    }

    return remover;
}

int main(){

    int valor, anterior;
    No *remove, *lista = NULL;

    printf("Digite um valor para remover: ");
    scanf("%d", &valor);
    remove = remover(&lista, valor);
    if(remove){
        free(remove);
    }

}