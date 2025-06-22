//
// Acessando parametros digitados na linha de comando
// (slides 69-73)
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    // argc e' a quantidade de parametros de linha de comando, 0 e' o nome do programa
    // argv e' um array de ponteiros para strings (cada uma e' um parametro)
    //
    // Rode o programa com: ./08_linha_de_comando teste de parametros na linha de comando
    
    for(int i=0; i<argc; i++)
        printf("%d: %s\n", i, argv[i]);
}

