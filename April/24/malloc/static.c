#include <stdio.h>

#define SIZE 2000000 // um milhão

int main()
{
    double array[SIZE];
    printf("tam. mem: %zu\n", sizeof(double)*SIZE);
    int i;
    for(i=0; i<SIZE; i++)
        array[i] = i;
}
