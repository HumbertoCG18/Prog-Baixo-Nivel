#include <stdio.h>

int main(int argc, char* argv[]){

    //char planets[][8] = {"Mercury", "Venus", "Earth", 
    char *planets[]   = {"Mercury", "Venus", "Earth", 
                         "Mars", "Jupiter", "Saturn",
                         "Uranus", "Neptune", "Pluto"};
    char * ptr=planets[0];

    int i=0;
    while(i<64){
        i++;
        if(*ptr=='\0')
            printf(". ");
        else
            printf("%c ", *ptr);

        ptr++;
        if((i%8)==0)
            printf("\n");
    }

/*
    for(int i=0; i<9; i++)
        for(int x=0; x<8; x++)
            printf("  %s\n", planets[i][x]);
*/
}