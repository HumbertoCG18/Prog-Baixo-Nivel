#include <stdio.h>

int main(){
    int x = 10;
    //4 bytes são alocados na memoria stack para x
    int *p;

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n\n", &x);
    p = &x;

    printf("Endereco para onde 'p' aponta: %p\n", p);
    printf("Endereco da variavel 'p' em si: %p\n\n", &p);

    printf("Valor no endereco apontado por 'p': %d\n", *p);

    *p = 25;
    printf("Novo valor de x: %d\n", x); // x agora vale 25

    return 0;
}