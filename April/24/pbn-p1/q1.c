#include <stdio.h>

int contar(char* s, char c);

int contarFor(char* s, char c) {
	int r = 0;
	for (int i = 0; s[i] != '\0'; i++)	
		if (s[i] == c)
			r++;
	return r;
}

int contar(char* s, char c) {
	int r = 0;
	while (*s != '\0') {
		if (*s == c) {
			r++;
		}
		s++;
	}
	return r;
}

int main(void) {
	int c = contar("Hello World", 'o');
	printf("C = %d\n", c);
	return 0;
}
