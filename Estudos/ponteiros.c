// Ponteiros:

// *p : apontado por (conteúdo do endereço apontado por p) - %d
// p : endereço onde a variável está armazenada - %p
// &p : endereço onde p está armazenado

// ao passar ponteiros como argumento de funções, usar parâmentro assim: p ou &var


#include <stdio.h>

void display(int var, int *p);
void update(int *p);

int main(){

    int var = 15;  // valor da variável
    int *p;        // ponteiro
    int exibe;
            
    p = &var;      // ponteiro aponta para o endereço da variável

    exibe = *p;     // recebe o conteúdo do endereço pra onde p aponta
    
    display(var,p);
    printf("\n");

    update(p);
    display(var,p);

    return 0;
}


void display(int var, int *p){
    printf("conteudo de var = %d\n", var);
    printf("endereco de var = %p\n", &var);
    printf("conteudo apontado por p = %d\n", *p);
    printf("endereco apontado por p = %p\n", p);
    printf("endereco de p: %p\n", &p);
}

void update(int *p){
    *p += 1;
}

/* da para usar para indexação de matrizes, fazendo iteração no endereço apontado pelo ponteiro: printf("%d", *(point+i)) dentro do laço for*/