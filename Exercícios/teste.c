#include <stdio.h>

int main(){

    int vetor[5], i, store;

    printf("insira um vetor de %d elementos: \n", 5);
    for (i=0; i<5; i++){
        printf("\nelemento %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for(int j=0; j<4; j++){
        for(i=0; i<4-i; i++){
            if (vetor[i]>vetor[i+1]){
                store = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = store;
            }
        }
    }
        

    for(i=0;i<5;i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}