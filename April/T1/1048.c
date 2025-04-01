#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Função para comparar palavras por comprimento para classificação
int compareByLength(const void* a, const void* b) {
    return strlen(*(const char**)a) - strlen(*(const char**)b);
}

// Função para verificar se a palavraA é uma predecessora da palavraB
bool isPredecessor(const char* wordA, const char* wordB) {
    int lenA = strlen(wordA);
    int lenB = strlen(wordB);
    
    // a palavraB deve ter exatamente um caractere a mais do que a palavraA
    if (lenB != lenA + 1) {
        return false;
    }
    
    int i = 0, j = 0;
    int diffCount = 0;
    
    while (i < lenA && j < lenB) {
        if (wordA[i] == wordB[j]) {
            i++;
            j++;
        } else {
            diffCount++;
            if (diffCount > 1) {
                return false;   // Mais de uma diferença
            }
            j++;  // Pula o caracter extra na wordB
        }
    }
    
    // Se anda estiver caracteres na wordB
    if (j < lenB) {
        diffCount++;
    }
    
    return (diffCount == 1);
}

// Funçao para achar o máximo de duas integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para atualizar DP array para um index específico
void updateDP(char** words, int* dp, int index, int* maxLength) {
    for (int j = 0; j < index; j++) {
        if (strlen(words[index]) == strlen(words[j]) + 1) {
            if (isPredecessor(words[j], words[index])) {
                dp[index] = max(dp[index], dp[j] + 1);
            }
        }
    }
    *maxLength = max(*maxLength, dp[index]);
}

int longestStrChain(char** words, int wordsSize) {
    // Ordena as palavras pela largura 
    qsort(words, wordsSize, sizeof(char*), compareByLength);
    
    // dp[i] representa a cadeia mais longa que termina em palavras[i]
    int* dp = (int*)malloc(wordsSize * sizeof(int));
    for (int i = 0; i < wordsSize; i++) {
        dp[i] = 1;  // Cada palavra, por si só, forma uma cadeia de comprimento 1
    }
    
    int maxChainLength = 1;
    
    // Processa cada letra
    for (int i = 0; i < wordsSize; i++) {
        updateDP(words, dp, i, &maxChainLength);
    }
    
    free(dp);
    return maxChainLength;
}