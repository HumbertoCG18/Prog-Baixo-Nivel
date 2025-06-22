#include <stdio.h>

typedef struct{
  char campo1;
  char campo2;
  int campo4;
} registro1;

typedef struct{
  char campo1;
  int campo2;
  double campo4;
} registro2;

typedef struct{
  char campo1;
  short campo3,campo6;
  double campo2,campo5;
} registro3;

int main(){

  printf("Resultados de sizeof\n");
  printf("  sizeof char:  %d\n",  sizeof(char));
  printf("  sizeof short: %d\n",  sizeof(short));
  printf("  sizeof int:   %d\n",  sizeof(int));
  printf("  sizeof float: %d\n",  sizeof(float));
  printf("  sizeof double: %d\n", sizeof(double));
  printf("  sizeof long: %d\n", sizeof(long));
  printf("  sizeof registro1: %d\n", sizeof(registro1));
  printf("  sizeof registro2: %d\n", sizeof(registro2));
  printf("  sizeof registro3: %d\n", sizeof(registro3));

  registro1 r;
  r.campo1=1;
  r.campo2=2;
  r.campo4=0x03040506;
  printf("  sizeof da variavel: %d\n", sizeof(r));
  printf("Explorando o conteudo da variavel r:\n");
  
  char * ptr = &r;

  for(int i=0; i<sizeof(r);i++){
    printf("  [%p]: %c/%d\n",ptr, *ptr, *ptr);
    ptr++;
  }
   


}
