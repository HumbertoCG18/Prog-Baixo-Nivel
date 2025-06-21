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
