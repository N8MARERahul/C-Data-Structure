//9. Write a C program to print reverse array.

#include<stdio.h>

int main() {
	int len, i;
	printf("Enter the length of the array \n");
    scanf("%d", &len);
    int arr[len];
    printf("Enter the elements \n");
    for (i = 0; i < len; i++)
        scanf("%d", &arr[i]);
    printf ("The array is->\n");
    for (i = 0; i < len; i++)
        printf("%d\t", arr[i]);
    printf ("\nThe reverse of the array is->\n");
    for (i = len - 1; i >= 0; i--)
        printf("%d\t", arr[i]);
	return 0;
}
