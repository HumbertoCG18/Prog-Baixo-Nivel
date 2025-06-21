#include <stdio.h>
#include <stdlib.h>

#include "set.h"

int menu();

void main(){
    hashSet conjunto;
    initSet(&conjunto, 20);
    int opcao;
    int value;    
    do{
        opcao=menu();
        switch(opcao){
            // insercao
            case 1:
                printf("Informe um valor: ");
                scanf("%d", &value);
                if(value>=0)
                    addToSet(&conjunto, value);
                break;
            // listagem
            case 2:
                printSet(&conjunto);
                printf("\n-=-=-==-==-=-==-\n");

                break;
            //salvar em arquivo
            case 3:
                int *listaDeValores=NULL;
                listaDeValores=toArray(&conjunto);
                if(listaDeValores!=NULL){
                    // SALVAMENTO EM UM ARQUIVO TEXTO
                    FILE *meuArquivo = fopen("conjunto.txt", "w");
                    if(meuArquivo==NULL){
                        printf("Erro na abertura do arquivo texto");
                        exit(1);
                    }

                    for(int i=0; i<conjunto.nElements; i++)
                        fprintf(meuArquivo, "%d\n", *(listaDeValores+i));
                    fclose(meuArquivo);

                    // SALVAMENTO EM UM ARQUIVO BINARIO
                    meuArquivo = fopen("conjunto.bin", "wb");
                    if(meuArquivo==NULL){
                        printf("Erro na abertura do arquivo binario");
                        exit(1);
                    }
                    /*
                    for(int i=0; i<conjunto.nElements; i++)
                        fwrite(listaDeValores+i, sizeof(int), 1, meuArquivo);
                    */
                    fwrite(listaDeValores, sizeof(int), conjunto.nElements, meuArquivo);

                    fclose(meuArquivo);


                }
                break;         
            //sair do programa       
            case 0:
                break;
            default:
                printf("Opcao invalida\n");
            
        }
    }while (opcao!=0);
    printf("Fim do programa\n");
    getchar();
}

int menu(){
    printf("Escolha uma das opções que seguem:\n");
    printf("  0 - Sair do programa\n");
    printf("  1 - Adicionar um valor no conjunto\n");
    printf("  2 - Listar o conjunto de valores\n");
    printf("  3 - Salvar o conjunto de valores em arquivo\n");
    printf("resposta: ");
    int valor;
    scanf("%d", &valor);
    return valor;
}
