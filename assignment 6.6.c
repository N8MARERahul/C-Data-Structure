#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_SIZE 100 
int stack[MAX_SIZE]; 
int top = -1;
void push(int value) {
	if (top == MAX_SIZE - 1) { 
		printf("Stack Overflow\n"); 
		exit(1);
	} else {
		top++;
		stack[top] = value;
	}
}
int pop() {
	if (top == -1) {
		printf("Stack Underflow\n"); 
		exit(1);
	} else
		return stack[top--];
}
int evaluatePrefix(char* prefix) { 
	int length = strlen(prefix), i;
	for (i = length - 1; i >= 0; i--) { 
		char token = prefix[i];
		if (token >= '0' && token <= '9')  
			push(token - '0');
		else {
			int a = pop(); 
			int b = pop(); 
			switch (token) {
				case '+': 
					push(a + b); 
					break;
				case '-':
					push(a - b); 
					break;
				case '*': 
					push(a * b); 
					break;
				case '/': 
					push(a / b); 
					break;
			}
		}
	}
	return stack[top];
}
int main() {
	char prefix[MAX_SIZE];
	printf("Enter a Prefix Expression: "); 
	scanf("%s", prefix);
	int result = evaluatePrefix(prefix); 
	printf("Result: %d\n", result); 
	return 0;
}

