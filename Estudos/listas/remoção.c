#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
} No;


No* remove (No **lista, int num){
    No *ant, *aux= *lista;

    if(*lista){
        while(aux != NULL && aux->valor != num){
            ant = aux;
            aux = aux->prox;
        }
        if (aux == NULL) printf("Não encontrado");
        if (ant == NULL) *lista = aux->prox;
        else{
            ant->prox = aux->prox;
        
        } 
        free(aux);
    }
    return *lista;
}

int main(){
    
    return 0;
}
