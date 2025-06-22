#include <stdio.h>

typedef struct{
    int denominador;
    int numerador;
} Fracao;

void capturaValores(Fracao * fracao);
void imprimeFracao(Fracao fracao);
double calculaFracaoValor(Fracao fracao);
double calculaFracaoReferencia(Fracao * fracao);

void main(int argc, char* argv[]){
    /*
    printf("O número de argumentos passados foi %d\n", argc);
    for(int i=0; i<argc; i++)
      printf("  Argumento[%d]: %s\n", i, argv[i]);
    */
    Fracao edson;

    capturaValores(&edson);
    imprimeFracao(edson);

    printf("O resultado da operacao eh %f\n",calculaFracaoValor(edson));
    printf("O resultado da operacao eh %f\n",calculaFracaoReferencia(&edson));
}

void capturaValores(Fracao* fracao){
    printf("Informe o numerador: ");
    scanf("%d", &fracao->numerador);
    
    printf("Informe o denominador: ");
    scanf("%d", &fracao->denominador);    
}

void imprimeFracao(Fracao fracao){
    printf("O conteudo da estrutura de Fracao eh:\n");
    printf("  O valor do numerador eh:   %d\n", fracao.numerador);
    printf("  O valor do denominador eh: %d\n", fracao.denominador);
}

double calculaFracaoValor(Fracao fracao){
    int num, den;
    num=fracao.numerador;
    den=fracao.denominador;
    return (double) num/den;
}
double calculaFracaoReferencia(Fracao* fracao){
    int num, den;
    num=(*fracao).numerador;
    den=(*fracao).denominador;
    return (double) num/den;
}
