#include <stdio.h>

/**
 * @brief Imprime a representação binária de 8 bits de um unsigned char.
 * @param valor O byte a ser impresso.
 */
void ImprimeBits(unsigned char valor);

int main() {
    // Usando 170, que é 10101010 em binário.
    // O valor 12345 do enunciado causaria overflow.
    unsigned char i = 170; 

    printf("O valor decimal e: %d\n", i);
    printf("Sua representacao binaria e: ");
    ImprimeBits(i);
    printf("\n");

    return 0;
}

void ImprimeBits(unsigned char valor) {
    // A máscara começa com o bit mais significativo (MSB) ligado.
    // 128 em decimal é 10000000 em binário.
    // Poderia ser criado também com (1 << 7).
    unsigned char mascara = 128;
    int bit;

    // O laço executa 8 vezes, uma para cada bit.
    for (bit = 0; bit < 8; bit++) {
        
        // Aplica a máscara usando o 'E' bit a bit (&).
        // Se o bit correspondente em 'valor' também for 1, o resultado será não-zero.
        if ((valor & mascara) != 0) {
            putchar('1');
        } else {
            putchar('0');
        }

        // Desliza a máscara um bit para a direita para a próxima iteração.
        // 10000000 -> 01000000 -> 00100000 -> ...
        mascara = mascara >> 1;
    }
}