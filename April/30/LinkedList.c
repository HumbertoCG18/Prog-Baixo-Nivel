#include <stdio.h>
#include <stdlib.h>

// criar estrutura de nodo
typedef struct local Node;
struct local{
    int value;
    Node * next;
};

// criar estrutura de lista
typedef struct
{
    int size;
    Node * head;
    Node * tail;
    
} LinkedList;

void initList(LinkedList *ll);

// Operacoes com lista
//   adicionar elemento
void add(LinkedList *ll, int element);
//   remover indice
//   ver tamanho da lista (DEPRECATED)
//   capturar por indice um determinado elemento
int indexOf(LinkedList * ll, int element);
//   descobrir indice de um determinado elemento
//   descobrir se está vazio (DEPRECATED)
//   ordenacao
//   impressao da lista
void print(LinkedList* ll);
//   apaga a lista
void clean(LinkedList *ll);

void main(){
    LinkedList ll;
    initList(&ll);
    add(&ll, 7);
    add(&ll, 8);
    add(&ll, 9);
    getchar();

    for(int i=0; i<10; i++){
        for(int x=0; x<1000000; x++)
            add(&ll,x);
        printf("%d de 10\n",i+1);        
    }

    printf("Lista cheia\n");

    getchar();

    clean(&ll);
    printf("Memoria limpa\n");

    getchar();

    //print(&ll);
}

void initList(LinkedList *ll){
    ll->head=ll->tail=NULL;
    ll->size=0;
}
void add(LinkedList *ll, int element){
    Node * novo = malloc(sizeof(Node));
    novo->value=element;
    novo->next=NULL;

    if(ll->size==0)
        ll->head=ll->tail=novo;
    else{
        ll->tail->next=novo;
        ll->tail=novo;
    }
    ll->size++;
    //printf("Inseriu(%d): %d(%p -> %p), head(%p), tail(%p)\n",ll->size, novo->value, novo, novo->next, ll->head, ll->tail);
}

void print(LinkedList* ll){
    Node *aux = ll->head;
    printf("[");
    while (aux!=NULL){
        printf("%d ", aux->value);
        aux=aux->next;
    }
    printf("]\n");
}

void clean(LinkedList *ll){
    Node *aux;

    while (ll->head!=NULL){
        aux=ll->head;
        ll->head=ll->head->next;
        free(aux);
    }
    

}

int indexOf(LinkedList * ll, int element){
    Node *aux = ll->head;
    int idx=0;
    while (aux!=NULL){
        if(aux->value==element) return idx;
        idx++;
        aux=aux->next;
    }
    return -1;
}