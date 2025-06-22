#include <stdio.h>

int main()
{
    int vet[] = { 4, 9, 12 };
    int i, *ptr;
    ptr = vet;
    for(i =0; i<10; i++)
        printf("%d, %p - %d \n",i,ptr,*ptr++);
    printf ("\n");
    return 1;
}
