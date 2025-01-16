#include <stdlib.h>
#include <stdio.h>

#define MAX 100
int stack[MAX], top = -1; // top = -1 means stack is empty 

void push(int *stack, int *top, int value);
void pop(int *stack, int *top);
int peek(int *stack, int *top);
int printStack(int *stack, int *top);

int main(){
    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);
    push(stack, &top, 4);
    push(stack, &top, 5);
    printStack(stack, &top);
    pop(stack, &top);
    printStack(stack, &top);
    printf("Top element: %d\n", peek(stack, &top));
    return 0;

}

void push(int *stack, int *top, int value) {
    stack[++(*top)] = value;
}

void pop(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return;
    }
    (*top)--;
}

int peek(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[*top];
}

int printStack(int *stack, int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    for (int i = 0; i <= *top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    return 0;
}