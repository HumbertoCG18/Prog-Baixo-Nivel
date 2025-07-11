#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int * numbers;
    int tamVet=10;
    int * ponteiro;

    printf("szof size_t: %d\n",sizeof(size_t));
    printf("szof *numbers: %d\n",sizeof(*numbers));
    printf("szof numbers: %d\n",sizeof(numbers));


    numbers = malloc(tamVet * sizeof(int));    
    for(int i=0; i<tamVet; i++)
        numbers[i]=i;

    while(1){
        ponteiro = realloc(numbers, 2*tamVet*sizeof(*numbers));
        for(int i=0; i<tamVet*2; i++){
            printf("[%02d]: %02d; ",i,ponteiro[i]);
            if(i<10)
                printf("[%02d]: %02d; ",i,numbers[i]);
            printf("\n");
        }
    }

    return 0;

    ponteiro = realloc(numbers, 2*tamVet*sizeof(*numbers));
    for(int i=0; i<tamVet*2; i++){
        printf("[%02d]: %02d; ",i,ponteiro[i]);
        if(i<10)
            printf("[%02d]: %02d; ",i,numbers[i]);
        printf("\n");
    }

    printf("-=-=-=-=-=-=-=-=-=-\n");

    for(int i=0; i<tamVet*2; i++)
        ponteiro[i]++;

    for(int i=0; i<tamVet*2; i++){
        printf("[%02d]: %02d; ",i,ponteiro[i]);
        if(i<10)
            printf("[%02d]: %02d; ",i,numbers[i]);
        printf("\n");
    }

    

    return 0;
}
