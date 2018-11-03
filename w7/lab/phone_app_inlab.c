/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#include <stdio.h>
#define SIZE 3


/* prototypes */
void decompose(const long long phoneNum, int *areaCode1, int *prefix1, int *lineNum1);

/* functions */
void decompose(const long long phoneNum, int *areaCode1, int *prefix1, int *lineNum1) {
	*areaCode1 = phoneNum / 10000000;
	*prefix1 = (phoneNum % 10000000) / 10000;
	*lineNum1 = (phoneNum % 10000000) % 10000;
	/*
	This is replaced by above
	*AAA = pNum / 10000000 % 1000;
	*PPP = pNum / 10000 % 1000000 - (*AAA * 1000);
	*LLLL = pNum - (*AAA * 10000000) - (*PPP * 10000);
	*/
}


/* main program */

int main(void) {
	const long long *phoneNumber[SIZE] = { 0LL };

	int option;
	int i;									// to count for loops
	int phoneCount = 0;						// to check if there is empty space in an array
	long long tempPnum = 0LL;				// to hold temporary value of phone numbers
	int areaCode;						// to hold area code
	int prefix;							// to hold prefix
	int lineNum;						// to hold line number

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;


		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
			for (i = 0; i < phoneCount; i++) {
				decompose(*phoneNumber[phoneCount], &areaCode, &prefix, &lineNum);
				if (areaCode > 0 && prefix > 0 && lineNum > 0) {
					printf("(%3d)-%3d-%4d\n", areaCode, prefix, lineNum);
				}
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");
			if (phoneCount < SIZE) {
				scanf("%lld", &tempPnum);
				phoneNumber[phoneCount] = &tempPnum;
				//decompose(*phoneNumber[phoneCount], &pNumber[phoneCount].aCode, &pNumber[phoneCount].prefix, &pNumber[phoneCount].lNumber);
				phoneCount++;
			}
			else {
				printf("ERROR!!! Phone Number List is Full\n");
			}
			printf("\n");
			break;

		default:
			break;
		}

	} while (option != 0);

	return 0;
}

