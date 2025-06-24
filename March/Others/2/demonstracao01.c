#include <stdio.h>

void incArray(int []);

void main(){
    int data [] = {1,2,3,4,5,6,7,8,9,10};
    //preincremento
    printf("Pre incremento\n");
    for(int i=0; i<10; i++)
      printf("%d, ",data[i]);

    //posincremento
    incArray(data);
    printf("\nPos incremento\n");
    for(int i=0; i<10; i++)
      printf("%d, ",data[i]);

}

void incArray(int v[]){
    for(int idx=0; idx<10; idx++)
      v[idx]++;
}