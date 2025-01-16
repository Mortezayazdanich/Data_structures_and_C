#include <stdlib.h>
#include <stdio.h>


int main(void){
    int n, i;
    int* arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        arr[i] = i+1;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}