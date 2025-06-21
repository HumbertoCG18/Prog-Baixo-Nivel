#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void initList(LinkedList *ll){
    ll->head=ll->tail=NULL;
    ll->size=0;
}

void add(LinkedList *ll, int element){
    Nodo * novo = malloc(sizeof(Nodo));
    novo->value=element;
    novo->next=NULL;

    if(ll->size==0)
        ll->head=ll->tail=novo;
    else{
        ll->tail->next=(struct Node*) novo;
        ll->tail=novo;
    }
    ll->size++;
    //printf("Inseriu(%d): %d(%p -> %p), head(%p), tail(%p)\n",ll->size, novo->value, novo, novo->next, ll->head, ll->tail);
}

void print(LinkedList* ll){
    Nodo *aux = ll->head;
    printf("[");
    while (aux!=NULL){
        printf("%d ", aux->value);
        aux=aux->next;
    }
    printf("]\n");
}

void printn(LinkedList* ll, int n){
    Nodo *aux = ll->head;
    printf("[");
    while ((aux!=NULL) && (n>0)){
        printf("%d ", aux->value);
        aux=aux->next;
        n--;
    }
    printf("]\n");
}
void clean(LinkedList *ll){
    Nodo *aux;

    while (ll->head!=NULL){
        aux=ll->head;
        ll->head=ll->head->next;
        free(aux);
        ll->size--;
    }
}

int indexOf(LinkedList * ll, int element){
//     Retorno -1, a lista não existe
    if(ll==NULL) return -1;

//     Retorno -2, a lista está vazia
    if((ll->size==0)||(ll->head==NULL)) return -2;

//     Retorno >=0, o elemento foi encontrado
    Nodo *aux=ll->head;
    int idx=0;
    while(aux!=NULL){
        if(aux->value==element) return idx;

        idx++;
        aux=aux->next;
    }
    return -3;
}

int rremove(LinkedList *ll, int element){
//     Retorno -1, a lista não existe
    if(!ll) return -1;

//     Retorno -2, a lista está vazia
    if((ll->size==0)||(!ll->head)) return -2;

    Nodo * aux = ll->head;
    int idx=0;
    if(aux->value!=element){
        while(aux){
            if((aux->next) && (aux->next->value==element)){
                Nodo *remove=aux->next;
                aux->next=remove->next;

                if(remove==ll->tail)
                    ll->tail=aux;

                free(remove);
                ll->size--;
                return idx+1;
            }
            idx++;
            aux=aux->next;
        }
        return -3;
    }
    else{
        // remove o head
        ll->head=ll->head->next;

        if(aux==ll->tail)
            ll->tail=ll->head;

        free(aux);
        ll->size--;
        return 0;
    }
}

