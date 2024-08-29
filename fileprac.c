#include <stdio.h>
#include <conio.h>

int main(){

FILE *fptr;

    fptr = fopen("prac.txt", "w");
    char PRAC[100] = "C is a fun programming language.\nAnd, I love using C language";
    fprintf(fptr, "%s", PRAC);

fclose(fptr);

    fptr = fopen("prac.txt", "r");
    printf("%s", PRAC);

    return 0;
}
