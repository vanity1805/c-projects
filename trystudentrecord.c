#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
    char sex[10];
    int birthDay;
    int birthMonth;
    int birthYear;
} Student;

void addStudentRecord(FILE *file);
void sortStudentsByName(FILE *file);
void printStudentsWithSameBirthMonth(FILE *file, int month);
int compareNames(const void *a, const void *b);

int main() {
    FILE *file = fopen("students.txt", "a+");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit (1);
    }

    int choice, month;
    while (1) {
        printf("1. Add Student Record\n");
        printf("2. Sort Students by Name\n");
        printf("3. Print Students with Same Birth Month\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudentRecord(file);
                break;
            case 2:
                sortStudentsByName(file);
                break;
            case 3:
                printf("Enter the birth month (1-12): ");
                scanf("%d", &month);
                printStudentsWithSameBirthMonth(file, month);
                break;
            case 4:
                fclose(file);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    fclose(file);
    return 0;
}

void addStudentRecord(FILE *file) {
    Student student;

    printf("Enter name (Last Name, First Name): ");
    scanf("%s", student.name);
    printf("Enter age: ");
    scanf("%d", &student.age);
    printf("Enter sex: ");
    scanf("%s", student.sex);
    printf("Enter birth day: ");
    scanf("%d", &student.birthDay);
    printf("Enter birth month: ");
    scanf("%d", &student.birthMonth);
    printf("Enter birth year: ");
    scanf("%d", &student.birthYear);

    fwrite(&student, sizeof(Student), 1, file);
    fflush(file);
}

void sortStudentsByName(FILE *file) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int i;

    rewind(file);
    while (fread(&students[count], sizeof(Student), 1, file)) {
        count++;
    }

    qsort(students, count, sizeof(Student), compareNames);

    freopen("students.txt", "w", file);
    for (i = 0; i < count; i++) {
        fwrite(&students[i], sizeof(Student), 1, file);
    }
    fflush(file);

    printf("Students sorted by name.\n");
}

void printStudentsWithSameBirthMonth(FILE *file, int month) {
    Student student;

    rewind(file);
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.birthMonth == month) {
            printf("Name: %s, Age: %d, Sex: %s, Birthday: %02d-%02d-%04d\n",
                   student.name, student.age, student.sex, student.birthDay, student.birthMonth, student.birthYear);
        }
    }
}

int compareNames(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}
  
