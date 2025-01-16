#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct node *head, int data);
void printList(struct node *head);

int main(void){
    struct node *head = createNode(1);

    insertNode(head, 2);
    insertNode(head, 3);
       

    printList(head);
    
}

void insertNode(struct node *head, int data){
    struct node *newNode = createNode(data);
    if (newNode == NULL) return;
    struct node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(struct node *head){
    struct node *temp = head;
    while (temp != NULL){
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}