#include <stdio.h>


void main(){
  long c[] = { 3, 2, 1, 4, 5, 6, 9, 8, 7, 10 };
  long * p=c;

  printf("  *p: %d\n", *p);    // exibe o primeiro elemento do array
  printf("p[0]: %d\n", p[0]);  // idem

  printf("    p: %p\n", p);     // exibe o endereço do primeiro elemento
  printf("    c: %p\n", c);     // idem
  printf("&c[0]: %p\n", &c[0]); // idem

  printf("&p: %p\n", &p);     // exibe o endereço do primeiro elemento
  printf("&c: %p\n", &c);     // idem

  printf("Acessando o vetor por indice\n");
  for(int i=0; i<10; i++)
    printf(" %d: %d\n", i, c[i]);

  printf("Acessando o vetor aritmetica de ponteiro\n");
  for(int i=0; i<10; i++)
    printf(" %p: %d\n", p+i, *(p+i));
}
