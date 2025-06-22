#include <stdio.h>

int main() {
    char* text = "Prog. Sofware Basico";
    int v[] = { 0, 1, 2, 3, 4 };
    int matriz[4][4] = {
        0, 1, 2, 3,
        4, 5, 6, 7,
        8, 9, 10, 11,
        12, 13, 14, 15
    };
    
    char * ptr;
    printf("sizeof text = %d\n", sizeof(text));
    ptr=text;
    int i=0;
    while(*(ptr+i)!='\0'){	
      printf("[%d]: %c\n", i, *(ptr+i));
      i++;
    }
      
    printf("sizeof v = %d\n", sizeof(v));
    ptr=(char *)v;
    for(int i=0; i<sizeof(v); i++)
      printf("[%d]: %d\n", i, *(ptr+i));
      
    printf("sizeof matriz = %d\n", sizeof(matriz));
    ptr=(char *)matriz;
    for(int i=0; i<sizeof(matriz); i++)
      printf("[%d]: %d\n", i, *(ptr+i));
}
