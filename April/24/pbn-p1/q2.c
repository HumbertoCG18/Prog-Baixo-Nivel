#include <stdio.h>

double ftoc2(double f) {
	double c;
        c = 5.0 / 9.0 * (f - 32.0);
	return c;
}

float ftoc(float f) {
	float c;
        c = 5.0f / 9.0f * (f - 32.0f);
	return c;
}

int main(void) {
	printf("%f F = %f C\n", 451.0, ftoc(451.0));
	return 0;
}
