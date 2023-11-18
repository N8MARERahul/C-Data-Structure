/*
1. Write a Menu driven C program to accomplish the following functionalities in single linked list.
a) Create a single linked list.
b) Display the elements of a single linked list.
c) Insert a node at the beginning of a single linked list.
d) Insert a node at the end of a single linked list.
e) Insert a node before a given node of a single linked list.
f) Insert a node after a given node of a single linked list.
g) Delete a node from the beginning of a single linked list.
h) Delete a node from the end of a single linked list.
i) Delete a node after a given node of a single linked list.
j) Delete the entire single linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the elements of the single linked list
void display() {
    struct Node* current = head;
    if (current == NULL) {
        printf("The single linked list is empty.\n");
        return;
    }

    printf("Single Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the single linked list
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to insert a node at the end of the single linked list
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Node with data %d inserted at the end.\n", data);
}

// Function to insert a node before a given node of the single linked list
void insertBefore(int data, int key) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        printf("The single linked list is empty. Cannot insert before a given node.\n");
        return;
    }

    if (head->data == key) {
        newNode->next = head;
        head = newNode;
        printf("Node with data %d inserted before the node with data %d.\n", data, key);
        return;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data != key) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Node with data %d not found. Cannot insert before a given node.\n", key);
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Node with data %d inserted before the node with data %d.\n", data, key);
    }
}

// Function to insert a node after a given node of the single linked list
void insertAfter(int data, int key) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        printf("The single linked list is empty. Cannot insert after a given node.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with data %d not found. Cannot insert after a given node.\n", key);
    } else {
        newNode->next = current->next;
        current->next = newNode;
        printf("Node with data %d inserted after the node with data %d.\n", data, key);
    }
}

// Function to delete a node from the beginning of the single linked list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("The single linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete a node from the end of the single linked list
void deleteFromEnd() {
    if (head == NULL) {
        printf("The single linked list is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    struct Node* temp = current->next;
    current->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}

// Function to delete a node after a given node of the single linked list
void deleteAfter(int key) {
    if (head == NULL) {
        printf("The single linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Node with data %d not found or no node to delete after it.\n", key);
    } else {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        printf("Node deleted after the node with data %d.\n", key);
    }
}

// Function to delete the entire single linked list
void deleteLinkedList() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL;
    printf("Single linked list deleted.\n");
}

int main() {
    int choice, data, key;

    while (1) {
        printf("\nSingle Linked List Operations Menu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the single linked list\n");
        printf("3. Insert a node at the beginning\n");
        printf("4. Insert a node at the end\n");
        printf("5. Insert a node before a given node\n");
        printf("6. Insert a node after a given node\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node after a given node\n");
        printf("10. Delete the entire single linked list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for the first node: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the data of the node before which you want to insert: ");
                scanf("%d", &key);
                insertBefore(data, key);
                break;
            case 6:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the data of the node after which you want to insert: ");
                scanf("%d", &key);
                insertAfter(data, key);
                break;
            case 7:
                deleteFromBeginning();
                break;
            case 8:
                deleteFromEnd();
                break;
            case 9:
                printf("Enter the data of the node after which you want to delete: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 10:
                deleteLinkedList();
                break;
            case 11:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
