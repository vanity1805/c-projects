#include <stdio.h>

int main() {

 // Constants
 const int maxWeight = 35, luggageCharge = 250, excessFee = 150, refundPerLuggage = 25, refundWeightMin = 5,refundWeightMax = 5;
// Variables
 float weightL1, weightL2, aTotalCost, bTotalCost, totalExcessFee, totalRefund, acostL1, acostL2, bcostL1, bcostL2, cCostL1, cCostL2, cExcessFee, cTotalCost,
 dCostL1, dCostL2, dExcessFee, dTotalCost, eTotalCost, fTotalCost;

 printf("WELCOME TO Sariling Atin Aircraft Carrier");
 //PROMPTS THE USER TO INPUT WEIGHT OF EACH LUGGAGE
 printf("Input weight of the first luggage (in kilos): ");
 scanf("%f", &weightL1);
 printf("Input weight of the second luggage (in kilos): ");
 scanf("%f", &weightL2);

  // EQUATIONS USING IF-ELSE STATEMENTS TO PROVIDE EXACT TOTAL COST/EXCESS FEE/REFUND FEE
    if (weightL1 > maxWeight) {
        acostL1 = luggageCharge + excessFee * (weightL1 - maxWeight);
        printf("\nCost of Luggage 1: PHP %.2f\n", acostL1);
    }

    if (weightL2 > maxWeight) {
        acostL2 = luggageCharge + excessFee * (weightL2 - maxWeight);
        printf("\nCost of Luggage 2: PHP %.2f\n", acostL2);
    }

 aTotalCost = acostL1 + acostL2;
 totalExcessFee = excessFee *(weightL1 - maxWeight) + excessFee * (weightL2 - maxWeight);

   if (weightL1 >= refundWeightMin && weightL1 <= refundWeightMax) {
        bcostL1 = luggageCharge - refundPerLuggage;
        printf("\nCost of Luggage 1: PHP %.2f\n", bcostL1);
    }

   if (weightL2 >= refundWeightMin && weightL2 <= refundWeightMax) {
        bcostL2 = luggageCharge - refundPerLuggage;
        printf("\nCost of Luggage 2: PHP %.2f\n", bcostL2);
    }

    if (weightL1 < 5) {
        printf("\nCost of Luggage 1: PHP 0\n");
    }

   if (weightL2 < 5) {
        printf("\nCost of Luggage 2: PHP 0\n");
    }


 bTotalCost = bcostL1 + bcostL2;
 totalRefund = luggageCharge * 2 - bTotalCost;

    printf("\nWeight of the first luggage: %.2f kilos\n", weightL1);
    printf("Weight of the second luggage: %.2f kilos\n", weightL2);

    printf("\n\t\tRECEIPT\n\n");

    if (weightL1 > maxWeight && weightL2 > maxWeight) {
       printf("Your total excess fee is: PHP %.2f\n", totalExcessFee);
       printf("Total cost of all your luggage is : PHP %.2f\n", aTotalCost);
       printf("NO REFUND FEE\n");

    }else if (weightL1 >= refundWeightMin && weightL1 <= refundWeightMax && weightL2 >= refundWeightMin && weightL2 <= refundWeightMax){
       printf("NO EXCESS FEE\n");
       printf("Total cost of all your luggage is : PHP %.2f\n", bTotalCost);
       printf("Your total refund fee is: PHP %.2f\n", totalRefund);

    }else if (weightL1 < 5 && weightL2 < 5){
       printf("YOU'RE FREE FROM LUGGAGE FEE!\n");
    }else if (weightL1 > maxWeight && weightL2 < 5){
        cCostL1 = luggageCharge + excessFee * (weightL1 - maxWeight);
        cCostL2 = 0;
        cTotalCost = cCostL1 + cCostL2;
        cExcessFee = excessFee * (weightL1 - maxWeight);
       printf("Your total excess fee is: PHP %.2f\n", cExcessFee);
       printf("Total cost of all your luggage is : PHP %.2f\n", cTotalCost);
       printf("NO REFUND FEE\n");
    }else if (weightL1 < 5 && weightL2 > maxWeight){
        dCostL1 = 0;
        dCostL2 = luggageCharge + excessFee * (weightL2 - maxWeight);
        dTotalCost = dCostL1 + dCostL2;
        dExcessFee = excessFee * (weightL2 - maxWeight);
       printf("Your total excess fee is: PHP %.2f\n", dExcessFee);
       printf("Total cost of all your luggage is : PHP %.2f\n", dTotalCost);
       printf("NO REFUND FEE\n");
    }else if (weightL1 < 5 && weightL2 >= refundWeightMin && weightL2 <= refundWeightMax){
       printf("NO EXCESS FEE\n");
       printf("Total cost of all your luggage is : PHP %.2f\n", bcostL2);
       printf("Your total refund fee is: PHP 25\n");
    }else if (weightL1 >= refundWeightMin && weightL1 <= refundWeightMax && weightL2 < 5){
       printf("NO EXCESS FEE\n");
       printf("Total cost of all your luggage is : PHP %.2f\n", bcostL1);
       printf("Your total refund fee is: PHP 25\n");
    }else if (weightL1 > maxWeight && weightL2 >= refundWeightMin && weightL2 <= refundWeightMax){
       cCostL1 = luggageCharge + excessFee * (weightL1 - maxWeight);
       cExcessFee = excessFee * (weightL1 - maxWeight);
       eTotalCost = cCostL1 + bcostL2;
       printf("Your total excess fee is: PHP %.2f\n", cExcessFee);
       printf("Total cost of all your luggage is : PHP %.2f\n", eTotalCost);
       printf("Your total refund fee is: PHP 25\n");
    }else if (weightL1 >= refundWeightMin && weightL1 && weightL2 > maxWeight){
       acostL2 = luggageCharge + excessFee * (weightL2 - maxWeight);
       cExcessFee = excessFee * (weightL2 - maxWeight);
       fTotalCost = 225 + acostL2;
       printf("Your total excess fee is: PHP %.2f\n", cExcessFee);
       printf("Total cost of all your luggage is : PHP %.2f\n", fTotalCost);
       printf("Your total refund fee is: PHP 25\n");
    }else{
       printf("Total cost of all your luggage is : PHP %.2f\n", cTotalCost);
    }

 return 0;
}
