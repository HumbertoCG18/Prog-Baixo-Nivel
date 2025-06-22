#include <stdio.h>

typedef struct {
    char a;
} tp1;

typedef struct {
    char a;
    char b;
} tp2;

typedef struct {
    char a;
    char b;
    tp1 c;
} tp3;

typedef struct {
    char a;
    char b;
    tp1 c;
    int d;
} tp4;

typedef struct {
    char a;
    char b;
    tp1 c;
    int d;
    short e;
} tp5;

typedef struct {
    short e;
    char a;
    char b;
    tp1 c;
    int d;
} tp6;

int main()
{
    printf("Sizeof tp1 = %d\n", sizeof(tp1));
    /*
    tp1 t1; t1.a=1;
    */
    printf("Sizeof tp2 = %d\n", sizeof(tp2));
    /*
    tp2 t2; t2.a=1; t2.b=1; 
    */
    printf("Sizeof tp3 = %d\n", sizeof(tp3));
    /*
    tp3 t3; t3.a=1; t3.b=1; t3.c.a=3;
    */
    printf("Sizeof tp4 = %d\n", sizeof(tp4));
    /*
    tp4 t4; t4.a=1; t4.b=1; t4.c.a=3; t4.d=12;
    */
   tp4 t4 = {'a', 'b', 'c', 0x01020304};
   char * ptr= (char*) (&t4);
   for(int i=0; i<sizeof(t4); i++){     
     printf("No endereco %p, tem %d\n", ptr, *ptr);
     ptr++;
   }
    printf("Sizeof tp5 = %d\n", sizeof(tp5));
    printf("Sizeof tp6 = %d\n", sizeof(tp6));
}