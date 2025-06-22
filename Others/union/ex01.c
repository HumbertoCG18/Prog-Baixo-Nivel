#include <stdio.h>
typedef union {
  char c[4];
  int i;
  float d;
} mytype;

int main(){
  mytype utype;

  utype.i=0x01010101;
  printf("Os valores em char %X %X %X %x\n", utype.c[3], utype.c[2], utype.c[1], utype.c[0]);
  printf("O valor no campo i eh: %d\n", utype.i);
  printf("O valor no campo d eh: %.50f\n", utype.d);

  utype.d=2.5;
  printf("Os valores em char %X %X %X %x\n", utype.c[3], utype.c[2], utype.c[1], utype.c[0]);
  printf("O valor no campo i eh: %d\n", utype.i);
  printf("O valor no campo d eh: %f\n", utype.d);
}

