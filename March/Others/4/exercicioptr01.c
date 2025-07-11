#include<stdio.h>
#include<stdlib.h>

int findValueA(int *, int, int);
int findValueB(int *, int, int);

int main(int argc, char * argv[]){
    
    int tamVet = atoi(argv[1]);
    int value  = atoi(argv[2]);

    int vet[tamVet];
    for(int i=0; i<tamVet; i++)
        vet[i]=i+1;

    int pos = findValueB(vet, tamVet, value);

    if(pos<0)
        printf("O valor %d não foi encontrado no vetor\n", value);
    else
        printf("O valor %d foi encontrado na posicao %d.\n", value, pos);
    
}

int findValueA(int * vet, int tamVet, int value){
    int idx=0;
    while(idx<tamVet){
        if((*(vet+idx))==value)
            return idx;
        idx++;
    }
    return -1;
}

int findValueB(int * vet, int tamVet, int value){
    int * ptr = vet;
    do{
        if(*ptr==value)
            return (ptr-vet);
    }while((++ptr)<(vet+tamVet));
    return -1;
}