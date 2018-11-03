/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) {
	int isJedi = 0;					// if there is a match it will return true (1) otherwise false (0)
	char masterName[31] = { 0 };	// Full Name length is less than or equal to 30 characters in file (excluding '\0' at the end)

	FILE *fp = fopen("jedi_master.txt", "r");	// open the file with read mode

	if (fp != NULL) {	// checking the state of the file pointer before using it

		while (fscanf(fp, " %[^\n]", masterName) == 1) {
			// Reads the full-names out of the Jedi Master file, one by one,
			if (strcmp(masterName, name) == 0) {
				isJedi = 1;
				// and compares each of them with the incoming name argument, 
				// if there is a match it will return true (1) otherwise false (0);
			}
		}
	}

	return isJedi;
}


void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {

	int charSize = 0;			// to hold the size of characters obtained
	int sizeOfSpace = 0;		// to hold the size of spaces that should fill the empty spaces until 16 spaces
	int i;						// to count the for loop

	charSize = strlen(fullName);	// to count how many characters the fullName has

	if (charSize > 16) {
		// First if the name is longer than 16 characters
		strncpy(formattedRecord, fullName, 14);
		// This name (fullName) will be copied into formattedRecord
		formattedRecord[14] = '\0';
		// it will shorten it to 14
		
		// /* another way to shorten */
		////strcpy(formattedRecord, fullName);
		////formattedRecord[14] = '\0';

		strcat(formattedRecord, "..");
		// and then concatenates two dots ("..") 
	}
	else {
		// Otherwise, if the name is shorter than 16) to make the name exactly 16 characters,
		strcpy(formattedRecord, fullName);
		// This name (fullName) will be copied into formattedRecord
		sizeOfSpace = 16 - charSize;
		for (i = 0; i < sizeOfSpace; i++) {
			strcat(formattedRecord, " ");
		}
		// it will concatenate a string full of space with the length of(16 – Length of name)
	}

	strcat(formattedRecord, " (");
	// 1 - a space and an open parentheses
	strcat(formattedRecord, npa);
	// 2 - npa string
	strcat(formattedRecord, ") ");
	// 3 - Close parentheses and a space
	strcat(formattedRecord, co);
	// 4 - co string
	strcat(formattedRecord, "-");
	// 5 - a dash ("-")
	strcat(formattedRecord, number);
	// 6 - number string

	if (isJediMaster(fullName) != 0) {
		strcat(formattedRecord, " Jedi Master");
		// 7 - if this the name is of a Jedi Master, concatenate (" Jedi Master")
	}

}


/* formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/