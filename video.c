#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VIDEO 10
#define RENTAL_FEE_PER_DAY 10.00
#define FINE_PER_DAY 25.00
#define ALLOWABLE_RENTAL_DAYS 3

typedef struct {
    int number;
    char type[10];
    char vClass[10];
    char title[50];
    float price;
} VIDEO;

typedef struct {
    int accNo;
    char custName[30];
} CUSTOMER;

void addRecord(FILE *file);
void displayRecord(FILE *file);
void displaySpecificRecord(FILE *file, int videoNumber);
void displayBilling(FILE *file, int videoNumber, int rentalDays);

int main() {
    FILE *file = fopen("video.txt", "a+");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int choice;
    while (1) {
        printf("1. Enter New Record\n");
        printf("2. Display All Records\n");
        printf("3. Display Specific Record\n");
        printf("4. Display Billing\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecord(file);
                break;
            case 3: {
                int videoNumber;
                printf("Enter video number: ");
                scanf("%d", &videoNumber);
                displaySpecificRecord(file, videoNumber);
                break;
            }
            case 4: {
                int videoNumber, rentalDays;
                printf("Enter video number: ");
                scanf("%d", &videoNumber);
                printf("Enter the number of rental days: ");
                scanf("%d", &rentalDays);
                displayBilling(file, videoNumber, rentalDays);
                break;
            }
            case 5:
                fclose(file);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    fclose(file);
    return 0;
}

void addRecord(FILE *file) {
    VIDEO video;
    CUSTOMER customer;

    printf("\n=========================================================\n");
    printf("\t\tWelcome to ABC VIDEO RENTAL SHOP!\n");
    printf("\nEnter account number: ");
    scanf("%d", &customer.accNo);
    printf("Enter customer name: ");
    getchar();
    fgets(customer.custName, sizeof(customer.custName), stdin);
    customer.custName[strcspn(customer.custName, "\n")] = 0;

    printf("\nCustomer No. %d logged in!\n", customer.accNo);
    if (fwrite(&customer, sizeof(CUSTOMER), 1, file) != 1) {
        printf("Error writing customer record.\n");
        return;
    }

    printf("\nEnter video number: ");
    scanf("%d", &video.number);
    printf("Enter type of video: ");
    scanf("%s", video.type);
    printf("Enter video classification: ");
    scanf("%s", video.vClass);
    printf("Enter video title: ");
    getchar();
    fgets(video.title, sizeof(video.title), stdin);
    video.title[strcspn(video.title, "\n")] = 0;

    printf("\nNew record added!\n");
    printf("\n=========================================================\n");
    if (fwrite(&video, sizeof(VIDEO), 1, file) != 1) {
        printf("Error writing video record.\n");
        return;
    }

    fflush(file);
}

void displayRecord(FILE *file) {
    rewind(file);

    VIDEO video;
    CUSTOMER customer;


    while (fread(&customer, sizeof(CUSTOMER), 1, file) == 1) {
        if (fread(&video, sizeof(VIDEO), 1, file) == 1) {
            printf("\n=========================================================\n");
            printf("\t\tVideo Records:\n");
            printf("\nVideo Number: %d\n", video.number);
            printf("Type: %s\n", video.type);
            printf("Classification: %s\n", video.vClass);
            printf("Title: %s\n", video.title);
            printf("\n=========================================================\n");
        } else {
            printf("Error reading video record.\n");
            break;
        }
    }
}

void displaySpecificRecord(FILE *file, int videoNumber) {
    rewind(file);

    VIDEO video;
    CUSTOMER customer;
    int found = 0;

    while (fread(&customer, sizeof(CUSTOMER), 1, file) == 1) {
        if (fread(&video, sizeof(VIDEO), 1, file) == 1) {
            if (video.number == videoNumber) {
                printf("\n=========================================================\n");
                printf("\t\tSPECIFIC RECORD:\n");
                printf("\nVideo Number: %d\n", video.number);
                printf("Type: %s\n", video.type);
                printf("Classification: %s\n", video.vClass);
                printf("Title: %s\n", video.title);
                printf("\n=========================================================\n");
                found = 1;
                break;
            }
        } else {
            printf("Error reading video record.\n");
            break;
        }
    }

    if (!found) {
        printf("No record found for video number %d.\n", videoNumber);
    }
}

void displayBilling(FILE *file, int videoNumber, int rentalDays) {
    rewind(file);

    VIDEO video;
    CUSTOMER customer;
    int found = 0;

    while (fread(&customer, sizeof(CUSTOMER), 1, file) == 1) {
        if (fread(&video, sizeof(VIDEO), 1, file) == 1) {
            if (video.number == videoNumber) {
                float totalBill = rentalDays * RENTAL_FEE_PER_DAY;
                if (rentalDays > ALLOWABLE_RENTAL_DAYS) {
                    int excessDays = rentalDays - ALLOWABLE_RENTAL_DAYS;
                    totalBill += excessDays * FINE_PER_DAY;
                }

                printf("\n=========================================================\n");
                printf("\t\tABC VIDEO RENTAL SHOP:\n");
                printf("\nCustomer Account Number: %d\n", customer.accNo);
                printf("Customer Name: %s\n", customer.custName);
                printf("Video Number: %d\n", video.number);
                printf("Video Title: %s\n", video.title);
                printf("Rental Fee (per day): %.2f\n", RENTAL_FEE_PER_DAY);
                printf("Number of Days Borrowed: %d\n", rentalDays);
                printf("\nBILLING: %.2f\n", totalBill);
                printf("\n=========================================================\n");
                found = 1;
                break;
            }
        } else {
            printf("Error reading video record.\n");
            break;
        }
    }

    if (!found) {
        printf("No record found for video number %d.\n", videoNumber);
    }
}
