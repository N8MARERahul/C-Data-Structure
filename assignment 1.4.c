//WAP to sort an array.

#include <stdio.h>

int main() {
    int i, j, temp, len;
    printf("Enter the length the array: ");
    scanf("%d", &len); 
    int arr[len];
    printf("Enter the elemets \n");
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    printf("The array before sort are given below \n");
    for (i = 0; i < len; i++)
        printf("%d\t", arr[i]);

    for (i = 0; i < len; i++)
        for (j = i + 1; j < len; j++)
            if (arr[i] > arr[j]) {
                temp =  arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    printf("\nThe array after sort are given below \n");
    for (i = 0; i < len; i++)
        printf("%d\t", arr[i]);
 	return 0;
}
