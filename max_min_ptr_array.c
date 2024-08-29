#include <stdio.h>
#include <stdlib.h>

int findMin(int *ptr, int rows, int columns) {
    int min = *ptr;
    for (int i = 0; i < rows * columns; i++) {
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }
    return min;
}

int findMax(int *ptr, int rows, int columns) {
    int max = *ptr;
    for (int i = 0; i < rows * columns; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }
    return max;
}

int main() {
    int rows, columns;

    printf("WELCOME TO THE POINTER VERSION\n\n");

    printf("Enter size of rows: ");
    scanf("%d", &rows);
    printf("Enter size of columns: ");
    scanf("%d", &columns);
    printf("\n");

    int *numbers = (int *)malloc(rows * columns * sizeof(int));

    printf("Enter real numbers:\n");
    for (int i = 0; i < rows * columns; i++) {
        scanf("%d", &numbers[i]);
    }
    printf("\n");

    printf("Entered values:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", numbers[i * columns + j]);
        }
        printf("\n");
    }

    int *ptr = numbers;

    int lowest = findMin(ptr, rows, columns);
    int highest = findMax(ptr, rows, columns);

    printf("\nThe minimum element of the 2D Array is: %d\n", lowest);
    printf("The maximum element of the 2D Array is: %d\n", highest);



    return 0;
}
