#include <stdio.h>
#define SIZE 2000000 // DOIS milhÕES
int main()
{
    double array[SIZE];
    printf("tam. mem: %zu\n", sizeof(double)*SIZE);
    for(int i=0; i<SIZE; i++)
        array[i] = i;
}

