#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

// Estrutura para Pilha
typedef struct {
    int dados[MAX];
    int topo;
} pilha;

// Estrutura para Fila
typedef struct {
    int dados[MAX];
    int inicio, fim;
} fila;

// Estrutura para Fila de Prioridade
typedef struct {
    int dados[MAX];
    int tamanho;
} fila_prioridade;

// Funções para Pilha
void insere_pilha(int v, pilha *p) {
    p->dados[++(p->topo)] = v;
}

int remove_pilha(pilha *p) {
    return p->dados[(p->topo)--];
}

// Funções para Fila
void insere_fila(int v, fila *f) {
    f->dados[(f->fim)++] = v;
}

int remove_fila(fila *f) {
    return f->dados[(f->inicio)++];
}

// Funções para Fila de Prioridade
void insere_fila_prioridade(int v, fila_prioridade *fp) {
    int i = fp->tamanho - 1;
    while (i >= 0 && fp->dados[i] < v) { // Insere de forma ordenada (maior para menor)
        fp->dados[i + 1] = fp->dados[i];
        i--;
    }
    fp->dados[i + 1] = v;
    fp->tamanho++;
}

int remove_fila_prioridade(fila_prioridade *fp) {
    return fp->dados[--(fp->tamanho)]; // Remove o maior elemento (última posição)
}

int main() {
    int n;

    // Leitura de número de comandos
    while (scanf("%d", &n) != EOF) {
        // Inicialização das estruturas
        pilha p = {.topo = -1};
        fila f = {.inicio = 0, .fim = 0};
        fila_prioridade fp = {.tamanho = 0};

        bool is_stack = true, is_queue = true, is_pq = true;

        for (int i = 0; i < n; i++) {
            int comando, x;
            scanf("%d %d", &comando, &x);

            if (comando == 1) { // Inserção
                if (is_stack) insere_pilha(x, &p);
                if (is_queue) insere_fila(x, &f);
                if (is_pq) insere_fila_prioridade(x, &fp);
            } else if (comando == 2) { // Remoção
                if (is_stack) {
                    if (p.topo == -1 || remove_pilha(&p) != x) is_stack = false;
                }
                if (is_queue) {
                    if (f.inicio == f.fim || remove_fila(&f) != x) is_queue = false;
                }
                if (is_pq) {
                    if (fp.tamanho == 0 || remove_fila_prioridade(&fp) != x) is_pq = false;
                }
            }
        }

        // Verificação dos resultados
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

    return 0;
}
