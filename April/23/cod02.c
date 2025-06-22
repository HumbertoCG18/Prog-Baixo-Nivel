#include <stdio.h>
#include <stdlib.h>
#define SIZE 2000000000 // DOIS BilhÕES
int main()
{
    int i=1;
    int * ptr;
    int * aux;
    while(i<SIZE){
        //if(i==1)
            ptr=malloc(sizeof(int)*i);
        //else
        //    aux=realloc(ptr, i*sizeof(int));
        //printf("size[%zu] ptr=%p, aux=%p\n", i*sizeof(int), ptr, aux);
        printf("size[%zu] ptr=%p\n", i*sizeof(int), ptr);
        i+=1;
    }
}

