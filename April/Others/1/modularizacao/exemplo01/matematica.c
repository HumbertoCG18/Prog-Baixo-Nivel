#include "matematica.h"

float somatorio(int v){
    int result=0;
    for(int x=1; x<=v; x++)
      result+=x;
    return result;
}

float fatorial(int v){
    if(v<=1)
      return 1;
    else    
      return v*(fatorial(v-1));
}