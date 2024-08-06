#include <stdio.h>
#include <stdlib.h>

/// @brief 
/// @return 
int main() {
    int size;

    // Get the size of memory from the user
    printf("Enter the size of memory: ");
    scanf("%d", &size);

    // Dynamically allocate memory using malloc
    int *dynamicArray = (int *)malloc(size * sizeof(int));

    // Check if memory allocation is successful
    if (dynamicArray == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit the program with an error code
    }

    // Input values into the dynamically allocated memory
    printf("Enter %d values:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &dynamicArray[i]);
    }

    // Display the values stored in the dynamically allocated memory
    printf("Values entered: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", dynamicArray[i]);
    }

    // Free the dynamically allocated memory
    free(dynamicArray);

    return 0; // Exit the program successfully
}

