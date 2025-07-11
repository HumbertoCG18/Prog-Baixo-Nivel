#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    //
    int * numbers;
    int tamVet=100;

    printf("szof size_t: %d\n",sizeof(size_t));
    printf("szof *numbers: %d\n",sizeof(*numbers));
    printf("szof numbers: %d\n",sizeof(numbers));
/*
    numbers = malloc(tamVet * sizeof(int));    
    for(int i=0; i<tamVet; i++)
        printf("[%04d]: %d\n",i,numbers[i]);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    numbers = malloc(tamVet * sizeof(*numbers));
    for(int i=0; i<tamVet; i++)
        printf("[%04d]: %d\n",i,numbers[i]);

    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    numbers = calloc(tamVet, sizeof(*numbers));
    for(int i=0; i<tamVet; i++)
        printf("[%04d]: %d\n",i,numbers[i]);
*/
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    int limpo=1;
    int count=1;
    do{
        int idx=0;
        printf("Alocação %d\n",count++);
        numbers = malloc(tamVet * sizeof(*numbers));
        for(int i=0; i<tamVet; i++){
            if(numbers[i]!=0){
                limpo=0;
                idx=i;
            }
            numbers[i]^=numbers[i];
        }

        if(limpo==0){
            printf("[%02d]: %d\n",idx,numbers[idx]);
        }

        free(numbers);

    }while(limpo);

    return 0;
}
