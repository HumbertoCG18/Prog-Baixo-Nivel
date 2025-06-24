#include <stdio.h>

void xuxu();
int calcula(int);
int calculaPtr(int*);
int somaDoisNumeros(int, int);
void troca(int, int);
void trocaRef(int*, int*);

int main(){
    printf("Olá mundo da programacao de baixo nivel\n");
    xuxu();
    int algo = 2;
    int resultado = calcula(algo);
    printf("%d - %d \n", algo, resultado);

    resultado = calculaPtr(&algo);
    printf("%d - %d \n", algo, resultado);
    //-=-=-=-=-=-=-=-
    int valorUm, valorDois;
    valorUm=10;
    valorDois=20;
    troca(valorUm, valorDois);
    printf("v1: %d; v2:%d\n", valorUm, valorDois);
    trocaRef(&valorUm, &valorDois);
    printf("v1: %d; v2:%d\n", valorUm, valorDois);
}

void xuxu(){
    printf("imprime xuxu\n");
}

int calcula(int valor){
    valor*=10;
    return valor;
}

int calculaPtr(int* valor){
    *valor = *valor * *valor;
    return *valor*10;
}

int somaDoisNumeros(int valorUm, int valorDois){
    return valorUm+valorDois;
}

void troca(int a, int b){
    int aux = a;
    a=b;
    b=aux;
}

void trocaRef(int* a, int* b){
    int aux = *a;
    *a=*b;
    *b=aux;
}












