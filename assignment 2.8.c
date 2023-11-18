#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Elements before reallocation:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int newSize;
    printf("\nEnter the new size for reallocation: ");
    scanf("%d", &newSize);
    int *newArr = (int *)realloc(arr, newSize * sizeof(int));
    if (newArr == NULL) {
        printf("Memory reallocation failed. Exiting...");
        free(arr); 
        return 1;
    }
    printf("\nEnter additional elements:\n");
    for (i = n; i < newSize; i++) {
        scanf("%d", &newArr[i]);
    }
    printf("Elements after reallocation:\n");
    for (i = 0; i < newSize; i++) {
        printf("%d ", newArr[i]);
    }
    free(newArr); 
    return 0;
}

