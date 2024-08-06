#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node with given data at a specified position
void insertNode(struct Node** headRef, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    // If position is 0, insert at the beginning
    if (position == 0) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        struct Node* current = *headRef;
        int currentPosition = 0;
        // Traverse to the node before the position
        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }
        // If position is out of range
        if (current == NULL) {
            printf("Invalid position for insertion.\n");
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete a node at a specified position
void deleteNode(struct Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *headRef;

    // If position is 0, delete the first node
    if (position == 0) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    // Find the node before the position to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Node temp->next is the node to be deleted
    struct Node* nextNode = temp->next->next;
    free(temp->next);
    temp->next = nextNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 1);
    insertNode(&head, 3, 2);
    insertNode(&head, 4, 3);
    insertNode(&head, 5, 4);

    printf("Initial list: ");
    printList(head);

    // Insert at position 2
    insertNode(&head, 10, 2);
    printf("List after inserting 10 at position 2: ");
    printList(head);

    // Delete node at position 3
    deleteNode(&head, 3);
    printf("List after deleting node at position 3: ");
    printList(head);

    return 0;
}

