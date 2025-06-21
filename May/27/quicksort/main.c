#include <stdio.h>
#include <stdlib.h>

int compare (void * a, void * b) {
  return ( *(int*)a - *(int*)b );
}
// Exemplo de ponteiro para funcao sem classes: quicksort
int main()
{
   int values[10000];
   srand(time(0));
   int i;
   for(i=0; i<10000; i++)
       values[i] = rand() % 100000;

   ///exemplo do quicksort em C
   qsort (values, 10000, sizeof(int), compare); // compare é um ponteiro para funcao

   printf("Usando o quicksort (e passagem de funcoes por parametro)\n");

   for (i=0; i<10000; i++)
      printf("%d ", values[i]);
   printf("\n");
   return 0;
}

