#include <stdio.h>
#include "bibfunc.h"

void main(){
    printf("Informe um valor positivo e maior do que zero: ");
    int val;
    scanf("%d", &val);
    printf("O fatorial de %d é %7.2f\n", val, fatorial(val));
    printf("O somatoria de %d é %7.2f\n", val, somatorio(val));
}