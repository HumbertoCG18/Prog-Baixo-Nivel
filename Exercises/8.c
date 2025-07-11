#include <stdio.h>
#include <stdlib.h>

// Definição do tipo de nodo da lista
typedef struct temp {
    int dado;
    struct temp *prox;
} TNODO;

// Protótipo da função a ser implementada
void RemoveUltimoElemento(TNODO **ptr_lista);

// Função auxiliar para imprimir a lista
void ImprimeLista(TNODO *lista) {
    if (!lista) {
        printf("Lista: (vazia)\n");
        return;
    }
    printf("Lista: ");
    TNODO *p = lista;
    while (p != NULL) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

// Função auxiliar para inserir no início (facilita os testes)
void InsereInicio(TNODO **ptr_lista, int valor) {
    TNODO *novo_nodo = (TNODO *)malloc(sizeof(TNODO));
    if (!novo_nodo) return;
    novo_nodo->dado = valor;
    novo_nodo->prox = *ptr_lista;
    *ptr_lista = novo_nodo;
}

int main() {
    TNODO *lista = NULL; // Começamos com uma lista vazia

    // Montando uma lista para teste: 30 -> 20 -> 10 -> NULL
    InsereInicio(&lista, 10);
    InsereInicio(&lista, 20);
    InsereInicio(&lista, 30);

    printf("--- Teste do Caso Geral ---\n");
    ImprimeLista(lista);
    printf("Removendo o ultimo elemento (10)...\n");
    RemoveUltimoElemento(&lista); // Deve remover o 10
    ImprimeLista(lista);
    printf("\n");

    printf("Removendo o ultimo elemento (20)...\n");
    RemoveUltimoElemento(&lista); // Deve remover o 20
    ImprimeLista(lista);
    printf("\n");

    printf("--- Teste da Lista com Um Elemento ---\n");
    printf("Removendo o ultimo elemento (30)...\n");
    RemoveUltimoElemento(&lista); // Deve remover o 30, lista ficará vazia
    ImprimeLista(lista);
    printf("\n");
    
    printf("--- Teste da Lista Vazia ---\n");
    printf("Tentando remover de uma lista ja vazia...\n");
    RemoveUltimoElemento(&lista); // Não deve fazer nada nem quebrar
    ImprimeLista(lista);

    return 0;
}


/**
 * @brief Remove o último elemento de uma lista encadeada.
 * @param ptr_lista Ponteiro para o ponteiro da cabeça da lista.
 */
void RemoveUltimoElemento(TNODO **ptr_lista) {
    // CASO 1: A lista está vazia. Não há nada a fazer.
    if (*ptr_lista == NULL) {
        return;
    }

    // CASO 2: A lista tem apenas um elemento.
    // Se o primeiro nodo não tem um próximo, ele é o único.
    if ((*ptr_lista)->prox == NULL) {
        free(*ptr_lista);      // Libera a memória do único nodo.
        *ptr_lista = NULL;     // ATUALIZA a cabeça da lista original para NULL.
        return;
    }

    // CASO 3: A lista tem dois ou mais elementos.
    // Precisamos de dois ponteiros para percorrer a lista:
    // 'anterior' guardará o penúltimo nodo e 'atual' o último.
    TNODO *anterior = NULL;
    TNODO *atual = *ptr_lista;

    // Percorre a lista até que 'atual' seja o último nodo.
    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    // Neste ponto, 'atual' é o último nodo e 'anterior' é o penúltimo.
    free(atual);             // Libera a memória do último nodo.
    anterior->prox = NULL;   // O penúltimo nodo agora é o último.
}