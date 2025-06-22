#include <stdio.h>

typedef struct
{
    float p1;
    float p2;
    float trab;
    int faltas;
} Aluno;

typedef struct
{
    float numerador;
    float denominador;
} Fracao;

float calcula(Fracao frac);
// const faz com que a memória
// apontada não possa ser alterada
float calcula2(const Fracao *frac);

int main()
{
    Aluno aluno1, aluno2;

    aluno1.p1 = 10;
    aluno1.p2 = 7.5;
    aluno1.trab = 8;
    aluno1.faltas = 4;

    aluno2.p1 = 6.5;
    aluno2.p2 = 4.8;
    aluno2.trab = 7.5;
    aluno2.faltas = 0;

    Fracao f1;
    Fracao f2 = {5, 3};
    f1.numerador = 2;
    f1.denominador = 3;
    printf("Valor (calcula) : %f\n", calcula(f1));
    printf("Valor (calcula2): %f\n", calcula2(&f1));
}

float calcula(Fracao frac)
{
    return frac.numerador / frac.denominador;
}

float calcula2(const Fracao *frac)
{
    //frac->numerador = 0;
    // return (*frac).numerador / (*frac).denominador;
    return frac->numerador / frac->denominador;
}
