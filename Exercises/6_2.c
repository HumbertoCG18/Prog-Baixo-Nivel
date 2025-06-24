#include <stdio.h>

/**
 * @brief Elimina um elemento de um vetor de inteiros usando apenas ponteiros.
 * @param v Ponteiro para o início do segmento do vetor a ser considerado.
 * @param posicao Índice do elemento a ser removido, relativo ao ponteiro v.
 * @param qtd Ponteiro para a variável que armazena a quantidade total de elementos.
 */
void Elimina(int *v, int posicao, int *qtd);

// Função auxiliar para imprimir o vetor
void ImprimeVetor(int *vetor, int tamanho) {
    int i;
    printf("{ ");
    for (i = 0; i < tamanho; i++) {
        // Usando ponteiros para acessar os elementos
        printf("%d ", *(vetor + i));
    }
    printf("}\n");
}

int main() {
    int Vetor[50] = {1, 2, 3, 4, 5, 6, 7};
    int QtdDeElementos = 7;

    printf("Vetor original: ");
    ImprimeVetor(Vetor, QtdDeElementos);
    printf("Quantidade: %d\n\n", QtdDeElementos);

    // --- Primeira chamada ---
    // v aponta para o elemento '2' (Vetor[1]). posicao=3 remove o elemento em v+3, que é o '5'.
    printf("Chamando Elimina(&Vetor[1], 3, &QtdDeElementos)...\n");
    Elimina(&Vetor[1], 3, &QtdDeElementos);
    printf("Vetor resultante: ");
    ImprimeVetor(Vetor, QtdDeElementos); // Esperado: { 1 2 3 4 6 7 }
    printf("Nova quantidade: %d\n\n", QtdDeElementos);

    // --- Segunda chamada ---
    // v aponta para o elemento '7' (Vetor[5]). posicao=0 remove o próprio elemento '7'.
    printf("Chamando Elimina(&Vetor[5], 0, &QtdDeElementos)...\n");
    Elimina(&Vetor[5], 0, &QtdDeElementos);
    printf("Vetor resultante: ");
    ImprimeVetor(Vetor, QtdDeElementos); // Esperado: { 1 2 3 4 6 }
    printf("Nova quantidade: %d\n\n", QtdDeElementos);
    
    return 0;
}


void Elimina(int *v, int posicao, int *qtd) {
    // 1. Cria um ponteiro que aponta para o elemento a ser removido.
    int *ponteiro_alvo = v + posicao;
    
    // 2. Cria um ponteiro para o final lógico do vetor.
    // O ponteiro 'v' pode não ser o início do 'Vetor', então não podemos usá-lo como base.
    // A lógica de parada deve se basear no ponteiro_alvo e na quantidade total.
    // O último elemento a ser copiado está em (ponteiro_alvo + (*qtd - posicao - 2))
    // O laço deve ir do alvo até o penúltimo elemento.
    int *ponteiro_final = v + (*qtd - 1); 

    // 3. Laço de deslocamento
    // 'p' começa no alvo e vai até um antes do final do vetor
    int *p;
    for (p = ponteiro_alvo; p < ponteiro_final; p++) {
        // Copia o valor do próximo elemento para a posição atual
        *p = *(p + 1);
    }

    // 4. Atualiza a quantidade de elementos
    // Os parênteses são cruciais para decrementar o VALOR para o qual 'qtd' aponta,
    // e não o ponteiro em si.
    (*qtd)--;
}