#include <stdio.h>
// Esta função deve somar os valores dos parâmetros a e b e colocar o
// resultado em result.
void soma(float a, float b, float * result){
    *result=a+b;
}
// Somar os valores dos parâmetros V1 e V2 através
// da chamada da função SOMA e somar 1 ao resultado obtido.
// O resultado desta soma deve ser retornado no terceiro
// parâmetro da função.
void somaEIncrementa(float V1, int V2, float * V3)
{
    soma(V1,V2,V3);
    *V3+=1;
}
int main()
{
  float c=99;
  float x=3;
  float y=4;
  soma(x,y,&c);
  printf("A soma de %f com %f é %f\n", x, y, c);
  somaEIncrementa(10, 11, &c);
  printf("A soma com incremento é %f\n", c);
  return 0;
}
