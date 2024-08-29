#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char accountNumber[6];  // 5 characters + null terminator
    char PIN[5];            // 4 characters + null terminator
    float balance;
} Account;

void addAccountRecords(const char *filename);
void atmSimulator(const char *filename);
void balanceInquiry(Account *account);
void deposit(Account *account);
void withdraw(Account *account);
Account* findAccount(const char *filename, const char *accountNumber, const char *PIN);

int main() {
    const char *filename = "accounts.dat";

    int choice;
    while (1) {
        printf("1. Add Account Records\n");
        printf("2. ATM Simulator\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccountRecords(filename);
                break;
            case 2:
                atmSimulator(filename);
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void addAccountRecords(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char another = 'Y';

    while (another == 'Y' || another == 'y') {
        Account account;

        printf("Enter account details:\n");
        printf("Account Number (5 characters): ");
        scanf("%5s", account.accountNumber);
        printf("PIN (4 characters): ");
        scanf("%4s", account.PIN);
        printf("Balance: ");
        scanf("%f", &account.balance);

        // Write account to file
        fwrite(&account, sizeof(Account), 1, file);

        printf("Account record has been written.\n");
        printf("Do you want to add another account? (Y/N): ");
        getchar(); // To consume the newline character left by previous scanf
        another = getchar();
    }

    fclose(file);
}

void atmSimulator(const char *filename) {
    char accountNumber[6];
    char PIN[5];

    printf("Enter your account number: ");
    scanf("%5s", accountNumber);
    printf("Enter your PIN: ");
    scanf("%4s", PIN);

    Account *account = findAccount(filename, accountNumber, PIN);
    if (account == NULL) {
        printf("Invalid account number or PIN.\n");
        return;
    }

    int choice;
    while (1) {
        printf("\n1. Balance Inquiry\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Press the number of your choice: ");
        scanf("%d", &choice);

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
                free(account);
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

Account* findAccount(const char *filename, const char *accountNumber, const char *PIN) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Account *account = (Account*) malloc(sizeof(Account));
    while (fread(account, sizeof(Account), 1, file) == 1) {
        if (strcmp(account->accountNumber, accountNumber) == 0 && strcmp(account->PIN, PIN) == 0) {
            fclose(file);
            return account;
        }
    }

    fclose(file);
    free(account);
    return NULL;
}

void balanceInquiry(Account *account) {
    printf("Your balance is: %.2f\n", account->balance);
}

void deposit(Account *account) {
    float amount;
    printf("Enter the amount to deposit: ");
    scanf("%f", &amount);
    account->balance += amount;
    printf("Deposit successful. New balance is: %.2f\n", account->balance);
}

void withdraw(Account *account) {
    float amount;
    printf("Enter the amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. New balance is: %.2f\n", account->balance);
    }
}
