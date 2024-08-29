#include <stdio.h>
#include <string.h>

struct menu {
    char name[50];
    int qty;
    float unit_price;
    float amount;
} food[4];

void foodMenu(struct menu *food) {
    strcpy(food[0].name, "Java Rice");
    food[0].unit_price = 50.00;

    strcpy(food[1].name, "Pork Steak");
    food[1].unit_price = 120.00;

    strcpy(food[2].name, "Chopsuey");
    food[2].unit_price = 100.00;

    strcpy(food[3].name, "Iced Tea");
    food[3].unit_price = 35.00;
}

void applyPackage(struct menu *food, int meal, int packType) {
    int mealIndex = meal - 1;
    int icedTeaIndex = 3;

    // Reset quantities
    for (int i = 0; i < 4; i++) {
        food[i].qty = 0;
        food[i].amount = 0;
    }

    switch (packType) {
        case 1:
            food[mealIndex].qty = 1;
            break;
        case 2:
            food[mealIndex].qty = 1;
            if (mealIndex != icedTeaIndex) {
                food[icedTeaIndex].qty = 1;
            }
            break;
        case 3:
            food[mealIndex].qty = 3;
            break;
        case 4:
            food[mealIndex].qty = 3;
            if (mealIndex != icedTeaIndex) {
                food[icedTeaIndex].qty = 3;
            }
            break;
        case 5:
            food[mealIndex].qty = 5;
            break;
        case 6:
            food[mealIndex].qty = 5;
            if (mealIndex != icedTeaIndex) {
                food[icedTeaIndex].qty = 5;
            }
            break;
        default:
            printf("Invalid package type\n");
            return;
    }

    // Calculate amounts
    for (int i = 0; i < 4; i++) {
        food[i].amount = food[i].qty * food[i].unit_price;
    }
}

void billing(struct menu *food, int meal, int packType, int customerType) {
    float totalBill = 0;
    float discount = 0.0;
    float amountTendered, change;

    // Calculate total bill
    for (int i = 0; i < 4; i++) {
        totalBill += food[i].amount;
    }

    // Apply discount if possible
    if (totalBill >= 100 && totalBill <= 2000) {
        discount += 0.02;
    }

    // Apply pwd or senior discounts
    switch (customerType) {
        case 1:
            discount += 0.05; // PWD
            break;
        case 2:
            discount += 0.20; // Senior
            break;
    }

    float discountAmount = totalBill * discount;
    float finalBill = totalBill - discountAmount;

    // Prompt for amount tendered until sufficient funds are provided
    do {
        printf("\nPlease enter the amount tendered: ");
        scanf("%f", &amountTendered);

        change = amountTendered - finalBill;

        if (change < 0) {
            printf("Insufficient funds. Please tender more money.\n");
        }
    } while (change < 0);

    // Display billing statement
    printf("\n------------------------- Billing Statement -------------------------\n");
    printf("Item\t\tQty\tUnit Price\tAmount\n");
    printf("---------------------------------------------------------------------\n");

    for (int i = 0; i < 4; i++) {
        if (food[i].qty > 0) {
            printf("%s\t\t%d\t%.2f\t\t%.2f\n", food[i].name, food[i].qty, food[i].unit_price, food[i].amount);
        }
    }

    printf("---------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\tTOTAL BILL: %.2f\n", totalBill);
    printf("\t\t\t\t\t\tDISCOUNT: %.2f\n", discountAmount);
    printf("\t\t\t\t\t\tNET BILL: %.2f\n", finalBill);
    printf("\t\t\t\t\t\tAMOUNT TENDERED: %.2f\n", amountTendered);
    printf("\t\t\t\t\t\tCHANGE: %.2f\n", change);
    printf("---------------------------------------------------------------------\n");
}

int main() {
    int meal, packType, customerType;
    char tryAgain;

    foodMenu(food);

    do {
        printf("\tMENU:\n\n1 => JAVA RICE(50.00)\n2 => PORK STEAK(120.00)\n3 => CHOPSUEY(100.00)\n4 => ICED TEA(35.00)\n");
        printf("\nChoose a meal (1 - 4): ");
        scanf("%d", &meal);

        if (meal < 1 || meal > 4) {
            printf("Invalid meal choice\n");
            printf("Do you want to try again? (y/n): ");
            scanf(" %c", &tryAgain);
            if (tryAgain == 'y' || tryAgain == 'Y') {
                continue;
            } else {
                return 0;
            }
        }

        printf("\n\tPACKAGE TYPES:\n\n1 => SOLO PACK#1(SOLO CHOSEN MEAL)\n2 => SOLO PACK#2(CHOSEN MEAL + ICED TEA)\n3 => BARKADA PACK#1(CHOSEN MEAL * 3)\n4 => BARKADA PACK#2(CHOSEN MEAL * 3 + ICED TEA)\n5 => FAMILY PACK#1(CHOSEN MEAL * 5)\n6 => FAMILY PACK#2(CHOSEN MEAL * 5 + ICED TEA)\n");
        printf("\nChoose a package type (1-6): ");
        scanf("%d", &packType);

        if (packType < 1 || packType > 6) {
            printf("Invalid package type choice\n");
            printf("Do you want to try again? (y/n): ");
            scanf(" %c", &tryAgain);
            if (tryAgain == 'y' || tryAgain == 'Y') {
                continue;
            } else {
                return 0;
            }
        }

        applyPackage(food, meal, packType);

        printf("\nAre you:\n\n1 => PWD\n2 => Senior\n3 => None\n\nChoose your type (1-3): ");
        scanf("%d", &customerType);

        if (customerType < 1 || customerType > 3) {
            printf("Invalid customer type choice\n");
            printf("Do you want to try again? (y/n): ");
            scanf(" %c", &tryAgain);
            if (tryAgain == 'y' || tryAgain == 'Y') {
                continue;
            } else {
                return 0;
            }
        }

        // Calculate the final bill and display details
        billing(food, meal, packType, customerType);

        break;
    } while (1);

    return 0;
}
