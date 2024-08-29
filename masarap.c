#include <stdio.h>
#include <string.h>

// Define the structure for a menu item
typedef struct {
    char name[50];
    int qty;
    float unit_price;
    float amount;
} MenuItem;

// Function to calculate the amount for each menu item
void calculate_amount(MenuItem *item) {
    item->amount = item->qty * item->unit_price;
}

// Function to calculate the total bill, discount, net bill, and change
void calculate_billing(MenuItem items[], int num_items, float *total_bill, float *discount, float *net_bill, float *change, float amount_tendered, char discount_type) {
    *total_bill = 0;
    *discount = 0;

    for (int i = 0; i < num_items; i++) {
        *total_bill += items[i].amount;
    }

    if (*total_bill >= 100 && *total_bill <= 2000) {
        *discount = *total_bill * 0.02;
    }

    if (discount_type == 'P') {
        *discount = *total_bill * 0.05;
    } else if (discount_type == 'S') {
        *discount = *total_bill * 0.20;
    }

    *net_bill = *total_bill - *discount;

    if (amount_tendered >= *net_bill) {
        *change = amount_tendered - *net_bill;
    } else {
        *change = -1; // Indicates insufficient fund
    }
}

// Function to display the billing statement
void display_billing_statement(MenuItem items[], int num_items, float total_bill, float discount, float net_bill, float change) {
    printf("\n------------------------- Billing Statement -------------------------\n");
    printf("Item\t\tQty\tUnit Price\tAmount\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%d\t%.2f\t\t%.2f\n", items[i].name, items[i].qty, items[i].unit_price, items[i].amount);
    }

    printf("---------------------------------------------------------------------\n");
    printf("Total Bill: %.2f\n", total_bill);
    printf("Discount: %.2f\n", discount);
    printf("Net Bill: %.2f\n", net_bill);
    if (change >= 0) {
        printf("Change: %.2f\n", change);
    } else {
        printf("Insufficient Fund. Please tender more money.\n");
    }
    printf("---------------------------------------------------------------------\n");
}

int main() {
    MenuItem menu[] = {
        {"Solo Pack#1", 0, 100.0},
        {"Solo Pack#2", 0, 150.0},
        {"Barkada Pack#1", 0, 300.0},
        {"Barkada Pack#2", 0, 400.0},
        {"Family Pack#1", 0, 500.0},
        {"Family Pack#2", 0, 600.0}
    };

    int num_items = sizeof(menu) / sizeof(menu[0]);
    int choice, qty;
    char discount_type;
    float amount_tendered, total_bill, discount, net_bill, change;

    while (1) {
        printf("\n----------------------- Menu -----------------------\n");
        for (int i = 0; i < num_items; i++) {
            printf("%d. %s - %.2f\n", i + 1, menu[i].name, menu[i].unit_price);
        }
        printf("---------------------------------------------------\n");

        printf("Enter the menu item number (0 to finish): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        if (choice < 1 || choice > num_items) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d", &qty);

        menu[choice - 1].qty += qty;
        calculate_amount(&menu[choice - 1]);
    }

    printf("Enter discount type (N for None, P for PWD, S for Senior): ");
    scanf(" %c", &discount_type);

    printf("Enter amount tendered: ");
    scanf("%f", &amount_tendered);

    calculate_billing(menu, num_items, &total_bill, &discount, &net_bill, &change, amount_tendered, discount_type);

    display_billing_statement(menu, num_items, total_bill, discount, net_bill, change);

    if (change < 0) {
        while (change < 0) {
            printf("Enter additional amount tendered: ");
            scanf("%f", &amount_tendered);
            calculate_billing(menu, num_items, &total_bill, &discount, &net_bill, &change, amount_tendered, discount_type);
        }
    }

    return 0;
}
