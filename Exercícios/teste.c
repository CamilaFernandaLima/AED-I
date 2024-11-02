#include <stdio.h>
#include <math.h>

int fat(int n){
    
    int fatorial = 1;

    for (int i=1; i<n; i++){
        fatorial = fatorial * i;
    } 

    return fatorial;
}

float soma(float x){

    float s = 1.0;
    float s1 = 0.0, s2 = 0.0;

    for (int i=3; i<42; i= i+4){
        s1= -(pow(x,i-1)/ fat(i));
    }
    for (int i=5; i<42; i= i+4){
        s2 += (pow(x,i-1)/ fat(i));
    }

    return s + s1 + s2;
}

int main(){
    float x;
    scanf("%f", &x);
    printf("%f", soma(x));

    return 0;
}