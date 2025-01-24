#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int valor;
    struct no *prox;
} no;

void insere_fila(int v, no **cabeca){
    no *novo; 
    novo = malloc(sizeof(no));

    novo->valor = v;
    novo->prox = NULL;

    if(*cabeca == NULL){
        *cabeca = novo;
    } else{
        no *aux = *cabeca;
        while (aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int remove_fila(no **cabeca){
    no *aux = *cabeca;
    int x = aux->valor;

    if(*cabeca != NULL){
        *cabeca = aux->prox;
        free(aux);
    }
    return x;

}

void insere_pilha(int v, no **cabeca){
    no *novo;
    novo = malloc(sizeof(no));

    novo->valor = v;
    novo->prox = *cabeca;
    *cabeca = novo;
}

int remove_pilha(no **cabeca){
    no *aux = *cabeca;
    int x = aux->valor;

    if (*cabeca != NULL){
        *cabeca = aux->prox;
        free(aux); 
    }
    return x;
}

void insere_p(int v, no **cabeca){
    no *novo;
    novo = malloc(sizeof(no));
    novo->valor = v;
    
    if(*cabeca == NULL || (*cabeca)->valor < v){
        novo->prox = *cabeca;
        *cabeca = novo;
    }else {
        no *aux = *cabeca;
        while (aux->prox != NULL && aux->prox->valor >= v){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }

}

int main(){
    bool is_stack = true;
    bool is_queue = true;
    bool is_pq = true;
    no *pilha = NULL, *fila = NULL, *pq_i = NULL;

    int n;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int comando;
        scanf("%d", &comando);

        if(comando == 1){
            int x;
            scanf("%d", &x);

            if (is_stack) insere_pilha(x, &pilha);
            if (is_queue) insere_fila(x, &fila);
            if (is_pq) insere_p(x, &pq_i);

        } else if (comando == 2){
            int x;
            scanf("%d", &x);

            if(is_stack){
                if (pilha == NULL || remove_pilha(&pilha) != x){
                    is_stack = false;
                }
            }
            if(is_queue){
                if (fila == NULL || remove_fila(&fila) != x){
                    is_queue = false;
                }    
            }
            if(is_pq){
                if (pq_i == NULL || remove_fila(&pq_i) != x){
                    is_pq = false;
                }    
            }   
        }
    }


    //Verificação dos resultados:
    if (is_stack + is_queue + is_pq > 1) printf("not sure\n");
    else if (is_stack) printf("stack\n");
    else if(is_queue) printf("queue\n");
    else if (is_pq) printf("priority queue\n");
    else printf("impossible\n");

    return 0;
}