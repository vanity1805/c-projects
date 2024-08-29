#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 4

typedef struct {
    int row;
    char col;
    bool isOccupied;
} Seat;

void initializeSeats(Seat seats[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j].row = i + 1;
            seats[i][j].col = 'A' + j;
            seats[i][j].isOccupied = false;
        }
    }
}

void displaySeats(Seat seats[ROWS][COLS]) {
    printf("Current seating arrangement:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", seats[i][0].row);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j].isOccupied) {
                printf("X ");
            } else {
                printf("%c ", seats[i][j].col);
            }
        }
        printf("\n");
    }
}

void assignSeat(Seat seats[ROWS][COLS], int row, char col) {
    int colIndex = col - 'A';
    if (seats[row-1][colIndex].isOccupied) {
        printf("Seat %d%c is already occupied. Please choose another seat.\n", row, col);
    } else {
        seats[row-1][colIndex].isOccupied = true;
        printf("Seat %d%c assigned successfully.\n", row, col);
    }
}

int main() {
    Seat seats[ROWS][COLS];
    initializeSeats(seats);

    int row;
    char col;
    char choice;

    do {
        displaySeats(seats);
        printf("Enter the seat to assign (e.g., 1A): ");
        scanf("%d%c", &row, &col);

        if (row < 1 || row > ROWS || col < 'A' || col > 'A' + COLS - 1) {
            printf("Invalid seat. Please enter a valid seat.\n");
        } else {
            assignSeat(seats, row, col);
        }

        printf("Do you want to assign another seat? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Final seating arrangement:\n");
    displaySeats(seats);

    return 0;
}
