//
// Exemplos de uso das funcoes da biblioteca padrao para manipulacao de strings
// (slides 37-55)
//
#include <stdio.h>
#include <string.h> // para usar a biblioteca de funcoes para strings

int main()
{
    char str1[10], str2[10];

    //str1 = "abc" // NAO PODE!
    //str2 = str1; // NAO PODE!
    
    //char str1[10] = "abc"; // ISTO PODE, pois estamos inicializando ao mesmo tempo
    
    // Copiando uma string em outra: strcpy
    // CUIDADO! a funcao nao verifica se CABE!
    strcpy(str2, "abcd");  // a funcao acrescenta o \0 no final!

    // Copia str2 em str1 - mesmo cuidado acima!
    strcpy(str1, str2);

    // Mais seguro: strncpy - limita o tamanho, mas e' um pouco mais lenta
    strncpy(str1, str2, sizeof(str1));

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    // Descobrindo o comprimento de cada string: strlen
    printf("Tamanho de str1: %lu\n", strlen(str1));  // %lu: unsigned long
    printf("Tamanho de str2: %lu\n", strlen(str2));

    // Concatenando strings: strcat
    strcpy(str1, "abc");
    strcpy(str2, "def");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    strcat(str1, str2);  // concatena str1 com str2 => "abcdef"
    printf("Depois de strcat:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    // Comparando strings: strcmp
    // (MESMO comportamento do compareTo do Java)
    if(strcmp(str1, str2) < 0)
        printf("%s vem antes de %s\n", str1, str2);
    else if(strcmp(str1, str2) > 0)
        printf("%s vem depois de %s\n", str1, str2);
    else
        printf("%s e %s sao iguais!\n", str1, str2);
}

