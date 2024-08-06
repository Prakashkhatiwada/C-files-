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
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the specified position
void insertNode(struct Node** head, int data, int position) {
  struct Node* newNode = createNode(data);
  struct Node* current = *head;

  // Traverse to the specified position
  for (int i = 0; i < position - 1 && current != NULL; i++) {
    current = current->next;
  }

  // Check if the position is valid
  if (current == NULL) {
    printf("Invalid position\n");
    return;
  }

  // Update the links of the new node and the adjacent nodes
  newNode->prev = current;
  newNode->next = current->next;
  if (current->next != NULL) {
    current->next->prev = newNode;
  }
  current->next = newNode;
}

// Function to delete a node at the specified position
void deleteNode(struct Node** head, int position) {
  struct Node* current = *head;

  // Traverse to the specified position
  for (int i = 0; i < position - 1 && current != NULL; i++) {
    current = current->next;
  }

  // Check if the position is valid
  if (current == NULL || current->next == NULL) {
    printf("Invalid position\n");
    return;
  }

  // Update the links of the adjacent nodes
  struct Node* nodeToDelete = current->next;
  current->next = nodeToDelete->next;
  if (nodeToDelete->next != NULL) {
    nodeToDelete->next->prev = current;
  }
  free(nodeToDelete);
}

// Function to print the contents of the doubly linked list
void printList(struct Node* head) {
  struct Node* current = head;
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// Test the insert and delete functions
int main() {
  struct Node* head = NULL;

  // Insert nodes at positions 0, 1, and 2
  insertNode(&head, 10, 0);
  insertNode(&head, 20, 1);
  insertNode(&head, 30, 2);
  printList(head);

  // Delete the node at position 1
  deleteNode(&head, 1);
  printList(head);

  // Insert a node at position 1
  insertNode(&head, 40, 1);
  printList(head);

  return 0;
}
