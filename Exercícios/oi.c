#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char string[51];
    int original_index;
} String;

int compare(const void *a, const void *b) {
    String *str1 = (String *)a;
    String *str2 = (String *)b;

    int len1 = strlen(str1->string);
    int len2 = strlen(str2->string);

    // Comparar pelo tamanho
    if (len1 != len2) {
        return len1 - len2;
    }

    // Se o tamanho for igual, manter a ordem original
    return str1->original_index - str2->original_index;
}

int main() {
    int n;

    // Ler o número de casos de teste
    scanf("%d", &n);
    getchar(); // Consumir o caractere de nova linha após o número

    String palavras[50];
    int count = 0;

    while (n--) {
        char linha[2600]; // Buffer para ler a linha de entrada
        fgets(linha, sizeof(linha), stdin);

        char *token = strtok(linha, " \n");
        while (token != NULL) {
            strcpy(palavras[count].string, token);
            palavras[count].original_index = count;
            count++;
            token = strtok(NULL, " \n");
        }

        // Ordenar as palavras
        qsort(palavras, count, sizeof(String), compare);
    }

            // Imprimir as palavras ordenadas
    for (int i = 0; i < count; i++) {
        printf("%s", palavras[i].string);
        if (i < count - 1) {
            printf(" ");
        }
    }

    return 0;
}
