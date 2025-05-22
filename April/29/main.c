#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* createEmptyList(){
    return NULL;
}

bool isEmpty(Node* head){
    return head == NULL;
}

void insertAtBeginning(Node** head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL){
        printf("Erro: Falha na alocação de memória \n");
        return;
    }

    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    printf("Elemento %d inserido no inicio da lista\n", value);
}

void insertAtEnd(Node** head, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode
    }
    printf("Elemento %d inserido no final da lista\n", value);
}

void insertAtPosition(Node** head, int value, int position){
    if (position < 0){
        printf("Posição inválida\n");
        return;
    }

    if (position == 0 || *head == NULL) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == )   
}