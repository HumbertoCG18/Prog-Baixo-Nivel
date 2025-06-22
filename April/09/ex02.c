#include <stdio.h>

typedef struct{
    char nome[100];
    int anoNascimento;
    float nota;
} aluno;

void inicializaAlunos(aluno * umaLista);
void imprimeAlunos(aluno * umaLista);
float idadeMedia(aluno * umaLista);
void maiorNota(aluno * umaLista);
void acimaDaMedia(aluno * umaLista);

void main(){
    aluno lista[5];
    inicializaAlunos(lista);
    imprimeAlunos(lista);
//    printf("A idade media dos alunos eh : %f\n", idadeMedia(lista));
//    maiorNota(lista);
//    acimaDaMedia(lista);
}

void inicializaAlunos(aluno * umaLista){
    for(int i=0; i<5; i++){
        printf("Insira os detalhes do aluno %d/5\n",i+1);
        printf("  Informe o nome do aluno: ");
        scanf("%s", umaLista[i].nome);
        printf("  Informe o ano de nascimento do aluno: ");
        scanf("%d", &umaLista[i].anoNascimento);
        printf("  Informe a nota do aluno: ");
        scanf("%f", &umaLista[i].nota);
        printf("\n");
    }    
}
void imprimeAlunos(aluno * umaLista){
    printf("A lista de alunos é:\n");
    for(int i=0; i<5; i++){
        printf("Aluno %d/5\n",i+1);
        printf("  Nome: %s\n", (*umaLista).nome);
        printf("  Ano:  %d\n", umaLista->anoNascimento);
        printf("  Nota: %f\n", umaLista->nota);
        printf("\n");
        umaLista++;
    }
}
float idadeMedia(aluno * umaLista){
    int count=5;
    int acumIdades=0;
    while(count>0){
        acumIdades+=2024-(*umaLista).anoNascimento;
        umaLista++;
        count--;
    }
    return (float) acumIdades/5;
}
//void maiorNota(aluno * umaLista);
//void acimaDaMedia(aluno * umaLista);
