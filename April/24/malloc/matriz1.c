#include <stdio.h>
#include <stdlib.h>

// "Matriz" 5x5 alocada contiguamente, como vetor de 25 posições
int main()
{
    int* mat = malloc(5 * 5 * sizeof *mat);
    for (int i=0; i<25; i++)
        mat[i] = i;
    printf("Feito.\n");
    free(mat);
}

