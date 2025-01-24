//acha o menor valor e coloca na primeira posição, depois descarta a primeira posição até acabar o vetor.

#include <stdio.h>

void selectionsort(int *v, int n){
    int i, j, menor, troca;

    //procura menor elemento em relação a i
    for(i=0; i<n-1; i++){
        menor = i;
        for(j = i+1; j<n; j++){
            if(v[j]< v[menor]){
                menor = j;
            }
        }
        if (i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}