#include <stdio.h>

typedef struct{
    char valor;
}Tristate;


void set(Tristate * t){
    t->valor='V';
}

void reset(Tristate * t){
    (*t).valor='F';
}

void dontknow(Tristate * t){
    (*t).valor='I';
}

char get(Tristate t){
    return t.valor;
}

int main(int argc, char const *argv[])
{
    Tristate A;

    printf("O valor de A é %c\n", get(A));

    set(&A);
    printf("O valor de A é %c\n", get(A));

    reset(&A);
    printf("O valor de A é %c\n", get(A));

    dontknow(&A);
    printf("O valor de A é %c\n", get(A));


    return 0;
}
