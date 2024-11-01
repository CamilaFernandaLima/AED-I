#include <stdio.h>

int main(){

    int n, fatorial;
    fatorial = n;

    for (int i=1; i<n; i++){
        fatorial = fatorial * (n-i);
    } 

    printf("%i", fatorial);

    return 0;
}