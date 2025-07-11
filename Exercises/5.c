#include <stdio.h>
void imprime(int *p, int qtd)
{
 for (int i =0;i<qtd; i++)
 printf ("%d ", p[i]);
 printf("\n");
}
int main() {
 int M[2][3] = { {10,20,30},{40,50,60} };
 int *ptr;
 ptr = (int*)M;
 printf ("*PTR: %d\n", *ptr);
 imprime((int*)M,3);
 printf ("++(*PTR): %d\n", ++(*ptr));
 imprime((int*)M,3);
 printf ("(*PTR)++: %d\n", (*ptr)++);
 imprime((int*)M,3);
 printf ("++(*ptr): %d\n", ++(*ptr));
 imprime((int*)M,3);
 printf ("*PTR: %d\n", *++ptr);
 imprime((int*)M,3);
 return 0;
}