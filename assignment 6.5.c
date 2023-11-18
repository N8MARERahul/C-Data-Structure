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
int evaluatePostfix(char* postfix) { 
	int i, a, b;
	for (i = 0; postfix[i] != '\0'; i++) { 
		char token = postfix[i];
		if (token >= '0' && token <= '9') 
			push(token - '0');
		else {
			a = pop();
			b = pop(); 
			switch (token) {
				case '+': 
					push(b + a); 
					break;
				case '-':
					push(b - a); 
					break;
				case '*': 
					push(b * a); 
					break;
				case '/': 
					push(b / a); 
					break;
			}
		}
	}
	return stack[top];
}
int main() {
	char postfix[MAX_SIZE]; 
	printf("Enter a Postfix Expression: "); 
	scanf("%s", postfix);
	int result = evaluatePostfix(postfix); 
	printf("Result: %d\n", result); 
	return 0;
}

