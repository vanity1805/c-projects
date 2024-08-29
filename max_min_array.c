#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLUMNS 10

int main() {
    int numbers[MAX_ROWS][MAX_COLUMNS];
    int i, j;
    int rows, columns;

    printf("WELCOME TO THE ARRAY VERSION \n");
    printf("\n");

    printf("Enter size of rows: ");
    scanf("%d", &rows);
    printf("\n");
    printf("Enter size of columns: ");
    scanf("%d", &columns);
    printf("\n");

    printf("Enter real numbers: ");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }
    printf("\n");

     int lowest = numbers[0][0];
     int highest = numbers[0][0];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            if(numbers[i][j] > highest){
                highest = numbers[i][j];
            }
            if(numbers[i][j] < lowest){
                lowest = numbers[i][j];
        }
    }
    }
    // Printing the entered 2D array
    printf("2D ARRAY:\n");
    printf("\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%d ", numbers[i][j]);
        }
        printf("\n");
    }
        printf("\n");
        printf("The minimum element of the 2D Array is: %d \n", lowest);
        printf("The maximum element of the 2D Array is: %d \n", highest);

    return 0;
}
