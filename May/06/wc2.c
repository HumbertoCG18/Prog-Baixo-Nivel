#include <stdio.h>

int main(int argc, char** argv) {
	int cl = 0;
	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Não foi possível abrir o arquivo!");
		return -1;
	}
	int c;
	while ( (c = fgetc(f)) != EOF ) {
		if (c == '\n') {
			cl++;
		}
		printf("%c %x\n", c == '\n'? '.':c, c);
	}
	fclose(f);
	printf("\nLC=%d\n", cl);
	return 0;
}