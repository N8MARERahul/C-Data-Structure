//5. Write a C program to print the largest and second largest element of the array.

#include <stdio.h>

int main() {
    int n, max, max2, i, has_max2 = 0;
    printf("Enter the length of the array \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf ("The array is->\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    max = arr[0];
    for (i = 0; i < n; i++) {
        if (max < arr[i]) {
            max2 = max;
            max = arr[i];
        } 
    }
    for (i = 0; i < n; i++) {
        if (arr[i] < max) {
            if (!has_max2) {
                has_max2 = 1;
                max2 = arr[i];
            } 
			else if (arr[i] > max2)
                max2 = arr[i];
        }
    }
    if (has_max2 == 1)
    	printf("\nLargest number = %d\n2nd Largest number = %d", max, max2);
    else
    	printf("\nAll values are identical to %d", max);
    return 0;
}
