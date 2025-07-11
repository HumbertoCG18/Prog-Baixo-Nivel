#include <stdio.h>


void main(){
  char c[10] = {'a','b','c','d','e','f','g','h','i','j'};
  char * p=c;

  printf("  *p: %c\n", *p);    // exibe o primeiro elemento do array
  printf("p[0]: %c\n", p[0]);  // idem

  printf("    p: %p\n", p);     // exibe o endereço do primeiro elemento
  printf("    c: %p\n", c);     // idem
  printf("&c[0]: %p\n", &c[0]); // idem

  printf("&p: %p\n", &p);     // exibe o endereço do primeiro elemento
  printf("&c: %p\n", &c);     // idem

  printf("Acessando o vetor por indice\n");
  for(int i=0; i<10; i++)
    printf(" %d: %c\n", i, c[i]);

  printf("Acessando o vetor aritmetica de ponteiro\n");
  for(int i=0; i<10; i++)
    printf(" %p: %c\n", p+(sizeof(char))*i, *(p+i));
}
