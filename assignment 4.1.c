#include <stdio.h>
#include <stdlib.h>

// Node structure for a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList() {
	struct Node * current = head;
    printf("Doubly Linked List:\nNULL <-> ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
    	head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
    	head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to insert a node before a given node
void insertBeforeNode(int data, int key) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
    	head = newNode;
        return;
    }
    if (head->data == key) {
        newNode->next = head;
        head->prev = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Key not found in the list.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Function to insert a node after a given node
void insertAfterNode(int data, int key) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key not found in the list.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head -> next == NULL) {
    	free(head);
    	head = NULL;
	}
    struct Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node after a given node
void deleteAfterNode(int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Key not found or no node after the key to delete.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
}

// Function to delete the entire list
void deleteList() {
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire list deleted.\n");
}

int main() {
    int choice, data, key;

    do {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Create a doubly linked list\n");
        printf("2. Display the list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a given node\n");
        printf("6. Insert after a given node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete the entire list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a doubly linked list
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                head = createNode(data);
                break;

            case 2:
                // Display the elements of the doubly linked list
                displayList();
                break;

            case 3:
                // Insert at the beginning
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 4:
                // Insert at the end
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 5:
                // Insert before a given node
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the key value before which to insert: ");
                scanf("%d", &key);
                insertBeforeNode(data, key);
                break;

            case 6:
                // Insert after a given node
                printf("Enter data for the new node: ");
                scanf("%d", &data);
                printf("Enter the key value after which to insert: ");
                scanf("%d", &key);
                insertAfterNode(data, key);
                break;

            case 7:
                // Delete from the beginning
                deleteFromBeginning();
                break;

            case 8:
                // Delete from the end
                deleteFromEnd();
                break;

            case 9:
                // Delete after a given node
                printf("Enter the key value after which to delete: ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;

            case 10:
                // Delete the entire list
                deleteList();
                break;

            case 0:
                // Exit the program
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
