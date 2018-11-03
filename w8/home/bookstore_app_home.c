/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_BOOKS 10						// The maximum number of books that exists in an inventory
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
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);

/* main function */
int main(void)
{
	struct Book book[MAX_BOOKS];							// An array of Book representing the inventory

	int size = 0;											// Number of books in the inventory. The inventory is initially empty.
	int option = -1;

	printf("Welcome to the Book Store\n");					// Display a welcome message
	printf("=========================\n");					// 25 assignment operators
	do {
		menu();												// call the menu function
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			displayInventory(book, size);
			break;

		case 2:
			addBook(book, &size);
			break;

		case 3:
			checkPrice(book, size);
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
	printf("0) Exit.\n\n");
	printf("Select: ");
}

void displayInventory(const struct Book book[], const int size) {
	int i;

	if (size == 0) {
		printf("The inventory is empty!\n");
	}
	if (size > 0) {
		printf("\n\nInventory\n");											// two empty lines before it prints
		printf("===================================================\n");	// 51 “=”
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		//9 dashes + 19 dashes + 4 dashes + 7 dashes+ 8 dashes
		for (i = 0; i < size; i++) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
	}
	printf("===================================================\n");		// 51 “=” 
	printf("\n");															// and one more new line
}

int searchInventory(const struct Book book[], const int isbn, const int size) {
	int i;				// to count the for loop
	int matching = -1;	// the matching index that coming from the desired book 

	for (i = 0; i <= size; i++) {
		if (isbn == book[i]._isbn) {
			matching = i;
		}
	}
	return matching;
}

void addBook(struct Book book[], int *size) {
	int matching = -1;		// to store the matching index
	int tempIsbn = 0;		// temporary International Standard Book Number
	int tempQuantity = 0;	// temporary Quantity

	if (*size == MAX_BOOKS) {
		printf("the inventory is full\n");
	}
	else {
		printf("ISBN:");
		scanf("%d", &tempIsbn);
		if (*size > 0) {
			matching = searchInventory(book, tempIsbn, *size);
		}
		printf("Quantity:");
		scanf("%d", &tempQuantity);
		if (matching > -1) {
			book[matching]._qty += tempQuantity;
			printf("The book exists in the repository, quantity is updated.\n\n");
		}
		else {
			book[*size]._isbn = tempIsbn;
			book[*size]._qty = tempQuantity;
			printf("Title:");
			scanf(" %20[^\n]", book[*size]._title);
			printf("Year:");
			scanf("%d", &book[*size]._year);
			printf("Price:");
			scanf("%f", &book[*size]._price);
			(*size)++;
			printf("The book is successfully added to the inventory.\n");
			printf("\n");
		}
	}
}

void checkPrice(const struct Book book[], const int size) {
	int matching = -1;		// to store a matched book
	int checkIsbn = 0;		// the temporary International Standard Book Number received by the user to check

	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &checkIsbn);
	matching = searchInventory(book, checkIsbn, size);
	if (matching > -1) {
		printf("Book %d costs $%.2lf\n\n", book[matching]._isbn, book[matching]._price);
	}
	else {
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
}
