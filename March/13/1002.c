#include <stdio.h>
#include <math.h>
#define pi 3.14159

int main  (void){
    double area;
    double raio;

    scanf("lf", &raio);

    area = pi * pow(raio, 2.0);

    printf("A=%4lf\n", area);

    return 0;
}