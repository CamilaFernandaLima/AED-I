#include <stdio.h>

int main() {
    char entrada[51]; // Entrada com no máximo 50 caracteres + '\0'

    while (fgets(entrada, sizeof(entrada), stdin)) {
        long long numero = 0;
        int erro = 0; // Flag de erro
        int tem_digito = 0; // Flag para verificar se há pelo menos um número válido
        const long long LIMITE = 2147483647;

        for (int i = 0; entrada[i] != '\0' && entrada[i] != '\n'; i++) {
            char c = entrada[i];

            if (c == ' ' || c == ',') {
                continue; // Ignorar espaços e vírgulas
            } else if (c == 'O' || c == 'o') {
                c = '0';
            } else if (c == 'l') {
                c = '1';
            } else if (c < '0' || c > '9') {
                continue; // Ignorar qualquer outra letra ou caractere inválido
            }

            tem_digito = 1; // Pelo menos um número foi identificado
            numero = numero * 10 + (c - '0');

            if (numero > LIMITE) { // Overflow
                printf("error\n");
                goto proximo;
            }
        } 

        // Se não houver nenhum número válido, é um erro
        if (!tem_digito) {
            printf("error\n");
        } else {
            printf("%lld\n", numero);
        }
    proximo:;
    }

    return 0;
}
