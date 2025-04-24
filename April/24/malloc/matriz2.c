#include <stdio.h>
#include <stdlib.h>

// "Matriz" 5x5 alocada com array de linhas e depois colunas
int main()
{
    int** mat = malloc(5 * sizeof (int*));

    for (int i=0; i<5; i++)
        mat[i] = malloc(5 * sizeof (int));

    int cont = 0;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            mat[i][j] = cont++;
    printf("Feito.\n");

    // Liberando...
    for(int i=0; i<5; i++)
        free(mat[i]);
    free(mat);
}

