#include <stdio.h>

void printVet(int *vet, int tam);
void bubbleSort(int *, int);

int main(){

    int vet1[] = {9,8,7,6,5,4,3,2,1,0};

    printf("O conteudo de vet1\n");
    printVet(vet1, 10);

    bubbleSort(vet1, (sizeof(vet1)/sizeof(int)));

    printf("O conteudo de vet1\n");
    printVet(vet1, 10);

    return 0;
}

void printVet(int *vet, int tam){
    while (tam>0){
        printf("%d, ", *vet);
        vet++;
        tam--;
    }
    printf("\n");
}

void bubbleSort(int *vtSrc, int tamVet){
    int troca=1;
    while(troca){
        troca=0;
        int* ptr=vtSrc;
        while(ptr!=(vtSrc+tamVet-1)){
            if(*ptr>*(ptr+1)){
                int aux=*ptr;
                *ptr=*(ptr+1);
                *(ptr+1)=aux;
                troca=1;
            }
            ptr++;
        }
    }

}
