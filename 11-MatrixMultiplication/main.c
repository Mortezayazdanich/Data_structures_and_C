#include <stdlib.h>
#include <stdio.h>

int main(void){
    int n, m, a, b, i, j, k, c;
    int **arr1, **arr2, **arr3;

    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &n, &m);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &a, &b);

    if (m != a) {
        printf("The number of columns of the first matrix must be equal to the number of rows of the second matrix\n");
        return 1;
    }

    arr1 = (int**)malloc(n * sizeof(int*));
    arr2 = (int**)malloc(a * sizeof(int*));
    arr3 = (int**)malloc(n * sizeof(int*));

    for(i = 0; i < n; i++) arr1[i] = (int*)malloc(m * sizeof(int));
    for(i = 0; i < a; i++) arr2[i] = (int*)malloc(b * sizeof(int));
    for(i = 0; i < n; i++) arr3[i] = (int*)malloc(b * sizeof(int));

    if (arr1 == NULL || arr2 == NULL || arr3 == NULL) {
        printf("Memory allocation failed\n");
        return 2;
    }

    // Initialize matrices with example values
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            arr1[i][j] = i + j;

    for (i = 0; i < a; i++)
        for (j = 0; j < b; j++)
            arr2[i][j] = i * j;
    

    for (i = 0; i < n; i++){
        for (j = 0; j < b; j++){
            arr3[i][j] = 0;
            for (k = 0; k < m; k++){
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }

        // Free allocated memory
    for (i = 0; i < n; i++) free(arr1[i]);
    for (i = 0; i < a; i++) free(arr2[i]);
    for (i = 0; i < n; i++) free(arr3[i]);
    free(arr1);
    free(arr2);
    free(arr3);
    
    return 0;
}