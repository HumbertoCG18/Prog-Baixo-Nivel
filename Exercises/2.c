#include <stdio.h>
#include <string.h>

// Protótipo da função pedida no exercício
void imprime_string_custom(int *ptr_string);

int main() {
    // --- Montando um exemplo da string customizada na memória ---
    char buffer[100];
    char texto[] = "Teste";
    int tam = strlen(texto);

    // Coloca os 4 bytes do tamanho no início do buffer
    memcpy(buffer, &tam, sizeof(int));
    
    // Coloca os caracteres do texto logo após o tamanho
    memcpy(buffer + sizeof(int), texto, tam);
    
    printf("Testando a funcao de impressao:\n");
    
    imprime_string_custom((int *)buffer);
    printf("\n");

    return 0;
}

/**
 * @brief Imprime uma string no formato customizado (4 bytes de tamanho + dados).
 * @param ptr_int Um ponteiro para o início da estrutura (para o inteiro).
 */
void imprime_string_custom(int *ptr_int) {
    // Passo 1: Ler o tamanho.
    int tamanho = *ptr_int;

    // Passo 2: Achar o endereço do texto.
    char *ptr_char = (char *)(ptr_int + 1);
    
    int i; 

    printf("Tamanho: %d, Conteudo: ", tamanho);

    // Passo 3: Imprimir os caracteres.
    for (i = 0; i < tamanho; i++) {
        putchar(*ptr_char);
        ptr_char++;
    }
}