#include <stdio.h>
#include <stdlib.h>

int dup(int v[], int n);

int dup(int v[], int n)
{
    int c = 0;
    // TODO: completar!
    return c;
}

int main()
{
	printf("DUP");
    int ex1[] = {1,2,3,4,5,3,6,7,2,8};
    int r = dup(ex1, 10);
    printf("%d\n", r);

	return EXIT_SUCCESS;
}
