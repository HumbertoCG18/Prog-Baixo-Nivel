#include <stdio.h>

int meuStrLen(char * );

int main(int argc, char const *argv[]){
    //char * texto = "Edson Ifarraguirre Moreno";
    char * texto = "Edson";
    printf("O tamanho do texto \"%s\" eh %d\n", texto, meuStrLen(texto));
    return 0;
}

int meuStrLen(char * txt){
    int len=0;
    while(*txt++)
      len++;
    return len;
}