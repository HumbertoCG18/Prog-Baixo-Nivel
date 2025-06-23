#include <stdio.h>

void mult(int *px){
    *px = *px * 2;
}

int main(){
    int v = 10;

    mult(&v);

    printf("Valor de V Depois da funcao: %d\n", v);
    return 0;
}