/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#include <stdio.h>
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


// code your functions here:

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
	int i = 0;					//keep looping if the condition is not ture
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
	int i = 0;					//keep looping if the condition is not ture
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
			pause(void);
			break;
		case 2:
			printf("Search Items under construction!\n");
			pause(void);
			break;
		case 3:
			printf("Checkout Item under construction!\n");
			pause(void);
			break;
		case 4:
			printf("Stock Item under construction!\n");
			pause(void);
			break;
		case 5:
			printf("Add/Update Item under construction!\n");
			pause(void);
			break;
		case 6:
			printf("Delete Item under construction!\n");
			pause(void);
			break;
		case 7:
			printf("Search by name under construction!\n");
			pause(void);
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