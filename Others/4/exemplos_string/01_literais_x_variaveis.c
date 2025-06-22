//
// Entendendo as diferencas entre literais (constantes) e variaveis string
// (slides 1-22)
//
#include <stdio.h>
#define TAM 30     // constante para o tamanho maximo da string

int main()
{
    char* frase1      = "Esta e' uma frase.";        // literal (constante)
    char  frase2[TAM] = "Esta tambem e' uma frase."; // array (com 30 posicoes, 29 podem ser usadas)
    char  frase3[]    = "E esta e' outra frase.";    // array (com exatamente o tamanho do texto + 1)

    printf("%s\n", frase1);
    printf("%s\n", frase2);
    printf("%s\n", frase3);

    // As variaveis podem ser alteradas, o literal NAO!
    frase2[3] = 'e';  // troca 'a' por 'e'
    frase3[14] = 'o'; // troca 'a' por 'o'
    //frase1[3] = 'e'; // NAO PODE! Comportamento indefinido!
    //frase1 = "Uma nova frase elaborada pelo Edson";
    frase1 = frase2;
    frase1[0]='e';
    
    printf("\nApos alteracao:\n\n");
    printf("%s\n", frase1);
    printf("%s\n", frase2);
    printf("%s\n", frase3);
}

