/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

#include <stdio.h>
// Define Number of Employees "SIZE" to be 2
#define SIZE 2

// Declare Struct Employee 
struct Employee {
	int id;
	int age;
	double salary;
};

/* main program */
int main(void) {

	int i; // used to count for loop
	int limit = 0; // used to count limit for the if statement in case 2
	int option = 0;

	printf("---=== EMPLOYEE DATA ===---\n\n");
	// Declare a struct Employee array "emp" with SIZE elements
	struct Employee emp[SIZE] = {{0}};
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option); // Capture input to option variable
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		case 1: // Display Employee Data
				// @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
				}
			}
			printf("\n");
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0
			break;
		case 2:	// Adding Employee
				// @IN-LAB
			printf("Adding Employee\n");
			printf("===============\n");
			if (limit < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[limit].id);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[limit].age);
				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[limit].salary);
				printf("\n");
				limit++;
			}
			else {
				printf("ERROR!!! Maximum Number of Employees Reached\n\n");
			}
			// Check for limits on the array and add employee 
			// data accordingly. 
			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
