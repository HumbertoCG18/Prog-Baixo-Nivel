#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

int buscaValor(int*,int,int);

int main(int argc, char * argv[]){

  if(argc!=2){
    printf("Informe o número a ser pesquisado\n");
    return -1;
  }

  int valor = atoi(argv[1]);

  int vetor[TAMANHO];

  for(int i=0; i<TAMANHO; i++)
    vetor[i]=rand()%101;

  int posicao = buscaValor(vetor, TAMANHO, valor);

  if(posicao==-1)
    printf("O valor %d não foi encontrado no vetor\n", valor);
  else
    printf("O valor %d foi encontrado na posição %d do vetor\n", valor, posicao); 

}

int buscaValor(int *ponteiroParaOVetor, int tamanhoDoVetor, int valorBuscado){
  int resultado=-1, posicaoNoVetor=0;

  while(tamanhoDoVetor>0){

    if(*ponteiroParaOVetor==valorBuscado){
      resultado=posicaoNoVetor;
      break;
    }

    ponteiroParaOVetor++;
    posicaoNoVetor++;
    tamanhoDoVetor--;
  }
  return resultado;
}
