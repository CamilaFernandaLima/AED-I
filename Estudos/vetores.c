// Vetores:

// declarar: tipo nome[tamanho];
// manipulação dos vetores: usa v[i] dentro de um for;

#include <stdio.h>
/*#include <stdlib.h>

int main(){

    int v1[5];
    int v2[5];
    unsigned i, produto, escalar;

    printf("Vetor1: \n");
    for(i=0; i<5; i++){
        printf("elemento %d: ", i+1);
        scanf("%d", &v1[i]);
    }

    printf("\nVetor2: \n");
    for(i=0; i<5; i++){
        printf("elemento %d: ", i+1);
        scanf("%d", &v2[i]);
    }

    printf("\nProduto: ");
    for(i=0; i<5; i++){
        produto = v1[i] * v2[i];
        printf("%d ", produto);
        escalar += produto;
    }
    
    printf("\nEscalar = %d\n", escalar);

    return 0;
}*/

int main(){
    int vetor[5], i, ch, store;

    for(i=0; i<5; i++){
        printf("elemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    do{
        ch = 0;
        for(i=0; i<5; i++){
           if (vetor[i]> vetor[i+1]){
                store = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = store;

                ch = 1;
            } 
        }
    } while (ch == 1);

    for(i=0; i<5; i++){
        printf("%d ", vetor[i]);
    }
}

// funções para calcular prodito escalar de vetores e ordenar em ordem crescente.

/* usar vetor com tamanho desconhecido:

    int tamanho = sizeof(vetor) / sizeof(int);
    for (i=0; i<tamanho; i++){} 
   
   */