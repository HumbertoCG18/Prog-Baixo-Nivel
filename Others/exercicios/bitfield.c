#include <stdio.h>

typedef struct{
    int red: 10;
    int green: 10;
    int blue: 10;
} RGBbit1;

typedef struct{
    int red: 12;
    int green: 12;
    int blue: 12;
} RGBbit2;

int main(){
    printf("Sizeof campo 10 = %d\n",sizeof(RGBbit1));
    printf("Sizeof campo 12 = %d\n",sizeof(RGBbit2));


    // Campos: 
    //   Red   00:09
    //   Green 10:19
    //   Blue  20:29

    unsigned int colour = 0; // algum valor inicial
    unsigned int newgreen = 0x1F4; // novo valor para armazenar no verde

    unsigned int maskcolour = 0x3ff;

    colour = colour & ~(maskcolour << 10);
    colour = colour | (newgreen << 10);

}