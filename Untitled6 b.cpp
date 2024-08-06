#include <stdio.h>

int main() {
    // Declare variables
    int number, digit, sum = 0;

    // Input a 5-digit number
    printf("Enter a 5-digit number: ");
    scanf("%d", &number);

    // Check if the number has exactly 5 digits
    if (number >= 10000 && number <= 99999) {
        // Calculate the sum of individual digits
        while (number > 0) {
            digit = number % 10;  // Extract the last digit
            sum += digit;         // Add the digit to the sum
            number /= 10;         // Remove the last digit
        }

        // Print the result
        printf("Sum of individual digits: %d\n", sum);
    } else {
        // Print an error message if the input is not a 5-digit number
        printf("Error: Please enter a 5-digit number.\n");
    }

    return 0;
}

