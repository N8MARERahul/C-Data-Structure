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
	}
	else {
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
void infixToPostfix(char* infix) { 
	char postfix[MAX_SIZE];
	int i = 0, j = 0;
	while (infix[i] != '\0') { 
		char token = infix[i];
		if (token >= 'a' && token <= 'z' || token >= 'A' && token <= 'Z') 
			postfix[j++] = token;
		else if (token == '(')
			push(token);
		else if (token == ')') {
			while (stack[top] != '(') 
				postfix[j++] = pop();
			top--;
		} else {
			while (top != -1 && precedence(stack[top]) >= precedence(token)) 
				postfix[j++] = pop();
			push(token);
		} 
		i++;
	}
	while (top != -1)
		postfix[j++] = pop();
	postfix[j] = '\0';
	printf("Postfix Expression: %s\n", postfix);
}
int main() {
	char infix[MAX_SIZE];
	printf("Enter an Infix Expression: "); 
	scanf("%s", infix); 
	infixToPostfix(infix);
	return 0;
}
