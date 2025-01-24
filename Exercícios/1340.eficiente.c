#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int dados[1000];
    int topo;
} pilha;

typedef struct {
    int dados[1000];
    int inicio, fim;
} fila;

typedef struct {
    int dados[1000];
    int tamanho;
} fila_prioridade;

void insere_pilha(int v, pilha *p){
    p->dados[++(p->topo)] = v;
}

int remove_pilha(pilha *p){
    return p->dados[(p->topo)--];
}

void insere_fila(int v, fila *f){
    f->dados[(f->fim)++] = v;
}

int remove_fila(fila *f){
    return f->dados[(f->inicio)++];
}

void insere_prioridade(int v, fila_prioridade *fp){
    int i = fp->tamanho -1;
    while(i >= 0 && fp->dados[i] < v){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }
    fp->dados[i+1] = v;
    fp->tamanho++;
}

int remove_prioridade(fila_prioridade *fp) {
    return fp->dados[--(fp->tamanho)];
}


int main(){
    int n;
    scanf("%d", &n);

    // Inicialização das estruturas
    pilha p = {.topo = -1};
    fila f = {.inicio = 0, .fim = 0};
    fila_prioridade fp = {.tamanho = 0};


    bool is_stack = true, is_queue = true, is_pq = true;

    for (int i = 0; i<n; i++){
        int comando,x;
        scanf("%d %d", &comando, &x);

        if(comando == 1){
            if(is_stack) insere_pilha(x, &p);
            if (is_queue) insere_fila(x, &f);
            if (is_pq) insere_prioridade(x, &fp);
        } else if(comando == 2){
            if (is_stack) {
                if (p.topo == -1 || remove_pilha(&p) != x) is_stack = false;
            }
            if (is_queue) {
                if (f.inicio == f.fim || remove_fila(&f) != x) is_queue = false;
            }
            if (is_pq) {
                if (fp.tamanho == 0 || remove_prioridade(&fp) != x) is_pq = false;
            }
        }
    }

    if (is_stack + is_queue + is_pq > 1) {
        printf("not sure\n");
    } else if (is_stack) {
        printf("stack\n");
    } else if (is_queue) {
        printf("queue\n");
    } else if (is_pq) {
        printf("priority queue\n");
    } else {
        printf("impossible\n");
    }
    
}