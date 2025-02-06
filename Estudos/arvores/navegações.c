//ordem de navegação 
#include <stdio.h>
#include <stdlib.h>

void erd(arvore r){
    if(r!+ NULL){
        erd(r->esq);
        printf("%d", r->conteudo);
        erd(r->dir);
    }
    return 
}