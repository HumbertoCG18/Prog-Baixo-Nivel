#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    for(int i=0; i<argc; i++)
      printf("  argumento %02d: %s\n", i, argv[i]);

    if(argc!=3){
        printf("Faltam argumentos:\n");
        printf("  Informe dois nros inteiros: programa <linha> <coluna>\n");
        return -1;
    }

    int nlinhas=atoi(argv[1]);
    int ncolunas=atoi(argv[2]);

    printf("Capturados:\n");
    printf("  O numero de linhas é %d\n",nlinhas);
    printf("  O numero de colunas é %d\n",ncolunas);
    printf("  O total de espacos eh : %d\n", nlinhas*ncolunas);

    return 0;

}
