#include <stdio.h>

void insertionsort(int *v, int n){
    int i, j, aux;

    for(i=1; i<n; i++){
        aux = v[i];
        for (j=i-1; (j>=0) && (aux< v[j-1]); j--){
            v[j+1] = v[j]; //desloca todos uma posição para a frente.
        }
        v[j+1] = aux;
    }
}

//move as cartas do baralho!!