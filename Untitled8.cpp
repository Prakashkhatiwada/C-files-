#include <stdio.h>

// Function prototype
int sumOfNaturalNumbers(int n);

int main() {
    int n;

    // Input
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    // Checking if n is positive
    if (n <= 0) {
        printf("Please enter a positive integer.\n");
    } else {
        // Output
        printf("Sum of first %d natural numbers is %d\n", n, sumOfNaturalNumbers(n));
    }

    return 0;
}

// Recursive function to find the sum of first n natural numbers
int sumOfNaturalNumbers(int n) {
    // Base case
    if (n == 1) {
        return 1;
    } else {
        // Recursive case: sum of first n natural numbers is n + sumOfNaturalNumbers(n-1)
        return n + sumOfNaturalNumbers(n - 1);
    }
}

