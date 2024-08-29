#include <stdio.h>
#include <string.h>

int main() {
    char Class_ID[2]; // Define Class_ID as an array of characters

    printf("\t\tTYPES OF WARSHIP\n");
    printf("\nInput Class ID (B, C, D, F): ");
    scanf("%2s", Class_ID); // Read up to 2 characters into Class_ID

    printf("Class type: ");

    // Check the length of the input string to have a precise output
    if (strlen(Class_ID) > 1) {
        printf("Not a War Ship\n");
    } else {
        // Check the first character
        switch (Class_ID[0]) {
            case 'B':
            case 'b':
                printf("Battleship\n");
                break;
            case 'C':
            case 'c':
                printf("Cruiser\n");
                break;
            case 'D':
            case 'd':
                printf("Destroyer\n");
                break;
            case 'F':
            case 'f':
                printf("Trigate\n");
                break;
            default:
                printf("Not a War Ship\n");
                break;
        }
    }

    return 0;
}
