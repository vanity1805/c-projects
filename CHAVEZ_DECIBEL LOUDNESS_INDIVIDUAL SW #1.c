#include <stdio.h>

int main() {

    float decibelLoudness;

    //Prompts the User to input a decibel value
    printf("Input decibel loudness: ");
    scanf("%f", &decibelLoudness);

    printf("Loudness Type: ");

    //If-Else Statement for the Corresponding Loudness Type
    if (decibelLoudness <= 50.0) {
        printf("Quiet\n");
    } else if (decibelLoudness <= 70.0) {
        printf("Intrusive\n");
    } else if (decibelLoudness <= 90.0) {
        printf("Annoying\n");
    } else if (decibelLoudness <= 110.0) {
        printf("Very Annoying\n");
    } else {
        printf("Uncomfortable\n");
    }

    return 0;
}
