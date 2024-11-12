#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char lista1[2000], lista2[2000];
    char amigo[200];

    gets(lista1);
    gets(lista2);
    gets(amigo);
    
    if (strcmp(amigo, "nao") == 0) {
        strcat(lista1, " ");
        strcat(lista1, lista2);  
        printf("%s\n", lista1);
    } else {
        char *p = strstr(lista1, amigo);

        // Se a palavra foi encontrada
        if (p != NULL) {
            // Calcula o ponto de inserção
            int antes = p - lista1;

            char resultado[4000];  

            //copia parte de lista1 antes de amigo
            strncpy(resultado, lista1, antes);
            resultado[antes] = '\0';
            
            // Adiciona lista2 antes da palavra 'amigo'
            strcat(resultado, lista2);

            // Adiciona o restante de lista1 após a palavra 'amigo'
            strcat(resultado, " ");
            strcat(resultado, lista1 + antes);

            // Imprime o resultado
            printf("%s", resultado);
        
        }
    }
    

    return 0;


}