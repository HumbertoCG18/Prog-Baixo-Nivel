#include <stdio.h>
#include "matematica.h"
#include "fazOSomatorio.h"
#include "fazOFatorial.h"

int main(int argc, char const *argv[])
{

    int valor;
    printf("Informe um valor decimal: ");
    scanf("%d", &valor);
    
    fazOSomatorio(valor);
    printf("No principal: O somatorio de %d é : %f\n",valor, somatorio(valor));
    fazOFatorial(valor);
    printf("No principal: O fatorial de %d é : %f\n",valor, fatorial(valor));

    return 0;
}
