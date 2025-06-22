//
// Exemplos de exibicao de strings na tela
// (slides 23-27)
//
#include <stdio.h>

int main()
{
    char str[] = "Escrevendo strings";
    printf("%s\n", str);
    printf("%.10s\n", str);     // Apenas primeiras 10 letras
    printf("[%30s]\n", str);    // Ocupando 30 caracteres, alinhado a direita
    printf("[%-30s]\n", str);   // Ocupando 30 caracteres, alinhado a esquerda
    printf("[%30.10s]\n", str); // Combinando os dois modificadores
    puts(str);                  // Mais simples para escrever toda a string + nova linha
}

