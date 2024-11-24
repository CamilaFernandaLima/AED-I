#include <stdio.h>
#include <string.h>

int n;

void ordena(char nome[][30]){
    int x,y,r;
    char aux[80];
    for(x=0; x<n; x++){
        for(y=x+1; y<n; y++){
            r = strcmp(nome[x], nome[y]);
            if(r>0){
                strcpy(aux, nome[x]);
                strcpy(nome[x], nome[y]);
                strcpy(nome[y], aux);
            }
        }
    }
}

int main() {

    int k;
    
    scanf("%d", &n);
    scanf("%d", &k);

    char nome[n][30];

    for(int i=0; i<=n; i++){
        fgets(nome[i], sizeof(nome[i]), stdin);
        nome[i][strcspn(nome[i], "\n")] = 0;
    }

    ordena(nome);

    printf("%s\n", nome[k]);

    return 0;
}