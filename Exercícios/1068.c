#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int vetor[200];
    int topo;
} pilha;


void empilha(int valor, pilha *pilha){

    if (pilha->topo < 200){
        pilha->vetor[pilha->topo] = valor;
        pilha->topo ++;
    } else{
        printf("Não há mais espaço na pilha.");
    }
    
}

void desempilha(pilha *pilha){

    if (pilha->topo > 0){
        pilha->topo--;
    } else{
        printf("A pilha está vazia.");
    }
}

int main(){

    char conta[1000];
    pilha p;
    p.topo = 0;

    while (fgets(conta,sizeof(conta), stdin) != NULL){
        int tam = strlen(conta);
        for (int i=0; i<tam; i++){
            if(conta[i] == '('){
                empilha('(', &p);
            } else if(conta[i] == ')'){
                if(p.topo >0 && p.vetor[p.topo-1] == '('){
                    desempilha(&p);
                } else{
                    empilha(')', &p);
                }
            }
        }

        if (p.topo == 0){
            printf("correct\n");
        } else{
            printf("incorrect\n");
        }
        p.topo = 0;
    }
    

    return 0;
}
