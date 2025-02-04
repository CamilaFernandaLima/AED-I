#include <stdio.h>

void verificar(int a, int b, int c){
    int cat1 = b, cat2 = c, hip = a;
    if(b>hip){
        hip = b;
        cat1 = a;
    } 
    if(c>hip){
        hip = c;
        cat2 = a;
    }
    printf("%d %d %d", hip, cat1, cat2);
    
}

int main(){
    int a,b,c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    verificar(a,b,c);
}