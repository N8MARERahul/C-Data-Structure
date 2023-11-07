//10. Write a C program to check the sum of all elements of an array.

#include<stdio.h>

int main() {
	int len, i, sum = 0;

	printf("Enter the lenght of the array: ");
	scanf("%d", &len);
	int arr[len];
  	printf("Enter the elements of the array-->\n");
	for (i = 0; i < len; i++) {
		printf("%d element: ", i + 1);
    	scanf("%d", &arr[i]);
	}
	for (i = 0; i < len; i++) {
		sum += arr[i];
		printf("%d + ", arr[i]);
	}
	printf("\b\b= %d", sum);	
	return 0;
}
