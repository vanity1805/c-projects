#include <stdio.h>

int main() {
    char sName[100];
    int aAnswer, bAnswer, cAnswer, dAnswer, eAnswer, total;
    float average;

    printf("Enter student name: ");
    scanf("%s", sName);

    printf("\nEnter Answer #1: ");
    scanf("%d", &aAnswer);

    printf("\nEnter Answer #2: ");
    scanf("%d", &bAnswer);

    printf("\nEnter Answer #3: ");
    scanf("%d", &cAnswer);

    printf("\nEnter Answer #4: ");
    scanf("%d", &dAnswer);

    printf("\nEnter Answer #5: ");
    scanf("%d", &eAnswer);

    if (aAnswer > 5)
        aAnswer = 0;

    if (bAnswer > 5)
        bAnswer = 0;

    if (cAnswer > 5)
        cAnswer = 0;

    if (dAnswer > 5)
        dAnswer = 0;

    if (eAnswer > 5)
        eAnswer = 0;

    total = aAnswer + bAnswer + cAnswer + dAnswer + eAnswer;
    average = (float)total / 5;

    printf("%s, your total score is %d and your average score is %.1f\n", sName, total, average);
    return 0;
}
