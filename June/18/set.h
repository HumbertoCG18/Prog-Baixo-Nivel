#include "list.h"

typedef struct{
    int nElements;
    int hashSize;
    LinkedList* setOfValues;
} hashSet;

void initSet(hashSet *hs, int hashSize);
int addToSet(hashSet *hs, int value);
void printSet(hashSet *hs);
int* toArray(hashSet *hs);
