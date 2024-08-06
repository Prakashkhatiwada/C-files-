
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold array and size information
struct Array {
    int *arr;
    int size;
};

// Function to perform bubble sort on the array
void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap the elements if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to display the sorted array
void displayArray(struct Array *array) {
    printf("Sorted Array: ");
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Array array;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &array.size);

    // Allocate memory for the array using DMA
    array.arr = (int *)malloc(array.size * sizeof(int));

    // Get the elements of the array from the user
    printf("Enter %d elements:\n", array.size);
    for (int i = 0; i < array.size; i++) {
        scanf("%d", &array.arr[i]);
    }

    // Perform bubble sort on the array
    bubbleSort(array.arr, array.size);

    // Display the sorted array
    displayArray(&array);

    // Free the dynamically allocated memory
    free(array.arr);

    return 0;
}
