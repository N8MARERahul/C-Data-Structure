#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_SIZE 100 
char stack[MAX_SIZE]; 
int top = -1;
int precedence(char ch) { 
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/') 
		return 2;
	else
		return 0;
}
void push(char ch) {
	if (top == MAX_SIZE - 1) { 
		printf("Stack Overflow\n"); 
		exit(1);
	} else {
		top++; 
		stack[top] = ch;
	}
}
char pop() {
	if (top == -1) {
		printf("Stack Underflow\n"); 
		exit(1);
	} else
		return stack[top--];
}
void infixToPrefix(char* infix) { 
	int length = strlen(infix), i; 
	char prefix[MAX_SIZE];
	int j = 0;
	for (i = length - 1; i >= 0; i--) { 
		char token = infix[i];
		if (token >= 'a' && token <= 'z' || token >= 'A' && token <= 'Z')
			prefix[j++] = token;
		else if (token == ')')
			push(token);
		else if (token == '(') {
			while (stack[top] != ')')
				prefix[j++] = pop();
			top--;
		} else {
			while (top != -1 && precedence(stack[top]) > precedence(token))
				prefix[j++] = pop();
			push(token);
		}
	}
	while (top != -1)
		prefix[j++] = pop();
	for (i = 0; i < j / 2; i++) { 
		char temp = prefix[i]; 
		prefix[i] = prefix[j - i - 1]; 
		prefix[j - i - 1] = temp;
	}
	prefix[j] = '\0';
	printf("Prefix Expression: %s\n", prefix);
}
int main() {
	char infix[MAX_SIZE];
	printf("Enter an Infix Expression: "); 
	scanf("%s", infix); 
	infixToPrefix(infix);
	return 0;
}

