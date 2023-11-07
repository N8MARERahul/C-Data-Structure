// Write a c program to print an array

#include<stdio.h>

int main () {
    int n, i;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the elements of the Array-->\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("The Array is -->\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
}