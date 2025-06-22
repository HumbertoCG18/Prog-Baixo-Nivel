#include <stdio.h>

void printVet(int *vet, int tam);
void swapVetA(int *, int);
void swapVetB(int *, int);

int main(){

    int vet1[] = {1,2,3,4,5,6,7,8,9,0};

    printf("O conteudo de vet1\n");
    printVet(vet1, 10);

    swapVetB(vet1, (sizeof(vet1)/sizeof(int)));

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

void swapVetA(int *vtSrc, int tamVet){
    for(int i=0; i<tamVet/2; i++){
        int aux=*(vtSrc+i);
        *(vtSrc+i)=*(vtSrc+tamVet-1-i);
        *(vtSrc+tamVet-1-i)=aux;
    }
}

void swapVetB(int *vtSrc, int tamVet){
    int *fimDoVet=(vtSrc+tamVet-1);
    for(int i=0; i<tamVet/2; i++){
        int aux=*vtSrc;
        *vtSrc=*fimDoVet;
        *fimDoVet=aux;
        vtSrc++;
        fimDoVet--;
    }
}

