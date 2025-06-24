/* Escreva uma função para um caixa de banco, que recebe um valor inteiro R e determina o número de notas de 100, 50, 10, 5 e 1 reais necessário para pagar a quantia R . Faça de forma que o número de notas usado seja o menor possível, retornando as quantidades de notas por referência. */

#include <stdio.h>

void saqueCash(int, int*,int*,int*,int*,int*);
void imprimeDistribuicao(int v, int n100, int n50, int n10, int n5, int n1);

int main(){

    int nota100, nota50, nota10, nota5, nota1;
    int valor=100;
    saqueCash(valor, &nota100,&nota50, &nota10, &nota5, &nota1);
    imprimeDistribuicao(valor, nota100, nota50, nota10, nota5, nota1);

    valor=166;
    saqueCash(valor, &nota100,&nota50, &nota10, &nota5, &nota1);
    imprimeDistribuicao(valor, nota100, nota50, nota10, nota5, nota1);

    valor=1234;
    saqueCash(valor, &nota100,&nota50, &nota10, &nota5, &nota1);
    imprimeDistribuicao(valor, nota100, nota50, nota10, nota5, nota1);

    valor=9478;
    saqueCash(valor, &nota100,&nota50, &nota10, &nota5, &nota1);
    imprimeDistribuicao(valor, nota100, nota50, nota10, nota5, nota1);}

void imprimeDistribuicao(
    int v, 
    int n100, 
    int n50, 
    int n10, 
    int n5, 
    int n1
){
    printf("\n-=-=-=-=-=-=-=-\n");
    printf("A distribuição de notas para o valor %d e':\n",v);
    printf("  Notas de 100: %d\n", n100);
    printf("  Notas de  50: %d\n", n50);
    printf("  Notas de  10: %d\n", n10);
    printf("  Notas de   5: %d\n", n5);
    printf("  Notas de   1: %d\n", n1);
}

void saqueCash(
    int valorDoSaque,
    int *n100,
    int *n50,
    int *n10,
    int *n5,
    int *n1
){

  *n100=valorDoSaque/100;
  int valorRestante = valorDoSaque-(*n100*100);

  *n50=valorRestante/50;
  valorRestante-=(*n50*50);

  *n10=valorRestante/10;
  valorRestante-=(*n10*10);

  *n5=valorRestante/5;
  valorRestante-=(*n5*5);

  *n1 = valorRestante;

}