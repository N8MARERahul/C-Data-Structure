// Write a c program to check whether a given string is palindrome or not

#include<stdio.h>
#include<string.h>

int main() {
	char str[100];
	int l = 0, h;
	printf("Enter a string: ");
	gets(str);
	
	h = strlen(str) - 1;
	while (h > l) {
		if (str[l++] != str[h--]) {
			printf("%s is not a palindrome\n", str);
			return 0;
		}
	}
	printf("%s is a palindrome\n", str);
	return 0;
}
