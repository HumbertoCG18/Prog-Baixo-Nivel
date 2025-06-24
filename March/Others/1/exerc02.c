/* 
    Escreva uma função que receba um tempo em 
    total de segundos desde a meia-noite, 
    retornando por referência o tempo em horas, 
    minutos e segundos correspondentes. 
*/

#include <stdio.h>
void converte(int, int*, int*, int*);
void imprimeConversao(int, int, int, int);

int main(){

    int hora, minuto, segundo;
    int totalSegundos;

    totalSegundos=60;
    converte(totalSegundos, &hora, &minuto, &segundo);
    imprimeConversao(totalSegundos, hora, minuto, segundo);

    totalSegundos=600;
    converte(totalSegundos, &hora, &minuto, &segundo);
    imprimeConversao(totalSegundos, hora, minuto, segundo);

    totalSegundos=6000;
    converte(totalSegundos, &hora, &minuto, &segundo);
    imprimeConversao(totalSegundos, hora, minuto, segundo);

    totalSegundos=60000;
    converte(totalSegundos, &hora, &minuto, &segundo);
    imprimeConversao(totalSegundos, hora, minuto, segundo);

    totalSegundos=60100;
    converte(totalSegundos, &hora, &minuto, &segundo);
    imprimeConversao(totalSegundos, hora, minuto, segundo);
}

void converte(
    int totalEmSegundos,
    int *hr,
    int *min,
    int *seg
){
    *hr  =  totalEmSegundos/(60*60);
    *min = (totalEmSegundos - (*hr*(3600)))/60;
    *seg =  totalEmSegundos - (*hr*(3600)) - (*min * 60);
}

void imprimeConversao(int v, int h, int m, int s){
    printf("\n-=-=-=-=-=-=-=-=-\n");
    printf("A conversao de %d segundos e':\n",v);
    printf("  qtde de horas   : %d\n", h);
    printf("  qtde de minutos : %d\n", m);
    printf("  qtde de segundos: %d\n", s);
}