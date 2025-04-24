#include <stdio.h>

void dobro(double* n) {
	*n = *n * 2;
}

int main(void) {
	double a = 7.0;
	dobro(&a);
	printf("A=%.0lf\n", a);
	return 0;
}
