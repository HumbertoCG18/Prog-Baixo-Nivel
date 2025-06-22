#include <stdio.h>
#include <stdlib.h>

#include "set.h"

void main(){
    hashSet conjunto;
    initSet(&conjunto, 20);
    int value;
    do{ 
        printSet(&conjunto);
        printf("\n-=-=-==-==-=-==-\n");

        printf("Informe um valor: ");
        scanf("%d", &value);
        if(value>=0)
            addToSet(&conjunto, value);
    }while (value>=0);    


    getchar();
}
