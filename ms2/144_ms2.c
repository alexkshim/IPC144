/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//// Define statements:
//#define LINEAR 1
//#define FORM 0

// Constant TAX value:
const double TAX = 0.13;

// Item structure:
struct Item {
	double price;			// price of a unit of the item
	int sku;				// Stock Keeping Unit, a 3 digit integer
	int isTaxed;			// an integer Flag, if true (non-zero), the tax is applied in price calculations
	int quantity;			// the quantity of the time in the inventory
	int minQuantity;		// the minimum quantity number in inventory
	char name[21];			// a 20 character, C string to keep the name of the item
};


// Function Prototypes Milestone 1:
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);

// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function Implementations Milestone 1:
void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n\n");
}

void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");

}

void printFooter(double grandTotal) {
	printf("--------------------------------------------------------+----------------\n");
	if (grandTotal > 0) {
		printf("                                           Grand Total: |%12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void) {
	while (getchar() != '\n');
}

void pause(void) {
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void) {
	char NL = 'x';
	int Value = 0;
	while (NL != '\n') {
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid integer, please try again: ");
		}
	}
	return Value;
}

int getIntLimited(int lowerLimit, int upperLimit) {
	int i = 0;					// keep looping if the condition is not ture
	int result;

	while (i == 0) {
		result = getInt();
		if (result >= lowerLimit && result <= upperLimit) {
			i++;
		}
		else {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
	}
	return result;
}

double getDouble(void) {
	char NL = 'x';
	double Value = 0;
	while (NL != '\n') {
		scanf("%lf%c", &Value, &NL);
		if (NL != '\n') {
			flushKeyboard();
			printf("Invalid number, please try again: ");
		}
	}
	return Value;
}

double getDoubleLimited(double lowerLimit, double upperLimit) {
	int i = 0;					// keep looping if the condition is not ture
	double result;
	while (i == 0) {
		result = getDouble();
		if (result >= lowerLimit && result <= upperLimit) {
			i++;
		}
		else {
			printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
		}
	}
	return result;
}

int yes(void) {
	int loopEnd = 0, to_return = 0;
	char input = '0';				// user input
	while (loopEnd == 0) {
		scanf(" %c", &input);
		flushKeyboard();
		if (!(input == 'Y' || input == 'y' || input == 'N' || input == 'n')) {
			printf("Only (Y)es or (N)o are acceptable: ");
		}
		else {
			loopEnd++;
		}
	}
	if (input == 'Y' || input == 'y') {
		to_return = 1;
	}
	else {
		to_return = 0;
	}
	return to_return;
}

int menu(void) {
	int option;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n> ");
	option = getIntLimited(0, 7);
	return option;
}

void GroceryInventorySystem(void) {
	welcome();
	int loopEnd = 0;
	while (loopEnd == 0) {

		int result = menu();
		switch (result)
		{
		case 1:
			printf("List Items under construction!\n");
			pause();
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause();
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause();
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause();
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause();
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause();
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause();
			break;
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			int check = yes();
			if (check == 1) {
				loopEnd++;
			}
			break;
		default:
			break;
		}

	}//loop end

}
// code your functions here:

// Function Implementations Milestone 2:
double totalAfterTax(struct Item item) {
	double total = 0;
	if (item.isTaxed == 1) {
		total = item.price * item.quantity;
		total += total * TAX;
	}
	else {
		total = item.price * item.quantity;
	}
	return total;
}

int isLowQuantity(struct Item item) {
	int to_return;

	if (item.quantity < item.minQuantity) {
		to_return = 1;
	}
	else {
		to_return = 0;
	}

	return to_return;
}

struct Item itemEntry(int sku) {

	struct Item newObject;

	newObject.sku = sku;

	printf("        SKU: %d\n", newObject.sku);
	printf("       Name: ");
	scanf("%20[^\n]", newObject.name);
	flushKeyboard();
	printf("      Price: ");
	scanf("%lf", &newObject.price);
	printf("   Quantity: ");
	scanf("%d", &newObject.quantity);
	printf("Minimum Qty: ");
	scanf("%d", &newObject.minQuantity);
	printf("   Is Taxed: ");

	newObject.isTaxed = yes();

	return newObject;
}

void displayItem(struct Item item, int linear) {
	// Define statements:
	#define LINEAR 1
	#define FORM 0

	if (linear != 0) {
		printf("|%3d|%-20s|%8.2lf|  %3s| %3d | %3d |%12.2lf|%s\n",
			item.sku, item.name, item.price, item.isTaxed == 0 ? "No" : "Yes", item.quantity, item.minQuantity, totalAfterTax(item),
			item.quantity < item.minQuantity ? "***" : "");
		/* I used this way to print Yes or NO for its simplicity. I know this one could be bad but using if and else statements here 
		may have too much spaces just to print these. And I exceptionally divided this one line by three to avoid a very long line 
		which could be hard to follow. */
	}
	else {
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		
		/* The another way to print Yes or No using if and else statments. Used two methods for the same purpose but depending on
		its appropriation. */
		if (item.isTaxed == 0) {
			printf("   Is Taxed: %s", "No\n");
		}
		else {
			printf("   Is Taxed: %s", "Yes\n");
		}

		if (item.quantity < item.minQuantity) {
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}

	}

}

void listItems(const struct Item item[], int noOfItems) {
	int i;						// to count the for loop
	double grandTotal = 0;		// grand total variable

	printTitle();
	for (i = 0; i < noOfItems; i++) {
		printf("%-4d", i + 1);
		displayItem(item[i], LINEAR);
		grandTotal += totalAfterTax(item[i]);
	}
	printFooter(grandTotal);
}

int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index) {
	int exist = 0;				// to return a true or false value
	int i;						// to count the for loop

	for (i = 0; i < NoOfRecs; i++) {
		if (sku == item[i].sku) {
			(*index) = i;
			exist++;
		}
	}

	return exist;
}