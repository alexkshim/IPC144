/*
Name:            Kyuyoung Shim
Student number:  102562162
Email:           kshim3@myseneca.ca
Workshop:        workshop3 - lab
Section:         IPC144SMM
Date:            2017-Feb-1
*/

#include <stdio.h>
#define NUMS 3
int main(void){
	
	int high = 0; // collects high values
	int low = 0; // collects low values
	int i = 0, count = 0; // i for for loop and count for do while loop
	int TotalH = 0, TotalL = 0; // Total High and Total Low
	float total = 0; // total high + total low

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++){

		while (count = 1) {
			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &low);
			printf("\n");
			if (high >= 41 || high <= -41 || low >= 41 || low <= -41 || high <= low) {
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
				count--;
				printf("%d\n", count);
			}
			else if (count != 1) {
				count == 1;
			}
		}
		TotalH += high;
		TotalL += low;
	}

	total = TotalH + TotalL;
	printf("The average (mean) temperature was: %.2f\n", total / (NUMS * 2) );

	return 0;
}


