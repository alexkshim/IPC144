/* Name:    Kyuyoung Shim
 * Section: IPC144SMM
 * ID:      102562162
 * Date:    2017-Jan-27
 * File:    cashRegister.c
*/
#include <stdio.h>
int main(void){
	double i = 0; // input
	int L1 = 0, Q1 = 0, D1 = 0, N1 = 0, P1 = 0; // Loonies, Quarters, Dimes, Nickels, Pennies
	double GST = 0;
	double tAmount = 0;
	int tRemaining = 0; // hold total remaining as cents
	
	printf("Please enter the amount to be paid: $");
	scanf("%lf",&i);
	
	GST = i * .13 + .005;
	tAmount = GST + i;
	
	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n",tAmount);

	tRemaining = tAmount * 100;
	L1 = tRemaining / 100;
	tRemaining = tRemaining % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", L1, (double)tRemaining/100);
	Q1 = tRemaining / 25;
	tRemaining = tRemaining % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", Q1, (double)tRemaining/100);
	D1 = tRemaining / 10;
	tRemaining = tRemaining % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", D1, (double)tRemaining/100);
	N1 = tRemaining / 5;
	tRemaining = tRemaining % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", N1, (double)tRemaining/100);
	P1 = tRemaining / 1;
	tRemaining = tRemaining % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", P1, (double)tRemaining/100);

	return 0;
}
