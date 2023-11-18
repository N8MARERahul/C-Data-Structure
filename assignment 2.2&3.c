#include <stdio.h>
void modifyByValue(int arr[], int size) {
	int i;
    printf("Array elements in the function (Call by Value):\n");
    for (i = 0; i < size; i++) {
        arr[i] += 10; 
        printf("%d ", arr[i]);}
    printf("\n");}
void modifyByReference(int *arr, int size) {
	int i;
    printf("Array elements in the function (Call by Reference):\n");
    for (i = 0; i < size; i++) {
        *arr += 5; 
        arr++;
        printf("%d ", *(arr - 1));  } printf("\n");}
void displayArray(int arr[], int size, const char *message) {
    int i;
	printf("%s\n", message);
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);  }
    printf("\n"); }
int main() {
	int n, i;
   printf("Enter the number of elements of array: ");
    scanf("%d", &n);
    int arr[n] ;
    printf("Enter the elements of the 2D array:\n");
    for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  }
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d",size);
    displayArray(arr, size, "Array elements in the main function:");
    modifyByValue(arr, size);
    displayArray(arr, size, "Array elements after Call by Value:");
    modifyByReference(arr, size);
    displayArray(arr, size, "Array elements after Call by Reference:");
    return 0; 
}

