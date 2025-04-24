#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SIZE 200000000 // dois milhões
int main()
{
    double* array = malloc(sizeof *array * SIZE);
    printf("tam. mem: %zu\n", sizeof *array * SIZE);
    int i;
    for(i=0; i<SIZE; i++)
        array[i] = i;
    free(array);
    printf("Liberada!\n");
}
