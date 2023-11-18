#include <stdio.h> 
#include <stdlib.h> 
struct Node {
	int data;
	struct Node* next;
};
struct Node* top = NULL; 
void push(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
	newNode->data = value;
	newNode->next = top; 
	top = newNode;
	printf("Element pushed successfully.\n");
}
void pop() {
	if (top == NULL)
		printf("Stack Underflow\n");
	else {
		struct Node* temp = top;
		printf("Element popped: %d\n", temp->data); top = top->next;
		free(temp);
	}
}
void peek() {
	if (top == NULL)
		printf("Stack Underflow\n");
	else
		printf("Top element: %d\n", top->data);
}
void display() {
	if (top == NULL)
		printf("Stack Underflow\n");
	else {
		printf("Elements in the stack: "); 
		struct Node* current = top; 
		while (current != NULL) {
			printf("%d ", current->data); 
			current = current->next;
		}
		printf("\n");
	}
}
int main() {
	int choice, element;
	do {
		printf("\nStack Operations(Linked List Implementation):\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n"); 
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
				printf("Program Terminated\n"); 
				break;
			default:
				printf("Invalid choice.\n");
		}
	} while (choice != 5); 
	return 0;
}

