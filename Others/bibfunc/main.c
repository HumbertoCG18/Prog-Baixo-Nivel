#include <stdio.h>
#include "bibfunc.h"
#include "biboutra.h"

int main()
{
    int v;
    printf("Digite um valor: ");
    scanf("%d", &v);
    printf("Fatorial: %f\n", fatorial(v));
    printf("Somatório: %f\n", somatorio(v));
    printf("Teste: %f\n", teste(v));
}
 