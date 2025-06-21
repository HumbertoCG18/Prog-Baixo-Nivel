#include <stdio.h>

void printToBin(long val, int tamTipoDado);

typedef union
{
    float fVal;
    int   iVal;
    /* data */
} minhaUnion;


void main(){

    char vc = 'a';
    //010110011
    printf("%c\n", vc);
    printf("%d\n", vc);
    printf("%x\n", vc);

    printToBin(vc, sizeof(vc)*8);

    printToBin(1234, sizeof(int)*8);

    minhaUnion a;
    a.fVal=2.74;
    printToBin(a.iVal, sizeof(a.iVal)*8);

}

void printToBin(long val, int tamTipoDado){
    for(int i=(tamTipoDado-1); i>=0; i--){
        if((val & (1 << i) )==0) printf("0");
        else printf("1");
        if(i%4==0) printf(" ");
    }
    printf("\n");
}
