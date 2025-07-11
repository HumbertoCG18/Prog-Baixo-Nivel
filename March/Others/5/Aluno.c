#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct{
    float p1, p2;
    float media;
} Aluno;

int main(int argc, char const *argv[])
{
    int nAlunos = atoi(argv[1]);
    Aluno listaDeAlunos[nAlunos];
    srand(time(NULL));

    calculaMedia(listaDeAlunos, nAlunos);

    for(int i=0; i<nAlunos; i++){
        listaDeAlunos[i].p1= (rand()%9)+1;
        listaDeAlunos[i].p2= (rand()%9)+1;
    }

    return 0;
}
