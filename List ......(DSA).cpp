#include <stdio.h>

#define MAX_SIZE 100

// Function to create a list
int createList(int list[]) {
    int size;
    printf("Enter the size of the list: ");
    scanf("%d", &size);

    printf("Enter the elements of the list:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &list[i]);
    }

    return size;
}

// Function to insert an element at a specified position
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

// Function to delete an element from a specified position
void deleteAtPosition(int list[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }

    // Shift elements to the left to fill the gap created by deletion
    for (int i = position; i < *size - 1; i++) {
        list[i] = list[i + 1];
    }

    (*size)--;
}

// Function to modify an element at a specified position
void modifyElement(int list[], int size, int position, int newValue) {
    if (position < 0 || position >= size) {
        printf("Invalid position for modification.\n");
        return;
    }

    list[position] = newValue;
}

// Function to display the list
void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to display the transpose of the list
void displayTranspose(int list[], int size) {
    printf("Transpose of the list: ");
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

// Function to move elements of two arrays
void moveArrays(int list1[], int *size1, int list2[], int *size2) {
    if (*size1 + *size2 > MAX_SIZE) {
        printf("Combined size of arrays exceeds maximum allowed size.\n");
        return;
    }

    // Move elements of list2 to list1
    for (int i = 0; i < *size2; i++) {
        list1[*size1 + i] = list2[i];
    }

    // Update sizes of lists
    *size1 += *size2;
    *size2 = 0;
}

int main() {
    int list1[MAX_SIZE], list2[MAX_SIZE];
    int size1 = 0, size2 = 0;

    printf("Creating list 1:\n");
    size1 = createList(list1);
    printf("Creating list 2:\n");
    size2 = createList(list2);

    printf("\nInitial ");
    displayList(list1, size1);
    displayList(list2, size2);

    int position, element;

    printf("\nEnter position to insert into list 1: ");
    scanf("%d", &position);
    printf("Enter element to insert into list 1: ");
    scanf("%d", &element);
    insertAtPosition(list1, &size1, position, element);

    printf("\nList 1 after insertion: ");
    displayList(list1, size1);

    printf("\nEnter position to delete from list 2: ");
    scanf("%d", &position);
    deleteAtPosition(list2, &size2, position);

    printf("\nList 2 after deletion: ");
    displayList(list2, size2);

    int modifyPosition, modifyValue;
    printf("\nEnter position to modify in list 1: ");
    scanf("%d", &modifyPosition);
    printf("Enter new value: ");
    scanf("%d", &modifyValue);
    modifyElement(list1, size1, modifyPosition, modifyValue);

    printf("\nList 1 after modification: ");
    displayList(list1, size1);

    printf("\nTranspose of list 2: ");
    displayTranspose(list2, size2);

    printf("\nMoving elements of list 2 to list 1...\n");
    moveArrays(list1, &size1, list2, &size2);

    printf("\nList 1 after moving: ");
    displayList(list1, size1);
    printf("List 2 after moving: ");
    displayList(list2, size2);

    return 0;
}

