#include <stdio.h>
#include <stdlib.h>

int main(){
    int x;
    int a=0,b=0,c=0,d=0,e=0,f=0;
    

    for (int i=0; i<20; i++){
        x = (rand() % 6) + 1;

        switch (x){
        case 1: a += 1; break;
        case 2: b += 1; break;
        case 3: c += 1; break;
        case 4: d += 1; break;
        case 5: e += 1; break;
        
        default: f += 1; break;
        }
    }

    printf("1: %i vezes\n 2: %i vezes\n 3: %i vezes\n 4: %i vezes\n 5: %i vezes\n 6: %i vezes\n", a,b,c,d,e,f);

    return 0;

}