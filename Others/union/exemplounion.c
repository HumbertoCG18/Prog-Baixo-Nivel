#include <stdio.h>

typedef union
{
    unsigned char bytes[4];
    unsigned int dword;
} HW_Register;

int main()
{
    HW_Register reg;
    reg.dword = 257;

    printf("dword: %d\n", reg.dword);
    printf("%02X %02X %02X %02X\n\n",
           reg.bytes[0],
           reg.bytes[1],
           reg.bytes[2],
           reg.bytes[3]);

    reg.bytes[2] = 1;
    reg.bytes[3] = 1;

    printf("dword: %d\n", reg.dword);
    printf("%02X %02X %02X %02X\n",
           reg.bytes[0],
           reg.bytes[1],
           reg.bytes[2],
           reg.bytes[3]);
}