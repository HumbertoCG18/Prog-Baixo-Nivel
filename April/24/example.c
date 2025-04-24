#include <stdio.h>
#include <stdlib.h>
 
int main () {
	int i;
	int * v = malloc (5 * sizeof (int));
	printf("I=%p V=%p *V=%p\n", &i, &v, v);
	for (i = 0; i < 5; i ++) 
		v [i] = i * i;
	printf("Elemento v[2] = %d\n", v[2]);
	free(v);
	return 0;
}
