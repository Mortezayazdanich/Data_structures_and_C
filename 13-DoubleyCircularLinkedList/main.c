#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

void insertNode(struct node *head, int data);
void printList(struct node *head);

int main(void){
    struct node *head = createNode(1);

    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 6);
       
    printList(head);
    
}

void insertNode(struct node *head, int data){
    struct node *newNode = createNode(data);
    if (newNode == NULL) return;
    struct node *temp = head->prev; // Start from the last node
    temp->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = temp;
}

void printList(struct node *head){
    struct node *temp = head;
    do{
        printf(" %d ->", temp->data);
        temp = temp->next;
    }while (temp != head);
    printf(" :head: \n");
}