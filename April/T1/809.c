#include <string.h>

int expressiveWords(char* s, char** words, int wordsSize) {
    int count = 0;
    int sLen = strlen(s);
    
    for (int i = 0; i < wordsSize; i++) {
        int wordLen = strlen(words[i]);
        
        int sIndex = 0; // Ponteiro para s
        int wIndex = 0; // Ponteiro para a palavra atual
        int isValid = 1; // 1 = verdadeiro, 0 = falso
        
        while (sIndex < sLen && wIndex < wordLen) {
            // Os caracteres devem ser iguais
            if (s[sIndex] != words[i][wIndex]) {
                isValid = 0;
                break;
            }
            
            // Contar caracteres idênticos consecutivos em s
            char curr = s[sIndex];
            int sCount = 0;
            while (sIndex < sLen && s[sIndex] == curr) {
                sCount++;
                sIndex++;
            }
            
            // Contar caracteres idênticos consecutivos na palavra
            int wordCount = 0;
            while (wIndex < wordLen && words[i][wIndex] == curr) {
                wordCount++;
                wIndex++;
            }
            
            // Verificar critérios para elasticidade
            if (sCount < wordCount) {
                // Não podemos reduzir grupos
                isValid = 0;
                break;
            }
            
            if (sCount > wordCount && sCount < 3) {
                // Só podemos estender se o tamanho final for pelo menos 3
                isValid = 0;
                break;
            }
        }
        
        // Ambas as strings devem ser totalmente processadas
        if (isValid && sIndex == sLen && wIndex == wordLen) {
            count++;
        }
    }
    
    return count;
}