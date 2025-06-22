#include <stdio.h>
int main(){

  int b=200;
  int* a=&b;

  printf("Endereço de B: %p\n",&b);
  printf("Endereço de A: %p\n",&a);
  printf("Conteúdo de B: %d\n",b);
  printf("Conteúdo de A: %p\n",a);
  printf("Referência de A: %d\n",*a);

}
