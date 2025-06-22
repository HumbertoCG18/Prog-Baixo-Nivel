#include <stdio.h>

int main(){

    int valor1, valor2;
    printf("Digite dois valores: ");

    scanf("%d %d", &valor1, &valor2);

    printf("O primeiro valor digitado foi %d\n", valor1);
    printf("O segundo valor digitado foi %d\n", valor2);
    printf("Ou seja, os valores foram %d e %d\n", valor1, valor2);

}