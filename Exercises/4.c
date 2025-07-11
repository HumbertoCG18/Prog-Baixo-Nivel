#include <stdio.h>
#include <string.h> 

// Variáveis globais
char Memoria[1000];
char *PosicaoLivre;

// Protótipos das suas funções
void ArmazenaINT(int *dado);
void ArmazenaFLOAT(float *dado);
void ArmazenaCHAR(char *dado);

int main() {
    // Inicializa o ponteiro para apontar para o início da nossa memória.
    PosicaoLivre = Memoria; // ou &Memoria[0]

    int A = 12345;
    float F = 98.76;
    char C = 'X';
    
    printf("PosicaoLivre inicial: %p\n", PosicaoLivre);

    ArmazenaINT(&A);
    ArmazenaFLOAT(&F);
    ArmazenaCHAR(&C);
    
    return 0;
}

void ArmazenaFLOAT(float *dado) {
    // Passo 1: Copiar os bytes do float para a PosicaoLivre.
    // memcpy(destino, origem, quantidade_de_bytes);
    memcpy(PosicaoLivre, dado, sizeof(float));
    
    // Passo 2: Atualizar a PosicaoLivre.
    PosicaoLivre = PosicaoLivre + sizeof(float);
    
    printf("FLOAT armazenado. Nova PosicaoLivre: %p\n", PosicaoLivre);
}

void ArmazenaINT(int *dado) {
    // FASE 1: Encontrar o endereço alinhado.
    while ((PosicaoLivre - Memoria) % 4 != 0) {
        PosicaoLivre++;
    }

    // FASE 2: Armazenar o dado na posição encontrada.
    memcpy(PosicaoLivre, dado, sizeof(int));
    PosicaoLivre = PosicaoLivre + sizeof(int); // Atualiza para a próxima posição livre

    printf("INT armazenado. Nova PosicaoLivre: %p\n", PosicaoLivre);
}

void ArmazenaCHAR(char *dado) {
    // Sua lógica de alinhamento está perfeita.
    while ((PosicaoLivre - Memoria) % 2 != 0) {
        PosicaoLivre++;
    }

    // CORREÇÃO 2: Cópia direta, mais simples para 1 byte.
    *PosicaoLivre = *dado;

    // Sua lógica de atualização está perfeita.
    PosicaoLivre = PosicaoLivre + sizeof(char);

    printf("CHAR armazenado. Nova PosicaoLivre: %p\n", PosicaoLivre);
}