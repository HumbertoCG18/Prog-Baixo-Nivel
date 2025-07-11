#include <stdio.h>

void main(){
    int b=200;
    printf("&b: %p\n", &b);
    printf("b:  %d\n", b);

    int* a;
    a=&b;
    printf("&a: %p\n", &a);
    printf("a : %p\n", a);
    printf("*a: %d\n", *a);

    int *c;
    printf("&c: %p\n", &c);
    printf("c : %p\n", c);
    printf("*c: %d\n", *c);
    c=0;
    printf("&c: %p\n", &c);
    printf("c : %p\n", c);
    printf("*c: %d\n", *c);


}