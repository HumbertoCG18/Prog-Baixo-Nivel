#include <stdio.h>

//Zera todos os bits
unsigned int clear(unsigned int val);
//Seta um único bit
unsigned int setbit (unsigned int x, int bit);
//Resseta um único bit
unsigned int clearbit (unsigned int x, int bit);
//Inverte o valor de um único bit
unsigned int invertBit (unsigned int x, int bit);
//Retorna o estado de um determinado bit  (retorna 0 ou 1)
int testBit (unsigned int x, int bit);

void main(){

    unsigned int variavel = 1234;
    unsigned int resultado;
    resultado=clear(variavel);
    printf("O resultado da operacao sobre (%d) é (%d)\n", variavel, resultado);

    resultado=setbit(variavel, 0);
    printf("O resultado da operacao sobre (%d) é (%d)\n", variavel, resultado);
    resultado=setbit(variavel, 1);
    printf("O resultado da operacao sobre (%d) é (%d)\n", variavel, resultado);
    resultado=setbit(variavel, 2);
    printf("O resultado da operacao sobre (%d) é (%d)\n", variavel, resultado);
    resultado=setbit(variavel, 3);
    printf("O resultado da operacao sobre (%d) é (%d)\n", variavel, resultado);

    int bit=0;
    resultado=clearbit(variavel, bit); 
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=clearbit(variavel, bit);
    printf("O resultado da operacao clear sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);

    bit=0;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=invertBit(variavel, bit);
    printf("O resultado da operacao invertBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);

    bit=0;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);
    bit++;
    resultado=testBit(variavel, bit);
    printf("O resultado da operacao testBit sobre (%d) em (%d) é (%d)\n", variavel, bit, resultado);

    char valor=0;
    printf("O maior valor da variavel é: (%d)\n", ( (~valor) & (~(1 << ((sizeof(valor)*8)-1) )) ) & 0x000000ff   );
    printf("O menor valor da variavel é: (%d)\n", ( valor | (1<< ((sizeof(valor)*8)-1) ) ) | 0xffffff00 )  ;


}

unsigned int clear(unsigned int val){
    unsigned int result=val;
    // ALTERNATIVA 1
    result = result & 0;

    // ALTERNATIVA 2
    for(int i=0; i<sizeof(result)*8; i++)
      result= result & !(1<<i);

    // ALTERNATIVA 3
    result= result<<(sizeof(result)*8);

    // ALTERNATIVA 4
    result= result^result;

    return result;
}


unsigned int setbit (unsigned int x, int bit){
    unsigned int result=x;

    result = result | (1 << bit);

    return result;
}

unsigned int clearbit (unsigned int x, int bit){
    unsigned int result=x;

    result = result & ~(1 << bit);

    return result;
}


unsigned int invertBit (unsigned int x, int bit){
    unsigned int result=x;

    result = result ^ (1 << bit);

    return result;
}

int testBit (unsigned int x, int bit){
    unsigned int result=x;

    result = (result & (1 << bit)) >> bit;

    return result;
}
