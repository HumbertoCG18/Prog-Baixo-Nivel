//
// Exemplos de leitura de strings (usando scanf e fgets)
// (slides 28-32)
//
#include <stdio.h>

int main()
{
    char frase[80];

    // Diferenca entre scanf e fgets:

    printf("Frase:");
    scanf("%s", frase); // frase ja' e' ponteiro
    printf("Voce digitou (scanf): %s\n", frase);

    // O que acontece se voce comentar a proxima linha?
    fgets(frase, 79, stdin); // "pula" o ENTER

    printf("Frase:");
    fgets(frase, 79, stdin);
    printf("Voce digitou (fgets): %s\n", frase);
}

