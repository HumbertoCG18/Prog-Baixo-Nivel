# include <stdio.h>
typedef struct{
    float p1;
    float p2;
    float trab;
    int faltas;
} Aluno;

int main(){
    Aluno a1, a2;
    printf("Dados do aluno 1 - pré inicialização\n");
    printf("  p1:     %f\n", a1.p1);
    printf("  p2:     %f\n", a1.p2);
    printf("  trab:   %f\n", a1.trab);
    printf("  faltas: %d\n", a1.faltas);

    printf("Dados do aluno 2 - pré inicialização\n");
    printf("  p1:     %f\n", a2.p1);
    printf("  p2:     %f\n", a2.p2);
    printf("  trab:   %f\n", a2.trab);
    printf("  faltas: %d\n", a2.faltas);
    a1.p1=10;
    a1.p2=9;
    a1.trab=7.5;
    a1.faltas=0;

    a2.p1=5;
    a2.p2=7;
    a2.trab=8;
    a2.faltas=4;

    printf("Dados do aluno 1\n");
    printf("  p1:     %f\n", a1.p1);
    printf("  p2:     %f\n", a1.p2);
    printf("  trab:   %f\n", a1.trab);
    printf("  faltas: %d\n", a1.faltas);

    printf("Dados do aluno 2\n");
    printf("  p1:     %f\n", a2.p1);
    printf("  p2:     %f\n", a2.p2);
    printf("  trab:   %f\n", a2.trab);
    printf("  faltas: %d\n", a2.faltas);

    a2=a1;
    printf("Dados do aluno 2 após atribuição\n");
    printf("  p1:     %f\n", a2.p1);
    printf("  p2:     %f\n", a2.p2);
    printf("  trab:   %f\n", a2.trab);
    printf("  faltas: %d\n", a2.faltas);

    a1.p1=5;

    printf("Dados do aluno 1 - modificado\n");
    printf("  p1:     %f\n", a1.p1);
    printf("  p2:     %f\n", a1.p2);
    printf("  trab:   %f\n", a1.trab);
    printf("  faltas: %d\n", a1.faltas);

    printf("Dados do aluno 2 - mantendo o valor antigo\n");
    printf("  p1:     %f\n", a2.p1);
    printf("  p2:     %f\n", a2.p2);
    printf("  trab:   %f\n", a2.trab);
    printf("  faltas: %d\n", a2.faltas);
}