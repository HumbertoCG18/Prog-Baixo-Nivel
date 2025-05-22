#include <stdio.h>

void hello(char *s) {
  printf("Hello %s\n", s);
}

void bye(char *s) {
  printf("Bye %s\n", s);
}

void now() {
  printf("NOW!");
}

#define MAX 2
void *fs[] = {hello, now};
char *ops[MAX] = {"hello",  "now"};

// DO NOT WRITE BELLOW THIS!
int main(void) {
  int op;
  void (*f)(char *s);
  printf("Menu:\n");
  for (int i = 0; i < MAX; i++) {
    printf("%d - %s\n", i, ops[i]);
  }
  scanf("%d", &op);
  f = fs[op];
  f("Marco");
  return 0;
}