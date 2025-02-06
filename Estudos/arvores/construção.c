#include <stdio.h>
#include <stdlib.h>

//normalmente nao tem cabeça, porque a raiz já possui um valor
//fazer 1195
//3134

struct cel{
    int conteudo;
    struct cel *esq;
    struct cel *dir;
} no;