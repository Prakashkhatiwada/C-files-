#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to count the nodes in the linked list
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

// Main function
int main() {
    // Create a sample linked list
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;
    
    third->data = 3;
    third->next = NULL;
    
    // Count the nodes and print the result
    int nodeCount = countNodes(head);
    printf("Number of nodes in the linked list: %d\n", nodeCount);
    
    // Free dynamically allocated memory
    free(head);
    free(second);
    free(third);
    
    return 0;
}

