/*********************************************************
    Name: Kyuyoung Shim
    ID: 102-562-162
    Section: MM
*********************************************************/
#include <stdio.h>
#define MAXDAYS 10
int main(void) {
	int days = 0; // days the user defines
	int high[MAXDAYS] = { 0 }; // collects high values
	int low[MAXDAYS] = { 0 }; // collects low values
	int i; // it counts for loop

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
	for (i = 0; i < days; i++) {
		printf("%-3d  %-2d  %3d\n", i + 1, high[i], low[i]);
	}

	return 0;
}



