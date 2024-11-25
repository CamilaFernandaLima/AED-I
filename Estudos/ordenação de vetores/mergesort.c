//intercalação, algoritmo recursivo.
//divide o conjunto até que cada subconjunto possua 1 elemento.
//combina 2 subconjuntos para obter um maior e ordenado, até que exista apenas um conjunto contendo todos os elementos.

#include <stdio.h>

void intercala(int inicio, int meio, int fim, int v[]){
    int i, j, k, *w;
    w = malloc ((fim-inicio) * sizeof(int));
    i = inicio;
    j = meio;
    k = 0;
    while (i<meio && j<fim){
        if(v[i] <= v[j]){
            w[k++] = v[i++];
        } else{
            w[k++] = v[j++];
        }
    }
    while (i<meio) w[k++] = v[i++];
    while (j<fim) w[k++] = v[j++];

    for (i=inicio; i<fim; i++){
        v[i] = w[i-inicio];
    }
    free(w);
}

void mergesort(int *v, int inicio, int fim){
    int meio; 
    if (inicio<fim-1){
        meio = (inicio+fim)/2;

        //chama a função para as duas metades.
        mergesort(v, inicio, meio);
        mergesort(v, meio, fim);

        //intercala as duas metades ordenadas.
        intercala(inicio, meio, fim, v);
    }
}

