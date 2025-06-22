#include <stdio.h>

int swap(int* a, int*b);

void main(){

  int valor1, valor2;

  printf("Informe o primeiro valor: ");
  scanf("%d", &valor1);

  printf("Informe o segundo valor: ");
  scanf("%d", &valor2);

  if(swap(&valor1,&valor2))
    printf("Foi feita a troca: v1=%d e v2=%d\n",
           valor1,
           valor2);
  else
    printf("Não foi feita troca. V1 continua com o mmo valor (%d) e V2 tb (%d)\n",
           valor1, 
           valor2);
}

int swap(int* v1, int* v2){
  int aux;
  if(*v1>*v2){
    aux=*v1;
    *v1=*v2;
    *v2=aux;
    return 1;
  }
  return 0;
}
