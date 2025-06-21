#include <stdio.h>

// Questões 1) e 2)
char str[]  = {5, 'a', 'b', 'c', 'd', 'e' };
char nome[] = {4, 'J', 'o', 'a', 'o' };

char str2[]  = {56 & 0xff, 56 & 0xff<<8, 56 & 0xff<< 16, 56 & 0xff << 24, 'a', 'b', 'c', 'd', 'e' };
char nome2[] = {4, 0, 0, 0, 'J', 'o', 'a', 'o' };

int STRLEN(char *s1) {
  return *s1;
}
int STRLEN2(int *s1) {
  return *s1;
}

// Questão 7
void ImprimeBits(unsigned char n) {
  for (int i = 7; i >= 0 ; i--) {
    printf("%d", (n >> i) & 1);
  }
  
}

int main(void) {
  // Questões 1) e 2)
  printf("%d\n", *str);
  int* v = str2;
  printf("%d\n", *v);
  printf("%d\n", STRLEN(str));
  printf("%d\n", STRLEN2(str2));


  // Questão 7
  unsigned char i = 255;
  ImprimeBits(i);

return 0;
}