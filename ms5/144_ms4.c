/* 1. Commented Header (your name, ID etc...) */
/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/


/* 2. #define _CRT_SECURE_NO_WARNINGS(if you require this) */
#define _CRT_SECURE_NO_WARNINGS


/* 3. #include ..... (any required library's) */
#include <stdio.h>
#include <string.h>

/* 3-2. #define .....  (what ever defines you need) */
#define STOCK 			1
#define CHECKOUT 		0
#define MAX_ITEM_NO 	500
#define MAX_QTY 		999
#define SKU_MAX 		999
#define SKU_MIN 		100
#define DATAFILE "items.txt"

/* 4. struct types(what ever struct's are required) */
// Item structure:
struct Item {
	double price;			// price of a unit of the item
	int sku;				// Stock Keeping Unit, a 3 digit integer
	int isTaxed;			// an integer Flag, if true (non-zero), the tax is applied in price calculations
	int quantity;			// the quantity of the time in the inventory
	int minQuantity;		// the minimum quantity number in inventory
	char name[21];			// a 20 character, C string to keep the name of the item
};


/* 5. Global variables(if required - only when instructed though) */
// Constant TAX value:
const double TAX = 0.13;


/* 6. Function prototypes .... */
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

// Function Prototypes Milestone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Function Prototypes Milestone 3:
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// Function Prototypes Milestone 4:
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);

// Function Prototypes Milestone Assembly:
void saveProcedures(const struct Item item[], char fileName[], int NoOfRecs);

// Function Prototypes Milestone 5:
// No prototypes in this milestone

/* 7. main() function */
int main(void) {
	GroceryInventorySystem();
	return 0;
}


/* 8. Function definitions .... */
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
	int result = 0;				// to return the permitted value

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
	double result;				// to return the permitted value
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
	int loopEnd = 0;								// anything non-zero is to end the loop
	int option = 0;									// the option for switch statement 0 to 7
	struct Item items[MAX_ITEM_NO] = { { 0 } };		// Create an array of Items. Use MAX_ITEM_NO for its size.
	int NumOfRecs = 0;								// Create an integer variable to Hold the number of records read.
	// variables above cover case 1, 2, 3, 4, 5
	int validSku = 0;								// to hold a valid sku number from SKU_MIN to SKU_MAX
	int targetedIndex = 0;							// to hold the targeted index of array removed
	int checkItem = 0;								// to check if the item exists
	int i;											// to count the for loops
	// variables above cover case 6 (delete)
	char input[21] = { 0 };							// to hold the user input
	char *matching;									// to check if the name is matching, this will return NULL otherwise, returning non-zero value 
	int noItemFound = 1;							// to print the message if no item is found
	// variables above cover case 7 (search by name)

	welcome(); // After the welcome() message

	if (DATAFILE != NULL) {
		if (loadItems(items, DATAFILE, &NumOfRecs) == 0) {
			// use the loadItems() function to fill the Items array you created with the Item records kept in the data file.
			// The name of the data file is defined in DATAFILE.
			printf("Could not read from %s.\n", DATAFILE);
			// If the loadItems fails, print the following message and exit the program and
			// replace %s with defined value in DATAFILE
		}
		else {
			// If loadItems is successful, run the menu section and action selection
			while (loopEnd == 0) {

				option = menu();
				switch (option)
				{
				case 1:
					// If 1 is selected: 
					listItems(items, NumOfRecs);
					// Call the listItems function passing the item array and the number of records
					pause();
					break;
				case 2:
					// If 2 is selected:
					printf("Please enter the SKU: ");
					search(items, NumOfRecs);
					// Call the search function passing the item array and the number of records
					pause();
					break;
				case 3:
					// If 3 is selected: 
					printf("Please enter the SKU: ");
					adjustQuantity(items, NumOfRecs, CHECKOUT);
					// Call the adjustQuantity function passing the item array, the number of records and CHECKOUT.

					saveProcedures(items, DATAFILE, NumOfRecs);
					// Then, call the saveItems function passing the item array, 
					// DATAFILE, and the number of records to apply the changes to the DATAFILE.

					pause();
					break;
				case 4:
					// If 4 is selected: 
					printf("Please enter the SKU: ");
					adjustQuantity(items, NumOfRecs, STOCK);
					// Do exactly what you have done in option 3 but pass STOCK to adjustQuantity instead of CHECKOUT.

					saveProcedures(items, DATAFILE, NumOfRecs);
					// the same as in case 3

					pause();
					break;
				case 5:
					// If 5 is selected:
					printf("Please enter the SKU: ");
					addOrUpdateItem(items, &NumOfRecs);
					// Call the addOrUpdateItem function passing the item array and the address of the number of records.

					saveProcedures(items, DATAFILE, NumOfRecs);
					// the same as in case 3 and 4

					pause();
					break;
				case 6:
					printf("Please enter the SKU: ");			// Ask for an SKU:
					validSku = getIntLimited(SKU_MIN, SKU_MAX);	// this function stands for the reusability. 

					checkItem = locateItem(items, NumOfRecs, validSku, &targetedIndex);
					// and search for the item using locateItem function.
					
					if (checkItem == 0) {
						// If not found, display: "SKU not found!\n"
						printf("SKU not found!\n");
						// And display the menu after a pause.
						// a pause and display menu will be done at the very bottom of case 6
					}

					else {
						// If item was found,

						displayItem(items[targetedIndex], 0); // FORM (0)
						// display it and then, display:

						printf("This Item will be deleted, are you sure? (Y)es/(N)o: ");
						// and ask for user’s confirmation to delete the item from the list.

						if (yes() != 1) {	// using yes() function for reusability
							// If the user enters “N” for no, display:
							printf("Aborted!\n");
							// and display the menu after a pause
							// Since anything is after this if statement, 
							// a pause and displaying menu will be done at the bottom.
						}

						else {
							// If user enters “Y” for yes, 

							FILE *fp = fopen(DATAFILE, "w"); // opening the file for write mode
							
							for (i = 0; i < targetedIndex; i++) {
								saveItem(items[i], fp);
								// then overwrite the data file by saving the items one by one,
							}
							for (i = targetedIndex + 1; i < NumOfRecs; i++) {
								// skipping the one you want to delete.
								saveItem(items[i], fp);
							}

							fclose(fp);

							loadItems(items, DATAFILE, &NumOfRecs);	// reusability of the function
							// Then load the items back and display: "Deleted!\n"
							printf("Deleted!\n");
							// And display the menu after a pause.
						}

					}

					pause();
					break;
				case 7:	
					// this case is also able to search more than just 1 items at every single one time

					noItemFound = 1; // reset to make it valid for every case

					printf("Please enter part of the name: "); // Display:
					scanf(" %20[^\n]", input);
					// Then receive a string including spaces.

					flushKeyboard(); // for the proper output

					for (i = 0; i < MAX_ITEM_NO; i++) {
						// Loop through the items array and using strstr function in <string.h>
						matching = strstr(items[i].name, input);
						// check each of item’s name for a substring matching the entered string. 

						if (matching != NULL) {
							// If there is a match
							noItemFound--; // not to show the message indicating there is no item 
							displayItem(items[i], 0);
							// display the item and continue until the end of the items array.
							pause(); // for the proper output
						}

					}

					if (noItemFound == 1) {
						// If there is no item name that includes the entered substring, display:
						printf("No Item found in the system matching the value entered!\n");
						// Then exit search, pause and display the menu.
						pause();
					}

					break;
				
				case 0:
					// Option 0 remains the same.
					printf("Exit the program? (Y)es/(N)o): ");
					if (yes()) { // true (1) is Yes and false (0) is No
						loopEnd++;
					}
					break;
				default:
					break;
				}

			}//loop end
		}
	}

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

	if (item.quantity <= item.minQuantity) {
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
	scanf(" %20[^\n]", newObject.name);
	flushKeyboard();
	printf("      Price: ");
	newObject.price = getDoubleLimited(0.01, 1000.00);
	printf("   Quantity: ");
	newObject.quantity = getIntLimited(1, MAX_QTY);
	printf("Minimum Qty: ");
	newObject.minQuantity = getIntLimited(0, 100);
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
	}
	else {
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);

		if (item.isTaxed == 0) {
			printf("   Is Taxed: %s", "No\n");
		}
		else {
			printf("   Is Taxed: %s", "Yes\n");
		}

		if (isLowQuantity(item)) {
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


// Function Implementations Milestone 3:
void search(const struct Item item[], int NoOfRecs) {
	int tempSku = 0;			// to hold user input of the sku number
	int checkItem = 0;			// to check whether the item found
	int tempIndex = 0;			// to hold the temporary index

	tempSku = getIntLimited(SKU_MIN, SKU_MAX);

	checkItem = locateItem(item, NoOfRecs, tempSku, &tempIndex);
	if (checkItem > 0) {
		displayItem(item[tempIndex], FORM);
	}
	else {
		printf("Item not found!\n");
	}
}

void updateItem(struct Item* itemptr) {
	struct Item instItem;		// Create an instance of struct Item, to hold the temporary structure
	char trueFalse = 0;			// to check true(1) or false(0)

	printf("Enter new data:\n");
	instItem = itemEntry(itemptr->sku);

	printf("Overwrite old data? (Y)es/(N)o: ");
	trueFalse = yes();
	if (trueFalse == 1) {
		*itemptr = instItem;	// overwrite the target of itemptr by the Item instance 
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
}

void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item tempItem;	// create an structure of the Item to hold temporary structure
	int check = 0;			// to check yes or no

	if (*NoOfRecs == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		tempItem = itemEntry(sku);	// get the details of the new Item with the SKU from the argument
		printf("Add Item? (Y)es/(N)o: ");
		check = yes();
		if (check == 1) {
			item[*NoOfRecs] = tempItem;	// set the Item after the last one in the item array 
			(*NoOfRecs)++;				// add one to the targGret of NoOfRecs pointer 
			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int tempSku = 0;			// to hold user input of the sku number
	int checkItem = 0;			// to check whether the item exists
	int tempIndex = 0;			// to hold the temporary index
	int trueFalse = 0;			// to hold the user input yes or no

	tempSku = getIntLimited(SKU_MIN, SKU_MAX);

	checkItem = locateItem(item, *NoOfRecs, tempSku, &tempIndex);	// locating the item in the item array
	if (checkItem == 1) {
		displayItem(item[tempIndex], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		trueFalse = yes();
		if (trueFalse == 1) {
			updateItem(&item[tempIndex]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, tempSku);
	}
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {
	int validSku = 0;			// to hold the user input of the valid sku number
	int checkItem = 0;			// to check whether the item exists
	int tempIndex = 0;			// to hold the temporary index
	int zeroToAbort = 0;		// user input of the quantity but zero to abort

	validSku = getIntLimited(SKU_MIN, SKU_MAX);

	checkItem = locateItem(item, NoOfRecs, validSku, &tempIndex);
	if (checkItem != 1) {
		printf("SKU not found in storage!\n");
	}
	else {
		displayItem(item[tempIndex], FORM);

		printf("Please enter the quantity ");
		/* If the value of stock argument is STOCK or CHECKOUT */
		if (stock == STOCK) {
			printf("%s;", "to stock");
			printf(" Maximum of %d or 0 to abort: ", MAX_QTY - item[tempIndex].quantity);
			zeroToAbort = getIntLimited(0, MAX_QTY - item[tempIndex].quantity);
		}
		else if (stock == CHECKOUT) {
			printf("%s;", "to checkout");
			printf(" Maximum of %d or 0 to abort: ", item[tempIndex].quantity);
			zeroToAbort = getIntLimited(0, item[tempIndex].quantity);
		}

		/* If the number input is zero or not */
		if (zeroToAbort == 0) {
			printf("--== Aborted! ==--\n");
		}
		else {
			if (stock == STOCK) {
				item[tempIndex].quantity += zeroToAbort;
				printf("--== Stocked! ==--\n");
			}
			else if (stock == CHECKOUT) {
				item[tempIndex].quantity -= zeroToAbort;
				printf("--== Checked out! ==--\n");
			}
		}
	}
	// if the quantity of the item is low, print the warning
	if (isLowQuantity(item[tempIndex])) {
		printf("Quantity is low, please reorder ASAP!!!\n");
	}

}

// Function Implementations Milestone 4:
void saveItem(struct Item item, FILE* dataFile) {
	if (dataFile != NULL) {
		// this function doesn't control the file state coming into it via the parameter,
		// it should at least check to see if the pointer is not null because it may have been called before the file object was opened.
		fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
	}
}

int loadItem(struct Item* item, FILE* dataFile) {
	int to_return = 0;

	if (dataFile != NULL) {
		// this function doesn't control the file state coming into it via the parameter,
		// it should at least check to see if the pointer is not null because it may have been called before the file object was opened.
		if (fscanf(dataFile, "%d,%d,%d,%lf,%d,%20[^\n]",
			&(item->sku), &(item->quantity), &(item->minQuantity), &(item->price), &(item->isTaxed), item->name) == 6) {
			to_return++;
		}
	}

	return to_return;
}

int saveItems(const struct Item item[], char fileName[], int NoOfRecs) {
	int to_return = 0;	// if not opened successfully, it returns zero otherwise returning one
	int i;				// to count the for loop

	FILE *fp = fopen(fileName, "w");

	if (fp != NULL) {
		for (i = 0; i < NoOfRecs; i++) {
			saveItem(item[i], fp);

		}

		to_return++;

		fclose(fp);
	}

	return to_return;
}

int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr) {
	int to_return = 0;		// if not opened successfully, it returns zero otherwise returning one
	int count = 0;			// to count the number in the while loop

	FILE *fp = fopen(fileName, "r");

	if (fp != NULL) {
		rewind(fp);			// to print from the first line whenever it is opened
		while (loadItem(&item[count], fp) != 0) {
			count++;
		}

		*NoOfRecsPtr = count;

		to_return++;

		fclose(fp);
	}

	return to_return;
}

// Function Implementations Milestone Assembly:
void saveProcedures(const struct Item item[], char fileName[], int NoOfRecs) {
	if (fileName != NULL) {
		if (saveItems(item, fileName, NoOfRecs) == 0) {
			// If saveITems fails, print the following message : "could not update data file %s\n" replacing %s with DATAFILE.
			printf("could not update data file %s\n", DATAFILE);
		}
	}
	// Note: as you see the save procedures in options 3, 4, and 5 are identical.
	// You could create a function and call it to prevent redundancy.
}

// Function Implementations Milestone 5:
// No function implementation in this milestone