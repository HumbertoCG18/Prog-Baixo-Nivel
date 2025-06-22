//
// Exemplo de uso da linha de comando: verificando se cada parametro digitado e' um nome
// valido de um planeta
// (slides 74-76)
//
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char* argv[])
{
    // Execute com por ex: ./08_planetas_linha_de_comando Oi tudo bem Earth Oi de novo Neptune

    char* planets[] =  { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto" };

    int i,j;
    for(i = 1; i < argc; i++) {
        for(j = 0; j < NUM_PLANETS; j++)
            if(strcmp(argv[i], planets[j]) == 0) {
                printf("%s e' um planeta %d\n", argv[i], j+1);
                break;
            }
        if(j == NUM_PLANETS)
            printf("%s nao e' um planeta\n", argv[i]);
    }
    return 0;
}


