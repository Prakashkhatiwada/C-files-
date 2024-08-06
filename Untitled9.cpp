#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    // Input the numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Input the operator
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform arithmetic operations based on the operator
    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;

        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero\n");
            }
            break;

        default:
            printf("Error: Invalid operator\n");
            break;
    }

    return 0;
}

