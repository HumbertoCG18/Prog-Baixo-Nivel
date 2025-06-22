#include <stdio.h>

int main(){
  char a;
  unsigned char ua;
  int b;
  unsigned int ub;
  short int c;
  unsigned short int uc;
  long int d;
  unsigned long int ud;
  float f;
  double g;
  long double h;

  printf("szof char(%d); szof uchar(%d)\n", sizeof(a), sizeof(ua));
  printf("szof int(%d); szof uint(%d)\n", sizeof(b), sizeof(ub));
  printf("szof sint(%d); szof usint(%d)\n", sizeof(c), sizeof(uc));
  printf("szof lint(%d); szof ulint(%d)\n", sizeof(d), sizeof(ud));
  printf("szof float(%d); double(%d); ldouble(%d)\n", sizeof(f), sizeof(g), sizeof(h));

  char valor = 65;
  printf("valor = %d\n", valor);
  printf("valor = %u\n", valor);
  printf("valor = %x\n", valor);
  printf("valor = %f\n", valor);
  printf("valor = %c\n", valor);

  int v[10];
  for(int i=0; i<100; i++)
    printf("v[%d]= %d\n",i,v[i]);

  int x=0;
  while(1){
    printf("v[%d]= %d\n",x,v[x]);
    x++;
  }
    

}
