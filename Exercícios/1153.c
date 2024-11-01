#include <stdio.h>

int fat(n){

    int fatorial;
    fatorial = n;

    for (int i=1; i<n; i++){
        fatorial = fatorial * (n-i);
    } 

    return fatorial;
}

int main(){
    int n, f;
    scanf("%i", &n);

    f = fat(n);
    printf("%i", f);

    return 0;
}