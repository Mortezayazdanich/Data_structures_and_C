#include <stdlib.h>
#include <stdio.h>

int main(void){
    int op1, op2;
    char operator;
    printf("Enter the first operand: ");
    scanf("%d", &op1);
    printf("Enter the second operand: ");
    scanf("%d", &op2);
    
    while (operator != '+' && operator != '-' && operator != '*' && operator != '/'){
        printf("Enter the operator: ");
        while ((operator = getchar()) == '\n'); // Skip newline characters
    }
    switch (operator){
        case '+':
            printf("%d %c %d = %d\n", op1, operator, op2, op1 + op2);
            break;
        case '-':
            printf("%d %c %d = %d\n", op1, operator, op2, op1 - op2);
            break;
        case '*':
            printf("%d %c %d = %d\n", op1, operator, op2, op1 * op2);
            break;
        case '/':
            printf("%d %c %d = %d\n", op1, operator, op2, op1 / op2);
            break;
    }

    return 0;
}