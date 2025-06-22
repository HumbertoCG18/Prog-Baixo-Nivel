#include <stdio.h>

int main(){

  char c [10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
  char *p = c;
 
  printf("O valor de *p eh %c\n", *p);
  printf("O proximo valor de *p eh %c \n", *(p+1));
  p+=2;
  printf("O proximo valor de *p eh %c \n", *p);


}
