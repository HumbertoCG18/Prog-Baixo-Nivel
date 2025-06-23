#include <stdio.h>

int STRLEN(char *s1);

int main(){
    char minha_string[] = {7,'o','l','a','','P','B','N'};
    char string_origem[] = "PBN";
    int tamanho_calculado;

    printf("Iniciando o teste da funcao STRLEN...\n");
    printf("O tamanho esperado era: 7\n");
    printf("A sua funcao STRLEN retornou: %d\n", tamanho_calculado);

    if (tamanho_calculado == 7){
        printf("\nParabens! A funcao STRLEN esta correta.\n");
    } else {
        printf("\nOpa, algo deu errado. Tente novamente.\n");
    }
    return 0;
}

int STRLEN(char *s1){
    return *s1;
}

void STRCPYNULL(char *s1, char *s2){
    
}