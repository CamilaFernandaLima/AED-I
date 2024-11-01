#include <stdio.h>

int maiorT(float v[], int n) {

    int maior = v[0];

    for(int i=1; i<n; i++){
        if (v[i]>maior){
            maior = v[i];
        }
    }

    return maior;
}


int main() {
    // Exemplo de uso da função
    float v[] = {1.5, 3.2, 0.7, 4.8, 2.1};
    int n = 5;
    
    float result = maiorT(v, n);
    printf("Maior valor no vetor: %.f\n", result);
    
    return 0;
}