#include <stdio.h>

#define MAX_SIZE 100

// Function to insert element at specified position
void insertAtPosition(int list[], int *size, int position, int element) {
    if (*size >= MAX_SIZE) {
        printf("List is full, insertion failed.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the element at the specified position
    list[position] = element;
    (*size)++;
}

// Function to print the list
void printList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE] = {1, 2, 3, 4, 5};
    int size = 5; // Current size of the list

    printf("Initial ");
    printList(list, size);

    int position, element;
    printf("Enter position to insert: ");
    scanf("%d", &position);
    printf("Enter element to insert: ");
    scanf("%d", &element);

    insertAtPosition(list, &size, position, element);

    printf("List after insertion: ");
    printList(list, size);

    return 0;
}

