#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Inicializa o gerador de nos. aleatórios
    int v = rand() % 100; // gera um número entre 0 e 99
    printf("%d\n", v);
}

