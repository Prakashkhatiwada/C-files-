#include <stdio.h>

int main() {
    // Declare variables
    float num1, num2, result;
    char operator;

    // Input two numbers and an arithmetic operator
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    printf("Enter arithmetic operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform arithmetic operation based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            // Check if the second number is not zero to avoid division by zero
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                printf("Error: Division by zero!\n");
                return 1;  // Exit the program with an error code
            }
            break;
        default:
            printf("Error: Invalid operator!\n");
            return 1;  // Exit the program with an error code
    }

    // Display the result
    printf("Result: %.2f %c %.2f = %.2f\n", num1, operator, num2, result);

    return 0;
}

