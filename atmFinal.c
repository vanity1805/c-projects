#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maintainingBALANCE 100

typedef struct {
    char accNum[6];  // 5 characters + null terminator
    char PIN[5];     // 4 characters + null terminator
    float balance;
} ACCOUNT;

void atmSimulator(FILE *file);
void balanceInquiry(ACCOUNT *account);
void deposit(ACCOUNT *account);
void withdraw(ACCOUNT *account);
ACCOUNT* findAccount(FILE *file, const char *accountNumber, const char *PIN);
void updateAccount(FILE *file, ACCOUNT *account);

int main() {
    FILE *file = fopen("accounts.dat", "a+");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    ACCOUNT account;

    printf("Enter three unique records\n");
    for (int i = 0; i < 3; i++) {
        printf("\nEnter Account Number: ");
        scanf("%s", account.accNum);
        printf("Enter PIN: ");
        scanf("%s", account.PIN);
        account.balance = maintainingBALANCE;

        fwrite(&account, sizeof(ACCOUNT), 1, file);
    }

    int choice;
    while (1) {
        printf("\n=========================================================\n");
        printf("\n1. ATM Simulator\n");
        printf("2. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n=========================================================\n");

        switch (choice) {
            case 1:
                atmSimulator(file);
                break;
            case 2:
                fclose(file);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    fclose(file);
    return 0;
}

void atmSimulator(FILE *file) {
    char accountNumber[6];
    char PIN[5];

    printf("Enter Account Number: ");
    scanf("%5s", accountNumber);
    printf("Enter PIN: ");
    scanf("%4s", PIN);

    ACCOUNT *account = findAccount(file, accountNumber, PIN);
    if (account == NULL) {
        printf("Invalid account number or PIN.\n");
        return;
    }

    int choice;
    while (1) {
        printf("\n=========================================================\n");
        printf("\nWelcome to PUP-On-Line Banking Systems!\n");
        printf("\n\t1. Balance Inquiry\n");
        printf("\t2. Deposit\n");
        printf("\t3. Withdraw\n");
        printf("\t4. Exit\n");
        printf("\n\tPress the number of your choice: ");
        scanf("%d", &choice);
        printf("\n=========================================================\n");

        switch (choice) {
            case 1:
                balanceInquiry(account);
                break;
            case 2:
                deposit(account);
                break;
            case 3:
                withdraw(account);
                break;
            case 4:
                updateAccount(file, account);
                free(account);
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void balanceInquiry(ACCOUNT *account) {
    printf("Current balance: %.2f\n", account->balance);
}

void deposit(ACCOUNT *account) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        account->balance += amount;
        printf("Deposit successful. New balance: %.2f\n", account->balance);
    } else {
        printf("\nInvalid amount. Please try again.\n");
    }
}

void withdraw(ACCOUNT *account) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account->balance - maintainingBALANCE) {
        account->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    } else {
        printf("\nInsufficient funds! Balance: %.2f\n", account->balance);
    }
}

ACCOUNT* findAccount(FILE *file, const char *accountNumber, const char *PIN) {
    ACCOUNT *account = (ACCOUNT*)malloc(sizeof(ACCOUNT));
    rewind(file);
    while (fread(account, sizeof(ACCOUNT), 1, file)) {
        if (strcmp(account->accNum, accountNumber) == 0 && strcmp(account->PIN, PIN) == 0) {
            return account;
        }
    }
    free(account);
    return NULL;
}

void updateAccount(FILE *file, ACCOUNT *account) {
    ACCOUNT temp;
    rewind(file);
    long pos;
    while ((pos = ftell(file)) != -1 && fread(&temp, sizeof(ACCOUNT), 1, file)) {
        if (strcmp(temp.accNum, account->accNum) == 0 && strcmp(temp.PIN, account->PIN) == 0) {
            fseek(file, pos, SEEK_SET);
            fwrite(account, sizeof(ACCOUNT), 1, file);
            fflush(file);
            return;
        }
    }
}
