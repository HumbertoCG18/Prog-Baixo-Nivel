#include <stdio.h>
#include <stdlib.h>

// criar estrutura de nodo
typedef struct Node Nodo;
struct Node
{
    int value;
    Nodo * next;
};

// criar estrutura de lista
typedef struct
{
    int size;
    Nodo * head;
    Nodo * tail;
    
} LinkedList;

void initList(LinkedList *ll);

// Operacoes com lista
//   adicionar elemento
void add(LinkedList *ll, int element);
//   remover indice
//   ver tamanho da lista (DEPRECATED)
//   capturar por indice um determinado elemento
//     Retorno -1, a lista não existe
//     Retorno -2, a lista está vazia
//     Retorno -3, o elemento não existe na lista
//     Retorno >=0, o elemento foi encontrado
int indexOf(LinkedList * ll, int element);
//   descobrir indice de um determinado elemento
//   descobrir se está vazio (DEPRECATED)
//   ordenacao
//   impressao da lista
void print(LinkedList* ll);
void printn(LinkedList* ll, int n);
//   apaga a lista
void clean(LinkedList *ll);

// remove o elemento encontrado e retorna a posicao onde estava
int rremove(LinkedList *ll, int element);


void main(){
    LinkedList ll;
    initList(&ll);
    add(&ll, 7);
    add(&ll, 8);
    add(&ll, 9);
    print(&ll);

    getchar();

    for(int i=0; i<10; i++){
        for(int x=0; x<1000000; x++)
            add(&ll,x);
        printf("%d de 10\n",i+1);        
    }   

    printf("Lista cheia (%d elementos)\n", ll.size);

    getchar();

    printf("Informe um valor a ser encontrado: ");
    int value;
    scanf("%d", &value);
    int idx=indexOf(&ll, value);
    switch (idx)    {
        case -1:
            printf("A lista não existia\n");
            break;
        case -2:
            printf("A lista estava vazia\n");
            break;
        case -3:
            printf("O valor %d não foi encontrado na lista\n", value);
            break;    
        default:
            printf("O valor %d está na posição %d da lista\n", value, idx);
            break;
    }

    getchar();

    printf("Informe um valor a ser removido: ");
    value;
    scanf("%d", &value);

    printn(&ll, 10);
    
    idx=rremove(&ll, value);

    switch (idx)    {
        case -1:
            printf("A lista não existia\n");
            break;
        case -2:
            printf("A lista estava vazia\n");
            break;
        case -3:
            printf("O valor %d não foi encontrado na lista\n", value);
            break;    
        default:
            printf("O valor %d estava na posição %d da lista e foi removido\n", value, idx);
            break;
    }
    printn(&ll, 10);
    getchar();

    clean(&ll);
    printf("Memoria limpa (%d elementos) na lista\n", ll.size);
    getchar();

    //print(&ll);
}

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


//     Retorno >=0, o elemento foi encontrado

}