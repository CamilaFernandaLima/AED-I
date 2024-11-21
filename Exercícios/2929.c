#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vetor[1000];
    int topo;
} pilha;

void push(int x, pilha *p){

    if (p->topo < 1000){
        p->vetor[p->topo] = x;
        p->topo ++;
    }
}

void pop(pilha *p){

    if(p->topo > 0){
        p->topo--;
    } else{
        printf("EMPTY\n");
    }
}

int min(pilha *p){

    if (p->topo == 0){
        printf("EMPTY\n");
        return -1;
    }else{
        int menor = p->vetor[0];
        for (int i = 1; i < p->topo; i++){
            if (p->vetor[i] < menor){
                menor = p->vetor[i];
            } 
        }
        return menor; 
    }
    
}

int main(){
    int n, num;
    scanf("%d", &n);

    char entrada[10];

    pilha p;
    p.topo = 0;

    for(int i=0; i<n; i++){
        scanf("%s", entrada);

        if (strcmp(entrada, "PUSH") == 0){
            scanf("%d", &num);
            push(num, &p);
        } else if (strcmp(entrada, "POP") == 0){
            pop(&p);
        } else if (strcmp(entrada, "MIN") == 0){
            int a = min(&p);
            if (a != -1){
                printf("%d\n", a);
            }
            
        }
    }

    return 0;
}