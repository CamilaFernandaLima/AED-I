#include <stdio.h>

int separa (int p, int r, int v[]){
    int c, j, k, t;
    c = v[r];
    j = p;

    for (k=p; k<r; k++){
        if(v[k] <=c){
            t = v[j];
            v[j] = v[k]; 
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void quicksort (int p, int r, int v[]){
    int j;
    if(p < r){
        j = separa (p,r,v);
        quicksort(p, j-1, v);
        quicksort(j+1, r, v);
    }
}
