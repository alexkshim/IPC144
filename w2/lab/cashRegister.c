/* Name:    Kyuyoung Shim
 * Section: IPC144SMM
 * ID:      102562162
 * Date:    2017-Jan-25
 * File:    cashRegister.c
*/
#include <stdio.h>
int main(void){
	int L1 = 0, Q1 = 0;
	double i, L2 = 0, Q2 = 0;

	printf("Please enter the amount to be paid: $");
	scanf("%lf",&i);
	L1 = i / 1;
	L2 = i - L1;
	Q1 = L2 / 0.25;
	Q2 = L2 - Q1 * 0.25;

	printf("Loonies required: %d, balance owing $%.2lf\n", L1, L2);
	printf("Quarters required: %d, balance owing $%.2lf\n", Q1, Q2);
	
	return 0;
}
