#include "bibfunc.h"

float fatorial(int v){
    int res=1;
    for(int i=1; i<=v; i++) res*=i;
    return res;
}

float somatorio(int v){
    int res=0;
    for(int i=0; i<=v; i++) res+=i;
    return res;
}