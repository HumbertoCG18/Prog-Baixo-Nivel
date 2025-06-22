#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void inverte(int*, int);

int main(int argc, char * argv[]){

  int vet[TAM];

  for(int i=0; i<TAM; i++)
    vet[i]=i;

  for(int i=0; i<TAM; i++)
    printf("vet[%d]: %d\n",i,vet[i]);

  inverte(vet, TAM);

  printf("-=-=-=-=-=-=-=-=-=-=-\n");
  for(int i=0; i<TAM; i++)
    printf("vet[%d]: %d\n",i,vet[i]);

}

void inverte(int* v, int t) {
    for (int i = 0; i < t/2; i++) {
        int temp = *(v+i);
        *(v+i) = *(v+t-i-1);
        *(v+t-i-1) = temp;
    }
}
