#include <stdio.h>
int main(int argc, char const *argv[])
{
    unsigned char var;
    //var = -1;
    
    var = 0b10000001;

    printf("var: %d\n", var);
    printf("var: %u\n", (var & 0x0ff));
    printf("var: %c\n", var);
    printf("var: %x\n", var);

    if(var<0)
        printf("var: é negativo \n");
    else
        printf("var: é zero ou positivo \n");

    return 0;
}
