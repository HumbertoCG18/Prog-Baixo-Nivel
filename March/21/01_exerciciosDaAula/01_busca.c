#include <stdio.h>

int busca(int valorBuscado, int* vetorDeBusca, int tamanhoDoVetor);

int main(){	
  int vetor[] = {1,2,3,4,5,7,9,10,11,12,14,15,23};
  int valor;
  
  do{
	printf("Informe um número a ser pesquisado (0 para sair): ");
	scanf("%d", &valor);
	if(valor!=0){
	  int posicao=busca(valor, vetor, (sizeof(vetor)/sizeof(*vetor)) );
	  if(posicao==-1)
		printf("O valor %d não está presente no vetor\n", valor);
	  else
		printf("O valor %d está na posicao %d\n", valor, posicao);
	}
  }while(valor!=0);	
  printf("Fim do programa\n");	
}

int busca(int valorBuscado, int* vetorDeBusca, int tamanhoDoVetor){
// PROPOSTA 1
/*
  for(int i=0; i<tamanhoDoVetor; i++)
    if(  (*(vetorDeBusca+i)) == valorBuscado ) return i;
*/

//PROPOSTA 2
  int *ptr=vetorDeBusca;
  while( (ptr < (vetorDeBusca+tamanhoDoVetor)) ){	  
	  if(*ptr==valorBuscado)
		return (ptr-vetorDeBusca);				
	  ptr++;	  
  }
  return -1;
}
