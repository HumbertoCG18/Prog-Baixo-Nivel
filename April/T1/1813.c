#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool areSentencesSimilar(char* sentence1, char* sentence2) {
    // Criar cópias de frases para tokenização
    char* s1Copy = (char*)malloc(strlen(sentence1) + 1);
    char* s2Copy = (char*)malloc(strlen(sentence2) + 1);
    strcpy(s1Copy, sentence1);
    strcpy(s2Copy, sentence2);
    
    // Divide as sentenças em letras
    char* words1[100]; // Assumindo máximo 100 letras
    char* words2[100];
    int count1 = 0, count2 = 0;
    
    char* token = strtok(s1Copy, " ");
    while (token != NULL) {
        words1[count1++] = token;
        token = strtok(NULL, " ");
    }
    
    token = strtok(s2Copy, " ");
    while (token != NULL) {
        words2[count2++] = token;
        token = strtok(NULL, " ");
    }
    
    // Determinar qual sentença tem menos palavras
    char** shorter = (count1 <= count2) ? words1 : words2;
    char** longer = (count1 <= count2) ? words2 : words1;
    int shorterCount = (count1 <= count2) ? count1 : count2;
    int longerCount = (count1 <= count2) ? count2 : count1;
    
    // Tente todas as maneiras possíveis de dividir a frase mais curta em um prefixo e um sufixo
    for (int i = 0; i <= shorterCount; i++) {
        // Verificar se as primeiras i palavras da sentença mais curta correspondem às primeiras i palavras da sentença mais longa
        bool prefixMatch = true;
        for (int j = 0; j < i; j++) {
            if (strcmp(shorter[j], longer[j]) != 0) {
                prefixMatch = false;
                break;
            }
        }
        
        if (!prefixMatch) continue;
        
        // Verificar se as últimas palavras (shorterCount - i) da sentença mais curta correspondem às últimas palavras (shorterCount - i) da sentença mais longa        
        bool suffixMatch = true;
        for (int j = 0; j < shorterCount - i; j++) {
            if (strcmp(shorter[i + j], longer[longerCount - (shorterCount - i) + j]) != 0) {
                suffixMatch = false;
                break;
            }
        }
        
        if (prefixMatch && suffixMatch) {
            free(s1Copy);
            free(s2Copy);
            return true;
        }
    }
    
    free(s1Copy);
    free(s2Copy);
    return false;
}