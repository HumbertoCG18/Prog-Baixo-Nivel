#include <stdio.h>
#define TAM 5

int main(){
    int vet[TAM];
    int i;

    for (i = 0; i < TAM; i++){
        vet[i] = i * 10;
    }

    for (i = 0; i < TAM; i++) {
        printf("Valor: %d, Endereco: %p\n", vet[i], &vet[i]);
    }

    return 0;
}