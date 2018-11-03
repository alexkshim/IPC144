/*********************************************************
Name: Kyuyoung Shim
ID: 102-562-162
Section: MM
*********************************************************/

// Copy your source code from in_lab file to here
// Expand the option list to include option 3 & 4 after 
// option 2. as following
// "3. Update Employee Salary"
// "4. Remove Employee"

#include <stdio.h>
#define SIZE 4

// Declare Struct Employee 
struct Employee {
	int id;
	int age;
	double salary;
};

/* main program */
int main(void) {

	int i; // used to count loops
	int limit = 0; // used for the if statement in case 2
	int check = 0; // the input for checking in case 3
	int tNum = 0; // temporary number in case 3
	int cf; // confirm if there is the matching id in case 3
	int option = 0;
	//int EMPnum = 0; // EMP numbers

	printf("---=== EMPLOYEE DATA ===---\n\n");
	// Declare a struct Employee array "emp" with SIZE elements
	struct Employee emp[SIZE] = { { 0 } };
	// and initialize all elements to zero

	do {
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option); // Capture input to option variable
		printf("\n");

		switch (option) {
		case 0:
		{	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			break;
		}
		case 1: 
		{         // Display Employee Data
				  // @IN-LAB
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");
			for (i = 0; i < SIZE; i++) {
				if (emp[i].id > 0 && emp[i].age > 0 && emp[i].salary > 0) {
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
		}

		case 2:
		{         // Adding Employee
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
		}

		case 3:
		{	//update employee salary
			printf("Update Employee Salary\n");
			printf("======================\n");
			do {
				cf = 0; // this will reset the confirmation
				printf("Enter Employee ID: ");
				scanf("%d", &check);
				for (i = 0; i < SIZE; i++) {
					if (check == emp[i].id) {
						tNum = i;
						cf++;
					}
				}
			} while (cf == 0);
			printf("The current salary is %.2lf\n", emp[tNum].salary);
			printf("Enter Employee New Salary: ");
			scanf("%lf", &emp[tNum].salary);
			printf("\n");
			break;
		}

		case 4:
		{	// remove employee
			printf("Remove Employee\n");
			printf("===============\n");
			do {
				cf = 0; // this will reset the confirmation
				printf("Enter Employee ID: ");
				scanf("%d", &check);
				for (i = 0; i < SIZE; i++) {
					if (check == emp[i].id) {
						tNum = i;
						cf++;
					}
				}
			} while (cf == 0);
			printf("Employee %d will be removed\n\n", emp[tNum].id);
			emp[tNum].id = 0;
			emp[tNum].age = 0;
			emp[tNum].salary = 0;
			break;
		}

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}

// Create two switch-cases for option 3 & 4 after case 2. 
// Implement "Update Salary" and "Remove Employee" 
// functionality as per instructions
// inside the relevant case statements


// PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 5

ERROR: Incorrect Option: Try Again

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 113
Enter Employee Age: 53
Enter Employee Salary: 120345.78

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 114
Enter Employee Age: 25
Enter Employee Salary: 46780

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 3

Update Employee Salary
======================
Enter Employee ID: 112
The current salary is 65000.00
Enter Employee New Salary: 99999.99

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   99999.99
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 4

Remove Employee
===============
Enter Employee ID: 112
Employee 112 will be removed

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
113       53  120345.78
114       25   46780.00

1. Display Employee Information
2. Add Employee
3. Update Employee Salary
4. Remove Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!
*/