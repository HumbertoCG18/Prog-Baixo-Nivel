#include <stdio.h>

char *mystery(unsigned int i) {
	static char buf[21];
	char *p = buf +21;
	*--p = '\0';

	do {
		*--p = '0' + (i % 10);
		i = i / 10;
	} while (i != 0);
	return p;
}

int main(void) {
	printf("[%s]\n", mystery(123));
	return 0;
}
