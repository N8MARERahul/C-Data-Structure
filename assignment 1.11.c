//11. Write a C program to check duplicate number in an array.

#include <stdio.h>

int main() {
	int len, i, j, count = 0;

	printf("Enter the lenght of the array: ");
	scanf("%d", &len);
	int arr[len];
  	printf("Enter the elements of the array-->\n");
	for (i = 0; i < len; i++) {
		printf("%d element: ", i + 1);
    	scanf("%d", &arr[i]);
	}

	for (i = 0; i < len; i++)
		for (j = i + 1; j < len; j++)
    		if (arr[i] == arr[j]) {
        		count++;
        		break;
      		}


	if (count == 0)
    	printf("No duplicates found in the array.\n");
	else 
    	printf("Number of duplicates found in the array = %d\n", count);
    return 0;
}
