#include <stdio.h>
#include <stdlib.h>

// "Matriz" 5x5 alocada diretamente (C99 em diante)
int main()
{
    int cols = 8, linhas = 5;
    int (*mat)[cols] = malloc(linhas * sizeof *mat);

    int cont = 0;
    for(int i=0; i<linhas; i++)
        for(int j=0; j<cols; j++)
            mat[i][j] = cont++;
    printf("Feito.\n");

    // Liberando...
    free(mat);
}

