#include <stdio.h>
#include <stdlib.h>

#define TAM_V1 10
#define TAM_V2 TAM_V1

void copiaDeVetores(int*,int*,int);

int main(int argc, char * argv[]){

  int vet_um[TAM_V1];

  for(int i=0; i<TAM_V1; i++)
    vet_um[i]=rand()%101;

  int vet_dois[TAM_V2];
  for(int i=0; i<TAM_V1; i++)
    printf("v1[%d]: %d <-> %d: [%d]v2\n",i,vet_um[i],vet_dois[i],i);

  copiaDeVetores(vet_um, vet_dois, TAM_V1);

  printf("-=-=-=-=-=-=-=-=-=-=-\n");
  for(int i=0; i<TAM_V1; i++)
    printf("v1[%d]: %d <-> %d: [%d]v2\n",i,vet_um[i],vet_dois[i],i);



}

void copiaDeVetores(int* vOrigem, int* vDestino, int tam){
//  while(tam--)
//    *vDestino++ = *vOrigem++;

  while(tam--){
    *vDestino = *vOrigem;
    vDestino++;
    vOrigem++;
  }

}
