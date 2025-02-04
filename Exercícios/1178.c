#include <stdio.h>

int main(){
    float x, y, v[100];
    scanf("%f", &x);
    v[0] = x;

    for(int i = 0; i<100; i++){
        if(i>0){
            v[i] = v[i-1]/2;
        }
        printf("N[%d] = %.4f\n", i, v[i]);
    }
    
    return 0;
}