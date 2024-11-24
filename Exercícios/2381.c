#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(const *a, const *b){
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {

    int n;
    char entrada[20];
    scanf("%d", &n);

    char vetor[1000];
    for(int i=0; i<n; i++){
        scanf("%s", &entrada);
        vetor[i] = entrada;
    }

    qsort(vetor, n, sizeof(const char*), comparar);

    // Imprime as strings ordenadas
    printf("Strings ordenadas em ordem alfabética:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", vetor[i]);
    }

    return 0;
}