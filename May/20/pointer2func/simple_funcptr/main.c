#include <stdio.h>
#include <stdlib.h>

void troca(int* x, int* y);

int main()
{
    void (*fptr)(int* x, int* y);

    fptr = troca;
    int a = 1;
    int b = 2;

    printf("%d %d\n",a,b);

    fptr(&a,&b);

    printf("%d %d\n",a,b);
}

void troca(int* x, int* y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}
