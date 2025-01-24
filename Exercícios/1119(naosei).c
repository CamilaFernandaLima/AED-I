#include <stdio.h>

int main(){
    int n, k, m, cont1 = 0;
    int vetor1[100][100];
    int vetor2[100][100];
    scanf("%d %d %d", &n, &k, &m);
    int cont2 = n;

    for(int i = 0; cont1<n; i++){
        cont1 += k;
        vetor1[1][i] = cont1;
        printf("%d ", vetor1[1][i]);
    }
    for(int j = 0; cont2<n; j++){
        cont2 -= k;
        vetor2[1][j] = cont2;
        printf("%d ", vetor2[1][j]);
    }


    return 0;
}