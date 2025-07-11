#include <stdio.h>

typedef struct{
    float p1, p2;
    float tf;
    int faltas;
} Aluno;

int main(){

    Aluno aluno1, aluno2;
    aluno1.p1=10;
    aluno1.p2=7.5;
    aluno1.tf=8.0;
    aluno1.faltas=0;

    printf("Aluno1: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno1.p1, 
            aluno1.p2, 
            aluno1.tf, 
            aluno1.faltas);

    aluno2.p1=8;
    aluno2.p2=7;
    aluno2.tf=5;
    aluno2.faltas=4;

    printf("Aluno2: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno2.p1, 
            aluno2.p2, 
            aluno2.tf, 
            aluno2.faltas);

    aluno2=aluno1;
    printf("-=-=-=-=\n");
    printf("Aluno1: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno1.p1, 
            aluno1.p2, 
            aluno1.tf, 
            aluno1.faltas);
    printf("Aluno2: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno2.p1, 
            aluno2.p2, 
            aluno2.tf, 
            aluno2.faltas);
    printf("-=-=-=-=\n");
    aluno2.p1=0;
    aluno2.p2=1;
    aluno2.tf=2;
    aluno2.faltas=3;
    printf("Aluno1: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno1.p1, 
            aluno1.p2, 
            aluno1.tf, 
            aluno1.faltas);
    printf("Aluno2: p1(%4.1f), p2(%4.1f), tf(%4.1f), faltas(%d)\n",
            aluno2.p1, 
            aluno2.p2, 
            aluno2.tf, 
            aluno2.faltas);
}