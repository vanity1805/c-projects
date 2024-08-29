#include <stdio.h>
#include <stdlib.h>

struct STORE {
    int Nstock;
    int style_num;
    int Size;
    float Nprice;
};

int main() {
    FILE *store, *temp;
    struct STORE shoe[10];
    int num = 0, choose, it_num, a;
    float newpr;
    int again;

    store = fopen("shoe.dat", "w");
    if (store == NULL) {
        printf("\tError");
        exit(1);
    }

    printf("How many pair of shoes will you add on the inventory?\t");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("\nEnter stock number:\t");
        scanf(" %d", &shoe[i].Nstock);
        printf("\nChoose a style (0-20):\t");
        scanf("%d", &shoe[i].style_num);
        printf("\nEnter size of the shoes (3-14):\t");
        scanf("%d", &shoe[i].Size);
        printf("\nEnter price:\t");
        scanf("%f", &shoe[i].Nprice);

        fprintf(store, "%d\t%d\t%d\t%.2f\n", shoe[i].Nstock, shoe[i].style_num, shoe[i].Size, shoe[i].Nprice);
    }
    fclose(store);

    printf("Recorded!\n");

    do {
        printf("\n=============================================================\n\n");
        printf("\t\tSHOE STORE INVENTORY\n");
        printf("\n\t1. Enter New Record");
        printf("\n\t2. Change the price of the item number");
        printf("\n\t3. Display the record");
        printf("\n\nChoose a number: ");
        scanf("%d", &choose);

        if (choose == 1) {
            store = fopen("shoe.dat", "a");

            if (store == NULL) {
                printf("\tError");
                exit(1);
            }

            printf("\n------------------------------------------------------------\n");
            printf("\n\t\tNEW RECORD\n");

            printf("How many pair of shoes will you add on the inventory?\t");
            scanf("%d", &num);
            for (int i = 0; i < num; i++) {
                printf("\nEnter stock number:\t");
                scanf(" %d", &shoe[i].Nstock);
                printf("\nChoose a style (0-20):\t");
                scanf("%d", &shoe[i].style_num);
                printf("\nEnter size of the shoes (3-14):\t");
                scanf("%d", &shoe[i].Size);
                printf("\nEnter price:\t");
                scanf("%f", &shoe[i].Nprice);

                fprintf(store, "%d\t%d\t%d\t%.2f\n", shoe[i].Nstock, shoe[i].style_num, shoe[i].Size, shoe[i].Nprice);
            }
            fclose(store);

            printf("Recorded!\n");
        } else if (choose == 2) {
            printf("\n------------------------------------------------------------\n");
            printf("\n\t\tCHANGE PRICE\n");

            store = fopen("shoe.dat", "r");
            temp = fopen("shoes.dat", "w");

            if (store == NULL || temp == NULL) {
                printf("\tError");
                exit(1);
            }

            printf("\n\nEnter Item Number: ");
            scanf("%d", &it_num);

            int found = 0;
            while (fscanf(store, "%d %d %d %f", &shoe[0].Nstock, &shoe[0].style_num, &shoe[0].Size, &shoe[0].Nprice) == 4) {
                if (shoe[0].Nstock == it_num) {
                    printf("\nEnter New Price: Php ");
                    scanf("%f", &newpr);
                    printf("\n\n\tNew price: Php %.2f", newpr);
                    fprintf(temp, "%d\t%d\t%d\t%.2f\n", shoe[0].Nstock, shoe[0].style_num, shoe[0].Size, newpr);
                    printf("\n\nChanged!\n");
                    found = 1;
                } else {
                    fprintf(temp, "%d\t%d\t%d\t%.2f\n", shoe[0].Nstock, shoe[0].style_num, shoe[0].Size, shoe[0].Nprice);
                }
            }

            if (!found) {
                printf("\n\nINVALID INPUT\n");
            }

            fclose(store);
            fclose(temp);

            // Replace old file with new file
            remove("shoe.dat");
            rename("shoes.dat", "shoe.dat");

        } else if (choose == 3) {
            printf("\n------------------------------------------------------------\n");
            printf("\n\t\tDISPLAY RECORD\n");

            store = fopen("shoe.dat", "r");

            if (store == NULL) {
                printf("\tError");
                exit(1);
            }

            printf("\n\nITEM NUMBER\tSTYLE\tSIZE\tPRICE\n");
            printf("----------------------------------------\n");
            while (fscanf(store, "%d %d %d %f", &shoe[0].Nstock, &shoe[0].style_num, &shoe[0].Size, &shoe[0].Nprice) == 4) {
                printf("%-12d\t%-10d\t%-5d\t%.2f\n", shoe[0].Nstock, shoe[0].style_num, shoe[0].Size, shoe[0].Nprice);
            }

            fclose(store);
        } else {
            printf("\nINVALID INPUT!\n");
        }

        printf("\n------------------------------------------------------------\n");
        printf("\n\n\tContinue? (1 - YES | 0 - NO) -> ");
        scanf("%d", &again);
        printf("\n");
        printf("=============================================================\n");

    } while (again == 1);

    return 0;
}
