#include <stdio.h>

int main(){

  int b=200;
  int * a;
  int * c;

  a = &b;

  printf("O endereço de B eh %p\n", &b);
  printf("O endereço de B por a eh %p\n", a);
  printf("O valor de B eh %d\n", b);
  printf("O valor de B por a eh %d\n", *a);
  printf("O endereço de A eh %p\n", &a);
  
  printf("O endereço de c é %p\n", &c);
  printf("O conteudo de c é %p\n", c);
  printf("O conteudo apontador por c é %d\n", *c);

}
