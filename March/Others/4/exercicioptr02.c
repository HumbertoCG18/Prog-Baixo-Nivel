#include<stdio.h>
#include<stdlib.h>

void copyA(int *, int *, int);

int main(int argc, char * argv[]){
    
    int vetSize = atoi(argv[1]);

    int vetSrc[vetSize], vetTgt[vetSize];

    for(int i=0; i<vetSize; i++){
        vetSrc[i]=i+1;
        vetTgt[i]=0;
    }

    for(int i=0; i<vetSize; i++){
        printf(" %d: %d <-> %d\n", i, vetSrc[i], vetTgt[i]);
    }

    copyA(vetSrc, vetTgt, vetSize);

    printf("-=-=-=-=-=-=-\n");
    for(int i=0; i<vetSize; i++){
        printf(" %d: %d <-> %d\n", i, vetSrc[i], vetTgt[i]);
    }
    
}

void copyA(int * src, int * tgt, int size){
    while(size--)
        *tgt++=*src++;
}