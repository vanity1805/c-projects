#include <stdio.h>

int main() {
    float N;

    //Prompts the User to input a value
    printf("Input Value of Richter Scale (N): ");
    scanf("%f", &N);

    printf("Type of Damage: ");

    //If-Else Statement for the Corresponding Damages
    if (N < 5.0) {
        printf("LITTLE OR NO DAMAGE\n");
    } else if (N >= 5.0 && N < 5.5) {
        printf("THERE ARE SOME DAMAGES\n");
    } else if (N >= 5.5 && N < 6.5) {
        printf("THERE ARE SERIOUS DAMAGE!\n");
    } else if (N >= 6.5 && N < 7.5) {
        printf("DISASTER! HOUSE AND BUILDINGS MAY COLLAPSE\n");
    } else {
        printf("CATASTROPHE!\n");
    }

    return 0;
}
