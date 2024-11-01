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


int main() {
    // Exemplo de uso da função
    double numeros[] = {1.5, 3.2, 0.7, 4.8, 2.1};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    
    double maior = encontrarMaiorValor(numeros, tamanho);
    printf("O maior valor no vetor é: %.2f\n", maior);
    
    return 0;
}