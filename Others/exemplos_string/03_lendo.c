//
// Exemplos de leitura de strings (usando scanf e fgets)
// (slides 28-32)
//
#include <stdio.h>
#define TAM 10

int main()
{
    char frase[TAM];

    // Diferenca entre scanf e fgets:

    printf("Frase:");
    scanf("%s", frase); // frase ja' e' ponteiro
    printf("Voce digitou (scanf): %s\n", frase);

    // O que acontece se voce comentar a proxima linha?
    fgets(frase, TAM-1, stdin); // "pula" o ENTER

    printf("Frase:");
    fgets(frase, TAM-1, stdin);
    printf("Voce digitou (fgets): %s\n", frase);
}

