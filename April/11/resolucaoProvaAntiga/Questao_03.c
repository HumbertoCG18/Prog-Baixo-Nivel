#include <stdio.h>

void contaPares(char s[], int m[5][5]);
int converteVogalParaIndice(char v);

void main(){

    char * str = "UAEEIIIOOOOUUUUAE";
    int matriz[5][5];
    contaPares(str, matriz);

    for(int l=0; l<5; l++){      
      printf("\n");
      for(int c=0; c<5; c++)
        printf("%d ", matriz[l][c]);
    }
}

void contaPares(char s[], int m[5][5]){
  char *ptr;
  ptr=s;
  while(*ptr!='\0'){
    if(*(ptr+1)!='\0'){
        int l = converteVogalParaIndice(*ptr);
        int c = converteVogalParaIndice(*(ptr+1));
        m[l][c]+=1;
    }
    ptr++;
  }
}



int converteVogalParaIndice(char v){
    switch ( v)
    {
        case 'A':
            return 0; break;
        case 'E':
            return 1; break;
        case 'I':
            return 2; break;
        case 'O':
            return 3; break;
        case 'U':
            return 4; break;
    }
}
