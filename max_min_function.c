#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLUMNS 10

// Function to find the minimum element in the 2D array
int findMin(int numbers[][MAX_COLUMNS], int rows, int columns) {
    int lowest = numbers[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (numbers[i][j] < lowest) {
                lowest = numbers[i][j];
            }
        }
    }
    return lowest;
}

// Function to find the maximum element in the 2D array
int findMax(int numbers[][MAX_COLUMNS], int rows, int columns) {
    int highest = numbers[0][0];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (numbers[i][j] > highest) {
                highest = numbers[i][j];
            }
        }
    }
    return highest;
}

int main() {
    int numbers[MAX_ROWS][MAX_COLUMNS];
    int rows, columns;

    printf("WELCOME TO THE ARRAY VERSION\n\n");

    printf("Enter size of rows: ");
    scanf("%d", &rows);
    printf("\n");
    printf("Enter size of columns: ");
    scanf("%d", &columns);
    printf("\n");

    printf("Enter real numbers: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }
    printf("\n");

    // Printing the entered 2D array
    printf("2D ARRAY:\n\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Calling functions to find min and max

    printf("The minimum element of the 2D Array is: %d\n", findMin(numbers, rows, columns));
    printf("The maximum element of the 2D Array is: %d\n", findMax(numbers, rows, columns));

    return 0;
}
