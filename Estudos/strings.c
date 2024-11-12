// Strings (principais funções):

// strcat (dest, orig) - concatena orig no final de dest
// strncat (dest, orig, n) - n é numero max de caracteres para concatenar
// strcmp (str1, str2) - compara retorna 0 (iguais), menor que 0 (str1<str2), maior que 0 (str1>str2)
// strlen (str) - calcula o comprimento
// strcpy (dest, orig) - copia cadeia orig para dest
// strncpy (dest, orig, qte)

// função gets(var) - armazena valor direto na string var

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char nome[50], sobrenome[50];
    int comp1, comp2;

    printf("digite seu nome: ");
    scanf("%s", &nome);
    comp1 = strlen(nome);

    printf("digite seu sobrenome: ");
    scanf("%s", &sobrenome);
    comp2 = strlen(sobrenome);

    strcat (nome, " ");
    strcat(nome, sobrenome);

    printf("%s %i %i", nome, comp1, comp2);
    
    return 0;
    
}