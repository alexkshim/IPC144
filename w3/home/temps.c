/*
Name:            Kyuyoung Shim
Student number:  102562162
Email:           kshim3@myseneca.ca
Workshop:        workshop3 - home
Section:         IPC144SMM
Date:            2017-Feb-1
*/

#include <stdio.h>
#define NUMS 4
int main(void){
	
	int high = 0; // collects high values
	int low = 0;; // collects low values
	int i;
	int TotalH = 0, TotalL = 0; // Total High and Total Low
	int highest = 0, lowest = 0; // highest temperature and lowest temperature
	int dayH = 0, dayL = 0; // day highest and day lowest
	float total; // total high + total low

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++){

		do{
			printf("Enter the high value for day %d: ", i+1);
			scanf("%d", &high);
			printf("\n");
			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &low);
			printf("\n");

			if(high >= 41 || high <= -41 || low >= 41 || low <= -41 || high <= low){
				printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
				}
			if (high > highest) {
				highest = high;
				dayH = i;
				}
			if (low < lowest) {
				lowest = low;
				dayL = i;
				}
		}while(high >= 41 || high <= -41 || low >= 41 || low <= -41 || high <= low);

		TotalH += high;
		TotalL += low;
	}

	total = TotalH + TotalL;

	printf("The average (mean) temperature was: %.2f\n", total / (NUMS * 2) );
	printf("The highest temperature was %d, on day %d\n", highest, dayH+1);
	printf("The lowest temperature was %d, on day %d\n", lowest, dayL+1);

	return 0;
}


