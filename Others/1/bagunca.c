#include <stdio.h>

void main(){
  long a=0;
  long* ptr=&a;
  for(;;) printf("%p --> %d\n",ptr++,*ptr);
}
