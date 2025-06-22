#include <stdio.h>

typedef struct {
    float p1;
    float p2;
    float trab;
    int faltas;
} Aluno;

void exibeAluno(Aluno a);
void exibeAluno2(const Aluno* a); // const garante que ninguém vai alterar os campos da struct

int main()
{
    Aluno a1;
    Aluno a2 = { 8.5, 7.5, 6.7, 4 };
    printf("Tamanho em bytes: %d\n", sizeof(Aluno));
    printf("Aluno 1:\n");
    // exibeAluno(a1);
    exibeAluno2(&a1);
    printf("\nAluno 2:\n");
    // exibeAluno(a2);
    exibeAluno2(&a2);
}

void exibeAluno(Aluno a)
{
    printf("P1: %f\n", a.p1);    
    printf("P2: %f\n", a.p2);    
    printf("Trab: %f\n", a.trab);    
    printf("Faltas: %d\n", a.faltas);    
}

void exibeAluno2(const Aluno* a)
{
    printf("P1: %f\n", a->p1); // mesma coisa que (*a).p1   
    printf("P2: %f\n", a->p2);    
    printf("Trab: %f\n", a->trab);    
    printf("Faltas: %d\n", a->faltas);   
}