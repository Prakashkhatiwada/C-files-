#include <stdio.h>

// Function to transpose a matrix
void transposeMatrix(int rows, int cols, int mat[][cols], int result[][rows]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = mat[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int mat[][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input matrix
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Display original matrix
    printf("Original Matrix:\n");
    displayMatrix(3, 4, matrix);

    // Transpose matrix
    int result[4][3];
    transposeMatrix(3, 4, matrix, result);

    // Display transposed matrix
    printf("\nTransposed Matrix:\n");
    displayMatrix(4, 3, result);

    return 0;
}

