#include <stdio.h>

int maior(double v[], int n) {

    int maior = v[0];

    for(int i=1; i<n; i++){
        if (v[i]>maior){
            maior = v[i];
        }
    }

    return maior;
}
