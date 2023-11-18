#include <stdio.h> 
#define MAX_SIZE 100 
int stack[MAX_SIZE]; 
int top = -1;

void push(int value) {
	if (top == MAX_SIZE - 1)
		printf("Stack Overflow\n");
	else { 
		top++;
		stack[top] = value;
		printf("Element pushed successfully.\n");
	}
}
void pop() {
	if (top == -1)
		printf("Stack Underflow\n");
	else {
		printf("Element popped: %d\n", stack[top]); 
		top--;
	}
}
void peek() {
	if (top == -1) 
		printf("Stack Underflow\n");
	else 
		printf("Top element: %d\n", stack[top]);
}
void display() { 
	int i;
	if (top == -1) 
		printf("Stack Underflow\n");
	else {
		printf("Elements in the stack: "); 
		for (i = top; i >= 0; i--)
			printf("%d ", stack[i]);
		printf("\n");
	}
}
int main() {
	int choice, element; 
	do {
		printf("\nStack Operations(Array Implementation):\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
		printf("Enter your choice: "); 
		scanf("%d", &choice); 
		switch (choice) {
			case 1: 
				printf("Enter element to push: "); 
				scanf("%d", &element); 
				push(element);
				break; 
			case 2: 
				pop(); 
				break; 
			case 3: 
				peek();
				break; 
			case 4:
				display(); 
				break; 
			case 5:
				printf("Exiting the program.\n"); 
				break;
			default:
				printf("Invalid choice, please enter a valid option.\n");
		}
	} while (choice != 5); 
	return 0;
}

