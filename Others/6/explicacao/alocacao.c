#include <stdlib.h>
#include <stdio.h>

int main()
{
    int * ptr;
    int a=1;
    ptr=&a;
    while(1){
        ptr=malloc(sizeof(int));
        free(ptr);
    }
}