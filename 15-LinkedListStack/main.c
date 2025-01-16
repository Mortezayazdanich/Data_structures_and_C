#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

struct node *createNode(int data);
void push(struct node **head, int data);
void pop(struct node **head);
int peek(struct node *head);
int printStack(struct node *head);

int main(void){
    struct node *head = createNode(1);

    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    printStack(head);
    pop(&head);
    printStack(head);
    printf("Top element: %d\n", peek(head));
    
}

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

void push(struct node **head, int data){
    struct node *newNode = createNode(data);
    if (newNode == NULL) return;
    newNode->next = *head;
    *head = newNode;
}

void pop(struct node **head){
    if (*head == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int peek(struct node *head){
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return head->data;
}

int printStack(struct node *head){
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}

