#include <stdlib.h>
#include <stdio.h>

#define MAX 10
int binarySearch(int arr[], int l, int r, int x);

int main(void){
    int arr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1) printf("Element not found\n");
    else printf("Element found at index %d\n", result);
    return 0;
}

int binarySearch(int arr[], int l, int r, int x){
    if (r >= l){
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}