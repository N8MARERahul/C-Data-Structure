//6. Write a C program to display Fibonacci series.

#include <stdio.h>

int main() {

	int num, i, t1 = 0, t2 = 1, next = t1 + t2;
	printf("Enter the terms of Fibonacci Series: ");
	scanf("%d", &num);
	printf("Fibonacci series-->\n");
	printf("%d\t%d\t", t1, t2);
	for (i = 2; i < num; i++) {
		printf("%d\t", next);
		t1 = t2;
		t2 = next;
		next = t1 + t2;
	}
	return 0;
}
