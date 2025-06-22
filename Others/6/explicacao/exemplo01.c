#include <stdio.h>
#define SIZE 1100000 // um milhão
int main()
{
    printf("aqui 01 \n");
    double array[SIZE];
    printf("tam. mem: %zu\n", sizeof(double)*SIZE);
    for(int i=0; i<SIZE; i++)
        array[i] = i;
}