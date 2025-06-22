#include <stdio.h>

typedef struct {
    char status;
} Tristate;

void set(Tristate *bit);
void reset(Tristate *bit);
void dontknow(Tristate *bit);
char get(Tristate bit);

void main(){
    Tristate meubit;

    printf("O conteudo do bit é: %c \n", get(meubit) );

    set(&meubit);
    printf("O conteudo do bit é: %c \n", get(meubit) );

    reset(&meubit);
    printf("O conteudo do bit é: %c \n", get(meubit) );

    dontknow(&meubit);
    printf("O conteudo do bit é: %c \n", get(meubit) );
}

void set(Tristate *bit){
    (*bit).status='V';
}
void reset(Tristate *bit){
    bit->status='F';
}
void dontknow(Tristate *bit){
    (*bit).status='I';
}

char get(Tristate bit){
    return bit.status;
}

