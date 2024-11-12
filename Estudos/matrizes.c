#include <stdio.h>
#include <stdlib.h>

/*int main(){

    int i,j;
    int matriz[3][3];

    printf("Digite os números da matriz 3x3: \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}*/

int main(){
    int i;
    int nomes[3][30];

    printf("Entre com os nomes: \n");
    for(i=0;i<3;i++){ 
        scanf("%s", &nomes[i]);
    }

    for(i=0;i<3;i++){
        printf("\nO nome %d eh: ", i+1);
        printf("%s ", nomes[i]);
    }
    

    return 0;
}