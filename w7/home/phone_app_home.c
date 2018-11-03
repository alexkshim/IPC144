/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#include <stdio.h>
#define SIZE 3

/* prototypes */
void decompose(const long long phoneNum, int *areaCode, int *prefix, int *lineNum);
int isValid(const long long validation);

/* functions */
void decompose(const long long phoneNum, int *areaCode, int *prefix, int *lineNum) {
	*areaCode = phoneNum / 10000000;
	*prefix = (phoneNum % 10000000) / 10000;
	*lineNum = (phoneNum % 10000000) % 10000;
}

/* main program */
int main(void) {

	const long long *phoneNumber[SIZE] = { 0LL };

	int areaCode = 0;									// to hold area code
	int prefix = 0;										// to hold prefix
	int lineNum = 0;									// to hold line number
	int option;
	int i;												// to count for loops
	int phoneCount = 0;									// to check if there is empty space in an array		
	long long tempPnum[SIZE] = { 0LL };					// to hold temporary phone numbers

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
			for (i = 0; i < SIZE; i++) {
				if (phoneNumber[i] > 0) {
					decompose(*phoneNumber[i], &areaCode, &prefix, &lineNum);
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
				scanf("%lld", &tempPnum[phoneCount]);

				if (isValid(tempPnum[phoneCount])) {
					phoneNumber[phoneCount] = &tempPnum[phoneCount];
					phoneCount++;
				}
				else {
					printf("ERROR!!! Phone Number is not Valid\n");
				}
			}

			else {
				printf("ERROR!!! Phone Number List is Full\n");
			}

			printf("\n");
			break;

		default:
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;
		}

	} while (option != 0);

	return 0;
}

/* functions */
int isValid(const long long validNum) {
	int acodeTonew[3] = { 416,647,905 };				// to check valid area codes
	int i;												// to count the for loop
	int satisfactory = 0;								// accept the received number if area codes and prefix are valid
	int areaCode = 0;									// to hold the area code
	int prefix = 0;										// to hold the prefix

	areaCode = validNum / 10000000;
	prefix = (validNum % 10000000) / 10000;

	for (i = 0; i < 3; i++) {
		if (areaCode == acodeTonew[i] && prefix >= 100 && prefix <= 999) {
			satisfactory++;
		}
	}

	//any positive value is true
	return satisfactory;
}

