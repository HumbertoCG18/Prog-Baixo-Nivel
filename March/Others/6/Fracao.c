#include <stdio.h>

typedef struct{
    char letraA;
    int denominador, numerador;
    char letraB;
} Fracao;

int calculaPorValor(Fracao);
int calculaPorReferenciaA(Fracao*);
int calculaPorReferenciaB(Fracao*);
void dissecarEstrutura(Fracao *);

int main(int argc, char const *argv[])
{
    Fracao teste;
    teste.letraA='A';
    teste.letraB='B';
    teste.denominador=2;
    teste.numerador=10;

    printf("V : A divisao de %d por %d eh %d\n", 
        teste.numerador, 
        teste.denominador, 
        calculaPorValor(teste));

    printf("RA: A divisao de %d por %d eh %d\n", 
        teste.numerador, 
        teste.denominador, 
        calculaPorReferenciaA(&teste));

    printf("RB: A divisao de %d por %d eh %d\n", 
        teste.numerador, 
        teste.denominador, 
        calculaPorReferenciaB(&teste));

    printf("-=-=-=-=-=\n");
    dissecarEstrutura(&teste);


    return 0;
}

int calculaPorValor(Fracao f){
    return f.numerador/f.denominador;
}

int calculaPorReferenciaA(Fracao *f){
    return (*f).numerador/(*f).denominador;
}

int calculaPorReferenciaB(Fracao *f){
    return f->numerador/f->denominador;
}

void dissecarEstrutura(Fracao *f){
    printf("Tamanho da *Fracao: %d\n", sizeof(f));
    printf("Tamanho da  Fracao: %d\n", sizeof((*f)));

    printf("ptr int\n");
    int * ptrInt = (int *) f;
    int size=sizeof(Fracao)/sizeof(int);
    while(size)
        printf("%d: %d\n", size--, *ptrInt++);
    
    printf("ptr char\n");
    char * ptrChar = (char *) f;
    size=sizeof(Fracao)/sizeof(char);
    while(size)
        printf("%d: %d\n", size--, *ptrChar++);

}