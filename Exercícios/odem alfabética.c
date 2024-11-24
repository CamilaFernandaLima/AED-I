#include <stdio.h>
#include <string.h>

char nome[10][80];

void ordena(){
    int x,y,r;
    char aux[80];
    for(x=0; x<10; x++){
        for(y=x+1; y<10; y++){
            r = strcmp(nome[x], nome[y]);
            if(r>0){
                strcpy(aux, nome[x]);
                strcpy(nome[x], nome[y]);
                strcpy(nome[y], aux);
            }
        }
    }
}

int main(){
    int i;
    for(i=0; i<10; i++){
        gets(nome[i]);
    }

    ordena();
    
    printf("\n");
    for (i=0; i<10; i++){
        printf("%s\n", nome[i]);
    }
}