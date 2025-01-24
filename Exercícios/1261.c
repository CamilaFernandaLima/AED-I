#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[16];
    int valor;
} funcao;

int main(){
    int n,m;
    scanf("%d %d", &m, &n);

    funcao funcoes[m];

    for(int i=0; i<m; i++){
        scanf("%s %d", funcoes[i].nome, &funcoes[i].valor);
        getchar();
    }

    for (int i=0; i<n; i++){
        char linha[100000];
        int salario = 0;

        while(1){
            fgets(linha, sizeof(linha), stdin);
            linha[strcspn(linha, "\n")] = 0;

            if(strcmp(linha, ".") == 0){
                break;
            }           

            char *token = strtok(linha, " ");
            while(token != NULL){
                for(int j=0; j<m; j++){
                    if(strcmp(token, funcoes[j].nome) == 0){
                        salario += funcoes[j].valor;
                        break;
                    }
                }
                token = strtok(NULL, " ");
            }
        }
        printf("%d\n", salario);
    }
    return 0;
}