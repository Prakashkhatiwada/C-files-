#include <stdio.h>
#include <conio.h>  // Only works on Windows, for getch()

void clearScreen() {

}

void drawCar(int position) {
    printf("   _______\n");
    printf(" //      \\\\\n");
    printf("||  [%d] [%d]  ||\n", position, position + 1);
    printf("||     -   ||\n");
    printf(" \\\\_______//\n");
}

int main() {
    int carPosition = 1;
    char userInput;

    do {
        clearScreen();
        drawCar(carPosition);

        printf("Use 'a' to move left, 'd' to move right, and 'q' to quit.\n");
        userInput = getch();  // Use _getch() on Windows, getch() on Linux

        switch (userInput) {
            case 'a':
                carPosition--;
                break;
            case 'd':
                carPosition++;
                break;
            case 'q':
                break;
            default:
                printf("Invalid input! Use 'a', 'd', or 'q'.\n");
                break;
        }
    } while (userInput != 'q');

    printf("Thanks for playing!\n");

    return 0;
}

