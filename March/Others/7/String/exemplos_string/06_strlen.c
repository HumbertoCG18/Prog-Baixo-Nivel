//
// Encontrando o final de uma string: diversas implementacoes da funcao strlen
// (slides 56-63)
//
#include <stdio.h>
#include <string.h>

// size_t geralmente equivale a unsigned long
size_t strlen1(const char* s);
size_t strlen2(const char* s);
size_t strlen3(const char* s);
size_t strlen4(const char* s);
size_t strlen5_chuck_norris(const char* s);

int main()
{
    char* frase = "Uma frase tao boa quanto qualquer outra";
    printf("Frase: %s\n", frase);
    printf("Comprimento (1): %lu\n", strlen1(frase));
    printf("Comprimento (2): %lu\n", strlen2(frase));
    printf("Comprimento (3): %lu\n", strlen3(frase));
    printf("Comprimento (4): %lu\n", strlen4(frase));
    printf("Comprimento (Chuck Norris): %lu\n", strlen5_chuck_norris(frase));
}

size_t strlen1(const char* s) {
    size_t n = 0;
    for(; *s != '\0'; s++)
        n++;
    return n;
}

size_t strlen2(const char* s) {
    size_t n = 0;
    for(; *s; s++) // *s e' o mesmo que *s != '\0'!
        n++;
    return n;
}

size_t strlen3(const char* s) {
    size_t n = 0;
    // Usando pos-incremento e aritmetica de ponteiros:
    // testa *s e logo em seguida avanca a posicao
    for(; *s++; )
        n++;
    return n;
}

size_t strlen4(const char* s) {
    size_t n = 0;
    // Trocando for por while (nao faz mais sentido usar for)
    while(*s++)
        n++;
    return n;
}

size_t strlen5_chuck_norris(const char* s) {
    // Chuck Norris nao precisa de contadores, apenas ponteiros...
    const char* p = s;
    while(*s)
        s++;
    return s - p;
}

