#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int valor;
    struct cel *prox;
} fila;

void insere(int num, fila *entra){
    fila *novo;
    novo = malloc(sizeof(fila));
    novo->valor = num;
    novo->prox = NULL;

    if(entra->prox == NULL){
        entra->prox = novo;
    } else{
        fila *aux = entra;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int conta_nao(fila *entrada){
    int tamanho = 0;
    fila *aux = entrada->prox;

    while(aux != NULL){
        tamanho++;
        aux = aux->prox;
    }

    int *notas = malloc(tamanho * sizeof(int)); //cria array
    aux = entrada->prox;
    for(int i=0; i<tamanho; i++){
        notas[i] = aux->valor;
        aux =  aux->prox;
    }

    // Ordena o array em ordem decrescente (bubble sort)
    for(int i=0; i<tamanho-1; i++){
        for(int j=0; j<tamanho-1-i; j++){
            if (notas[j] < notas[j+1]){
                int temp = notas[j];
                notas[j] = notas[j+1];
                notas[j+1] = temp;
            }
        }
    }

    // Compara o array ordenado com a fila original
    int contador = 0;
    aux = entrada->prox;
    for(int i=0; i<tamanho; i++){
        if(notas[i] == aux->valor){
            contador++;
        }
        aux = aux->prox;
    }

    free(notas);
    return contador;
}

void libera(fila *entrada){
    fila *aux = entrada->prox;

    while(aux != NULL){
        fila *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    entrada->prox = NULL;
}

int main(){
    int n, m, num;
    fila *fila = malloc(sizeof(fila));
    fila->prox = NULL;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &m);
        for(int j=0; j<m; j++){
            scanf("%d", &num);
            insere(num, fila);
        }

        int result = conta_nao(fila);
        printf("%d\n", result);

        libera(fila);
    }

    free(fila);

    return 0;
}