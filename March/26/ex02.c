#include <stdio.h>

void printVet(int *vet, int tam);
void fillVetA(int *vtSrc, int *vtTgt, int tamVet);
void fillVetB(int *, int *, int);
void fillVetC(int *, int *, int);
void fillVetD(int *, int *, int);

int main(){

    int vet1[] = {1,2,3,4,5,6,7,8,9,0};
    int vet2[10];

    printf("O conteudo de vet1\n");
    printVet(vet1, 10);
    printf("O conteudo de vet2\n");
    printVet(vet2, 10);

    fillVetD(vet1, vet2, (sizeof(vet1)/sizeof(int)));

    printf("O conteudo de vet1\n");
    printVet(vet1, 10);
    printf("O conteudo de vet2\n");
    printVet(vet2, 10);

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

void fillVetA(int *vtSrc, int *vtTgt, int tamVet){
    while(tamVet>0){
        *vtTgt=*vtSrc;
        vtSrc++;
        vtTgt++;
        tamVet--;
    }
}

void fillVetB(int *vtSrc, int *vtTgt, int tamVet){
    for(int i=0; i<tamVet; i++)
        *(vtTgt+i)=*(vtSrc+i);
}

void fillVetC(int *vtSrc, int *vtTgt, int tamVet){
    while(tamVet--)
        *(vtTgt+tamVet)=*(vtSrc+tamVet);
}

void fillVetD(int *vtSrc, int *vtTgt, int tamVet){
    while(tamVet--)
        *(vtTgt++)=*(vtSrc++);
}

