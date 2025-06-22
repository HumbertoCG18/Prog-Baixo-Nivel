#include <stdio.h>
#include <stdlib.h>
//#include <time.h>

int main(){

    int vet[10];
//    srand(time(NULL));

    for(int i=0; i<10; i++)
      vet[i]=rand()%101;

    for(int i=0; i<10; i++)
      printf("vet[%d]: d=%d; x=%x;\n",i,vet[i],vet[i]);

    int count=0;
    for(int i=0; i<10; i++)
      if(vet[i]%2==1) count++;
    printf("O vetor possuir %d nros impares\n",count);

}
