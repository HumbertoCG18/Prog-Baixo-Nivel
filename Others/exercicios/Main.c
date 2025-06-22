#include <stdio.h>

unsigned int clear(unsigned int val);
unsigned int setbit (unsigned int x, int bit);
void printbin(unsigned int val);
unsigned int clearbit (unsigned int val, int bit);
unsigned int invertbit (unsigned int val, int bit);

int main(){

    unsigned int valor, pos, resultado;
/*
    printf("[CLEAR]Informe um valor qualquer: ");
    scanf("%d",&valor);

    resultado = clear(valor);

    printf("O resultado da função clear é %u\n",resultado);

    printf("[SETBIT]Informe um valor qualquer: ");
    scanf("%d",&valor);
    printf("[SETBIT]Informe o bit a ser setado: ");
    scanf("%d",&pos);
    resultado = setbit(valor,pos);
    printf("O resultado da função setbit é %u\n",resultado);
    printf("O valor de entrada <-> modificado\n");
    printbin(valor);
    printbin(resultado);
    printbin(resultado^valor);

    printf("[CLEARBIT]Informe um valor qualquer: ");
    scanf("%d",&valor);
    printf("[CLEARBIT]Informe o bit a ser setado: ");
    scanf("%d",&pos);
    resultado = clearbit(valor,pos);
    printf("O resultado da função clearbit é %u\n",resultado);
    printf("O valor de entrada <-> modificado\n");
    printbin(valor);
    printbin(resultado);
    printbin(resultado^valor);
*/    

    printf("[INVERTBIT]Informe um valor qualquer: ");
    scanf("%d",&valor);
    printf("[INVERTBIT]Informe o bit a ser setado: ");
    scanf("%d",&pos);
    resultado = invertbit(valor,pos);
    printf("O resultado da função invertbit é %u\n",resultado);
    printf("O valor de entrada <-> modificado\n");
    printbin(valor);
    printbin(resultado);
    printbin(resultado^valor);
}

unsigned int invertbit (unsigned int val, int bit){
    if((bit<0) || (bit>=(sizeof(val)*8)))
        return val;

    if(val&(1<<bit))
        return val & ~(1<<bit);
    else
        return val |  (1<<bit);
}

unsigned int clearbit (unsigned int val, int bit){
    unsigned int set=1;

    if((bit<0) || (bit>=(sizeof(val)*8)))
        return val;

    set = set << bit;
    set = ~set;
    return (val & set);    

    //return (val & ~(1<<bit));
}

unsigned int setbit (unsigned int val, int bit){
    unsigned int set=1;

    if((bit<0) || (bit>=(sizeof(val)*8)))
        return val;

    for(int i=0; i<bit; i++)
      set=set*2;
    return (val | set);    
}

unsigned int clear(unsigned int val){
    return val^val; 
    // val & 0;
    // val & ~val;
    // val >> sizeof(val)*8;
    // val << sizeof(val)*8;
}

void printbin(unsigned int val){
    for(int i=(sizeof(val)*8)-1; i>=0; i--){
      if((val&(1<<i))==0)
        printf("0");
      else 
        printf("1");

      if(((i%4)==0)&&(i!=0)) printf(".");
    }
    printf("\n");
}
