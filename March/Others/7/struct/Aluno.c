#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "Aluno.h"

int main(int argc, char const *argv[])
{
    // Rotina para comprovar q 
    // o nro argumento corretos foi passado
    if(argc != 2){
        printf("Falta informar o número de alunos a ser criado\n");
        printf("  Exemplo: O comando abaixo cria uma lista com 10 alunos\n");
        printf("    %s 10\n", argv[0]);
        return 0;
    }

    // rotina principal
    int nAlunos = atoi(argv[1]);
    Aluno listaDeAlunos[nAlunos];
    srand(time(NULL));

    for(int i=0; i<nAlunos; i++){
        listaDeAlunos[i].p1= (rand()%10)+1;
        listaDeAlunos[i].p2= (rand()%10)+1;
        listaDeAlunos[i].media= 0;
    }

    calculaMediaA(listaDeAlunos, nAlunos);

    listaAlunos(listaDeAlunos, nAlunos);

    typedef union {
        int i;
        float f;
    } tipo;

    tipo valor;

    printf("Exemplo de divisão: %d, %d\n", 4, 4>>1);
    printf("Exemplo de divisão: %d, %d\n", 5, 5>>1);
    printf("Exemplo de divisão: %d, %d\n", 6, 6>>1);

    valor.i=4;
    printf("Exemplo de divisão: %d, %d\n", valor.i, valor.i/2);
    valor.f=4;
    printf("Exemplo de divisão: %d, %d\n", valor.i, valor.i/2);

    return 0;
}

void listaAlunos(Aluno * lista, int qtde){
    for(int pos=0; pos<qtde; pos++)
        printf  ("Aluno%02d: P1(%4.1f), P2(%4.1f), Média(%4.1f)\n",
                    pos, lista[pos].p1, lista[pos].p2, lista[pos].media
                );

}

void calculaMediaA(Aluno * lista, int qtde){
    while(qtde--){
        //lista->media=(lista->p1+lista->p2)/2;
        (*lista).media = ((*lista).p1 + (*lista).p2) / 2;
        lista++;
    }
}
