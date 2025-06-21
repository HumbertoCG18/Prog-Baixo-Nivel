#include "set.h"
#include <stdio.h>
#include <stdlib.h>

void initSet(hashSet *hs, int hashSize){
    hs->hashSize=hashSize;
    hs->nElements=0;
    hs->setOfValues = malloc(hashSize*sizeof(LinkedList));
    for(int i=0; i<hashSize; i++)
        initList(&hs->setOfValues[i]);
}

int addToSet(hashSet *hs, int value){

    int hashIdx = ((unsigned int)value)%hs->hashSize;
    int lstIdx = indexOf(&hs->setOfValues[hashIdx], value);
    if(lstIdx>=0)
        return 0; // inserção não pode ser realizada

    // a inserção pode ser realizada
    add(&hs->setOfValues[hashIdx], value);
    hs->nElements++;
    return 1;
}

void printSet(hashSet *hs){
    if(hs->nElements==0)
      printf("O conjunto está vazio\n");
    else
        for(int i=0; i<hs->hashSize; i++){
            if(hs->setOfValues[i].size>0){
                printf("hshIdx%d: ", i);
                printn(&hs->setOfValues[i], hs->setOfValues[i].size);
            }
        }
}

int* toArray(hashSet *hs){
    if((hs==NULL)||(hs->nElements==0))
        return NULL;

    int * list = malloc(sizeof(int)*(hs->nElements));
    int idx=0;
    for(int i=0; i<hs->hashSize; i++)
        if(hs->setOfValues[i].size>0){
            Nodo *aux = hs->setOfValues[i].head;
            while(aux!=NULL){
                *(list+idx)=aux->value;
                idx++;
                aux=aux->next;
            }
        }
    return list;
}
