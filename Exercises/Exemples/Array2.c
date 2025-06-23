#include <stdio.h>
#include <string.h>

int main(){
    char s[10] = "teste";
    int i;
    
    printf("String: %s\n", s); // %s lê até encontrar o '\0'
    printf("Tamanho (strlen): %ld\n\n", strlen(s)); // strlen() conta até o '\0'

    for(i = 0; i < 10; i++){
        printf("Caractere: %c, Valor ASCII: %d\n", s[i], s[i]);
    }
    return 0;
}