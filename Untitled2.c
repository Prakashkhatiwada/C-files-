#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    // Traverse the linked list and count nodes
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to insert a new node at the beginning of the linked list
void push(struct Node** headRef, int newData) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Set data of new node
    newNode->data = newData;

    // Link the new node to the list
    newNode->next = *headRef;

    // Move the head to point to the new node
    *headRef = newNode;
}

int main() {
    // Initialize an empty linked list
    struct Node* head = NULL;

    // Insert some nodes
    push(&head, 3);
    push(&head, 7);
    push(&head, 11);
    push(&head, 5);
    push(&head, 5);

    // Count the number of nodes
    printf("Number of nodes in the linked list: %d\n", countNodes(head));

    return 0;
}

