#include <stdio.h>

struct Fracao{
  int numerador, denominador;
};

float calculaPorValor(struct Fracao f);
float calculaPorReferencia(struct Fracao* f);


int main(){

  struct Fracao minhaFracao;

  printf("Informe o numerador: ");
  scanf("%d", &minhaFracao.numerador);

  printf("Informe o denominador: ");
  scanf("%d", &minhaFracao.denominador);

  printf("O resultado (por valor) eh %05.2f\n", calculaPorValor(minhaFracao));
  printf("O resultado (por refer) eh %05.2f\n", calculaPorReferencia(&minhaFracao));

}

float calculaPorValor(struct Fracao f){
  
  return ((float) f.numerador)/f.denominador;
}

float calculaPorReferencia(struct Fracao* f){
  return ((float)f->numerador)/(*f).denominador;
}


