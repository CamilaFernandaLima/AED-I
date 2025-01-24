#include <stdio.h>
#include <stdlib.h>

typedef struct elementolista {
    int valor;
    struct elementolista *prox;
    struct elementolista *ant;
} item;

void inserir(item *cabeca, int num) {
    item *novo = malloc(sizeof(item));
    if (novo == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }
    novo->valor = num;
    novo->prox = NULL;
    novo->ant = NULL;

    item *aux = cabeca;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = novo;
    novo->ant = aux; // Atualiza o ponteiro para o nó anterior
}

void imprimir(item *cabeca) {
    item *atual = cabeca->prox; // Ignora o nó sentinela
    while (atual != NULL) {
        printf("%d\n", atual->valor);
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
    if (cabeca == NULL || cabeca->prox == NULL) return;

    item *ordenado = NULL;
    item *atual = cabeca->prox;

    while (atual != NULL) {
        item *proximo = atual->prox;

        if (ordenado == NULL || atual->valor <= ordenado->valor) {
            atual->prox = ordenado;
            if (ordenado != NULL) ordenado->ant = atual;
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

    cabeca->prox = ordenado;
    if (ordenado != NULL) ordenado->ant = cabeca;
}

int main() {
    item *pares = malloc(sizeof(item));
    pares->prox = NULL;

    item *impares = malloc(sizeof(item));
    impares->prox = NULL;

    int n, x;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x % 2 == 0) {
            inserir(pares, x);
        } else {
            inserir(impares, x);
        }
    }

    insertionsort(pares);
    insertionsort(impares);

    imprimir(pares);
    imprimir_reverso(impares);

    return 0;
}
