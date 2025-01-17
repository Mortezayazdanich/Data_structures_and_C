#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    struct node *front;
    struct node *rear;
} queue;

node *createNode(int data);
queue *createQueue();
void enqueue(struct queue *q, int data);
int dequeue(struct queue *q);
int front(struct queue *q);
int isEmpty(struct queue *q);
void printQueue(struct queue *q);

int main(void){
    queue *q = createQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printQueue(q);

    printf("Dequeued: %d\n", dequeue(q));
    printQueue(q);
    return 0;
}


struct node *createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct queue *createQueue(){
    queue *q = (queue*)malloc(sizeof(queue));
    if (q == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct queue *q, int data){
    node *newNode = createNode(data);
    if (newNode == NULL) return;
    if (q->rear == NULL){
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct queue *q){
    if (q->front == NULL){
        printf("Queue is empty\n");
        return INT_MIN;
    }
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int front(struct queue *q){
    if (q->front == NULL){
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->front->data;
}

int isEmpty(struct queue *q){
    return q->front == NULL;
}

void printQueue(struct queue *q){
    if (q->front == NULL){
        printf("Queue is empty\n");
    }
    node *temp = q->front;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}