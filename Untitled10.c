#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at a specified position
void insertAtPos(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // If the list is empty or insertion at the beginning
    if (*head == NULL || position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    // Traverse to the desired position
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // Check if position is beyond the list length
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Insert after the found node
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Function to delete a node at a specified position
void deleteAtPos(struct Node** head, int position) {
    // If the list is empty or deletion at the beginning
    if (*head == NULL || position == 0) {
        if (*head == NULL) {
            printf("List is empty!\n");
            return;
        }
        struct Node* temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    // Traverse to the desired position
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    // Check if position is beyond the list length
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position!\n");
        return;
    }

    // Delete the found node
    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next != NULL) {
        delNode->next->prev = temp;
    }
    free(delNode);
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

    insertAtPos(&head, 10, 0);  // Insert at beginning
    insertAtPos(&head, 20, 1);  // Insert at position 1
    insertAtPos(&head, 30, 2);  // Insert at position 2 (end)
    printList(head);             // Output: Doubly Linked List: 10 20 30

    deleteAtPos(&head, 1);      // Delete at position 1
    printList(head);             // Output: Doubly Linked List: 10 30

    return 0;
}
