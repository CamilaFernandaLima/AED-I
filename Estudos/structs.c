#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct componente{
    char tipo[20];
    char referencial[4];
    unsigned char num;
    int valor;
    char unidade[10];
};
// ; por que não é função, e sim declaração

// criação de uma estrutura de dados desse tipo
struct componente comp;


int main(){
    printf("Tipo do componente: ");
    fgets(comp.tipo, 20, stdin);

    printf("Tipo da referencia: ");
    fgets(comp.referencial, 4, stdin);

    printf("Numero da referencia: ");
    scanf("%c", &comp.num);

    printf("Valor do componente: ");
    scanf("%d", &comp.valor);

    printf("Unidade: ");
    fflush(stdin);
    fgets(comp.unidade, 10, stdin);

    printf("\nCOMPONENTE CRIADO:");
    printf("%s", comp.tipo);
    printf("%s", comp.referencial);
    printf("%c", comp.num);
    printf("Valor: %d", comp.valor);
    printf(" %s", comp.unidade);
}

// para usar struct no código, temos: nomedastruct.nomedavariavel;