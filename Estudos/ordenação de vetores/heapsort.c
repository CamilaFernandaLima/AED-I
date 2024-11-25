#include <stdio.h>

void criaheap(int *v, int i, int f){
    int aux = v[i];
    int j = 2*i + 1;  // filhos: (2i + 1) e (2i + 2)
    while (j<=f){
        if (j<f){
            if(v[j] < v[j+1]){ //encontra o maior filho.
                j = j+1;
            }
        }

        if(aux < v[j]){//filho maior que pai? repetir
            v[i] = v[j];      
            i = j;
            j = 2*i + 1;
        } else{
            j = f+1;
        }
    }
    v[i] = aux;
}


void heapsort(int *v, int n){
    int i, aux;

    for(i=(n-1)/2; i>=0; i--){
        criaheap(v, i, n-1);
    }  

    for(i=n-1; i>=1; i--){
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;

        criaheap(v, 0, i-1);
    }
}