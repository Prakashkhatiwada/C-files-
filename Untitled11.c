#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the specified position
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
    } else {
        int count = 1;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position!\n");
            return;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
    }
    printf("Node inserted successfully!\n");
}

// Function to delete a node at the specified position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* current = *head;
    if (position == 1) {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
    } else {
        int count = 1;
        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position!\n");
            return;
        }
        if (current->next != NULL)
            current->next->prev = current->prev;
        current->prev->next = current->next;
        free(current);
    }
    printf("Node deleted successfully!\n");
}

// Function to print the contents of the doubly linked list
void printList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    // Inserting elements at specified positions
    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 2);
    insertAtPosition(&head, 40, 1);

    printList(head);

    // Deleting elements at specified positions
    deleteAtPosition(&head, 2);
    deleteAtPosition(&head, 1);

    printList(head);

    return 0;
}

