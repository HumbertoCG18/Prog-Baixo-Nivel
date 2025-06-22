#include <stdio.h>

int main(){

  char c [10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  char *p = c;

  char y =c;
  printf("o valor de y eh %x\n", y);
  
  printf("O valor de p eh %p\n", p);
  printf("O valor de c eh %p\n", c);

  printf("O conteudo de *p eh %c\n", *p);
  printf("O conteudo de *c eh %c\n", c[0]);

  for(int i=0; i<10; i++)
    printf("iten[%d]; valor[%c]; endereco[%p]\n", i, c[i], &c[i]);

}
