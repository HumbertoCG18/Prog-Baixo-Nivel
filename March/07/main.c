#include <stdio.h>

void quadrado(); // protótipo

int main(){ 
  quadrado();
}

void quadrado(){
  int k;   
  for (k=1; k<=10; k++)
	printf("%d\n", k*k);
} 

