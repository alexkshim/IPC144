/*
* Name:            Kyuyoung Shim
* Student number:  102562162
* Email:           kshim3@myseneca.ca
* Workshop:        workshop4 - home
* Section:         IPC144SMM
* Date:            2017-Feb-8
* */
#include <stdio.h>
#define MAXDAYS 10
int main(void) {
	int i, j; // these count for loops
	int s = 0; // selection for while loop at the bottom
	int days = 0; // days
	int high[MAXDAYS] = { 0 }; // collects high values
	int low[MAXDAYS] = { 0 }; // collects low values
	float total = 0;

	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	while (days < 3 || days > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days);
	}

	printf("\n");

	for (i = 0; i < days; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%d", &high[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &low[i]);
	}

	printf("\nDay  Hi  Low\n");
	for (j = 0; j < days; j++) {
		printf("%-3d  %-2d  %3d\n", j + 1, high[j], low[j]);
	}

	while (s != -1) {
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", days);
		scanf("%d", &s);
		if (s != -1 && !(s >= 1 && s <= days)) {
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", days);
			scanf("%d", &s);
		}
		if (s >= 1 && s <= days) {
			total = high[s - 1] + low[s - 1];
			printf("\nThe average temperature up to day %d is: %.2f\n", s, total / 2);
		}
	}
	printf("\nGoodbye!\n");

	return 0;
}