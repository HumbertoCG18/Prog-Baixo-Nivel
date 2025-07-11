#include <stdio.h>


void main(){
  int c[] = { 3, 2, 1, 4};
  int * p=c;

  for(int i=0; i<4; i++)
    printf(" (%d, %p), \n", *p++, p);
//  printf("\n");
//  for(int i=0; i<4; i++)
//    printf(" %d, ", *(p+i));
//    printf(" %d, ", (*p)++);
}
