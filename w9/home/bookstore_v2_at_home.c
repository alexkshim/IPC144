/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_BOOKS 10
#define MAX_TITLE_SIZE 21					// The maximum number of characters in a book title excluding the null terminator

//Type the struct here
struct Book {
	int _isbn;								// International Standard Book Number
	float _price;							// Book price
	int _year;								// Publication year
	char _title[MAX_TITLE_SIZE];			// Book title
	int _qty;								// Book Quantity
};

//Type the function prototypes here
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
			printf("ISBN:");
			scanf("%d", &mybook._isbn);
			printf("Title:");
			scanf(" %20[^\n]", mybook._title);
			printf("Year:");
			scanf("%d", &mybook._year);
			printf("Price:");
			scanf("%f", &mybook._price);
			printf("Quantity:");
			scanf("%d", &mybook._qty);
			addBook(filename, &mybook);
			break;
		case 3:
			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &mybook._isbn);
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

void displayInventory(const char filename[]) {
	//Define an object of struct Book
	struct Book book;

	printf("\n\nInventory\n");											// two empty lines before it prints
	printf("===================================================\n");	// 51 “=”
	printf("ISBN      Title               Year Price  Quantity\n");
	printf("---------+-------------------+----+-------+--------\n");
	//9 dashes + 19 dashes + 4 dashes + 7 dashes+ 8 dashes

	//Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	//If the file is properly opened, display headers, similar to workshop 8
	if (fp != NULL) {
		//Use a while loop to call readRecord and display the records.
		//while(/*call readRecord and check its return value*/)
		rewind(fp);
		while (readRecord(fp, &book) == 5) {
			//display the record
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n",
				book._isbn, book._title, book._year, book._price, book._qty);
		}
	}
	//Display the footer
	printf("===================================================\n");		// 51 “=” 
	printf("\n");															// and one more new line
	fclose(fp);	//Close the file
}

void addBook(const char filename[], struct Book *b2Add) {
	int check = 0;

	//Open the file for appending (a+)
	FILE *fp = fopen(filename, "a+");

	//Type your code here
	check = searchInventory(fp, b2Add->_isbn);

	if (check != -1) {
		printf("The book exists in the repository!\n\n");
	}
	else {
		feof(fp);
		fprintf(fp, "\n%d;%.2f;%d;%d;%s\n", b2Add->_isbn, b2Add->_price, b2Add->_year, b2Add->_qty, b2Add->_title);
		printf("The book is successfully added to the inventory.\n\n");
	}

	fclose(fp);	//Close the file
}

void checkPrice(const char filename[], const int isbn2find) {
	struct Book book;
	int check = 0;

	FILE *fp = fopen(filename, "r");
	
	if (fp != NULL) {
		check = searchInventory(fp, isbn2find);
		if (check != -1) {
			rewind(fp);
			while (readRecord(fp, &book) == 5) {
				if (isbn2find == book._isbn) {
					printf("Book %d costs $%.2f\n\n", book._isbn, book._price);
				}
			}
		}
		else {
			printf("The book is not found!\n");
		}
		fclose(fp);
	}
}


int searchInventory(FILE *fp, const int isbn2find) {
	//Define an object of struct Book and other necessary variables
	struct Book book;
	int check = -1;		// to return -1 if nothing found

	if (fp != NULL) {		// If the file ponter is not NULL:
		rewind(fp);
		//as long as the record is not found,
		//use the function readRecord to read the recods and look for isbn2find
		while (readRecord(fp, &book) == 5) {
			if (isbn2find == book._isbn) {
				check = 1;	// set it to positive value to indicate any value of positive is true in C
			}
		}
	}
	return check;
}

float calculateCapital(const char filename[]) {
	//Define an object of struct Book
	struct Book book;
	float total_capital = 0;

	FILE *fp = NULL;
	//Open the file for reading
	//Open the file, and check for null pointer
	fp = fopen(filename, "r");
	//If the file is properly opened, use a while loop to call readRecord
	//while(/*call readRecord and check its return value*/)
	//Accumulate the multiplication of the price of each item to its quantity
	if (fp != NULL) {
		while (readRecord(fp, &book) == 5) {
			total_capital = total_capital + book._price * book._qty;
		}
		fclose(fp);	//Close the file
	}
	return total_capital;	//return the total_capital
}

int readRecord(FILE *fp, struct Book *b2read) {
	int rv = 0;	//Define a variable int rv = 0
				//rv = fscanf(/*Type your code here*/);
	rv = fscanf(fp, "%d; %f; %d; %d; %20[^\n]", &(b2read->_isbn), &(b2read->_price), &(b2read->_year), &(b2read->_qty), (b2read->_title));
	//return rv
	return rv;
}