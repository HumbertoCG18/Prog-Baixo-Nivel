//
// Formas para declarar arrays de strings (usando uma matriz de char ou um ragged array)
// (slides 64-68)
//
#include <stdio.h>
#include <string.h>

int main()
{
    // Numero de linhas pode ser omitido, mas nao de caracteres por linha
    // O impacto disso e' que estamos declarando efetivamente uma MATRIZ
    // de caracteres, com 9 linhas e 8 colunas (e varios espacos nao usados - slide 65)
    char planets1[][8] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                         "Uranus", "Neptune", "Pluto" };

    // Segunda forma: declaramos um array de PONTEIROS para strings:
    // Ou seja, cada elemento e' um ponteiro que aponta para o inicio de uma string
    // (chamamos isso de "ragged array" - slide 67)
    char* planets2[] =  { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto" };


    printf("planets1: cada linha ocupa exatamente 8 bytes\n");
    for(int i=0; i<9; i++)
        printf("planets1[%d]: %p - %s\n", i, planets1[i], planets1[i]); 

    printf("\nplanets2: cada linha ocupa o espaco necessario para o nome do planeta\n");
    for(int i=0; i<9; i++)
        printf("planets2[%d]: %p - %s\n", i, planets2[i], planets2[i]); 
}

