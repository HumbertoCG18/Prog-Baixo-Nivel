#include <stdio.h>

int main() {
    char* text = "Prog. Sofware Basico";
    int v[] = { 0, 1, 2, 3, 1021 };
    int matriz[4][4] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };

    printf("Vetor de char\n");
    char* ptr=text;
    for(int i=0; i<20*sizeof(char); i++)
      printf("[%d]: %c\n",i,*ptr++);

    printf("\n-=-=-=-=-=-=-=-\n");
    printf("Vetor de int\n");
    ptr=v;
    for(int i=0; i<5*sizeof(int); i++)
      printf("[%d]: %d\n",i,*ptr++);

    printf("\n-=-=-=-=-=-=-=-\n");
    printf("Matriz de int\n");
    ptr=matriz;
    for(int i=0; i<4*4*sizeof(int); i++)
      printf("[%d]: %d\n",i,*ptr++);

}
