/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_TITLE_SIZE 20					// The maximum number of characters in a book title excluding the null terminator

struct Book {
	int _isbn;								// International Standard Book Number
	float _price;							// Book price
	int _year;								// Publication year
	char _title[MAX_TITLE_SIZE];			// Book title
	int _qty;								// Book Quantity
};

/* prototypes */
void menu();
int readRecord(FILE *fp, struct Book *b2read);
void displayInventory(const char filename[]);
float calculateCapital(const char filename[]);
float calculateCapital(const char filename[]);
int searchInventory(FILE *fp, const int isbn2find);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);

/* main function */
int main(void)
{
	struct Book mybook;										//An object of struct Book
	char filename[] = "inventory.txt";						//Name of the file

	int option = -1;
	float totalCapital = 0;

	printf("Welcome to the Book Store\n");					// Display a welcome message
	printf("=========================\n");					// 25 assignment operators
	do {
		menu();												// call the menu function
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			displayInventory(filename);
			break;
		case 2:
			addBook(filename, &mybook);
			break;
		case 3:
			checkPrice(filename, mybook._isbn);
			break;
		case 4:
			totalCapital = calculateCapital(filename);
			printf("The total capital is: $%.2lf.\n", totalCapital);
			break;
		case 0:
			printf("Goodbye!\n");
			break;

		default:
			printf("Invalid input, try again:\n");
			break;
		}

	} while (option != 0);

	return 0;
}

/* Function definitions */
void menu() {
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n\n");
	printf("Select: ");
}

/* w9 */
int readRecord(FILE *fp, struct Book *b2read) {
	int rv = 0;
		rv = fscanf(fp, "%d; %f; %d; %d; %20[^\n]", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), (b2read->_title));
	return rv;
}

void displayInventory(const char filename[]) {
	struct Book book;

	printf("\n\nInventory\n");											// two empty lines before it prints
	printf("===================================================\n");	// 51 “=”
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");
	//9 dashes + 19 dashes + 4 dashes + 7 dashes+ 8 dashes

	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (readRecord(fp, &book) == 5) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book._year, book._price, book._qty);
		}
		fclose(fp);
	}
	printf("===================================================\n");		// 51 “=” 
	printf("\n");															// and one more new line
}

float calculateCapital(const char filename[]) {
	struct Book book;
	float total = 0;

	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (readRecord(fp, &book) == 5) {
			total = total + book._price * book._qty;
		}
		fclose(fp);
	}
	return total;
}

/* Not implemented */
int searchInventory(FILE *fp, const int isbn2find) {
	printf("Not implemented\n");
	return 1;
}

void addBook(const char filename[], struct Book *b2Add) {
	printf("Not implemented\n");
}

void checkPrice(const char filename[], const int isbn2find) {
	printf("Not implemented\n");
}

