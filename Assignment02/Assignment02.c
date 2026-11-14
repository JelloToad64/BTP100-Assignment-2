// Assignment 02 - Wage Gap Calculator
// Angelo Fiorante, Ernesto Mykytyuk Quinones
// November 13, 2026
// This progream allows the user to operate with a database of employees, and calculate the wage gap between two employees.

#include <stdio.h>
#include "employee.h"


int main() { // Worked on by Angelo
	int choice = 0;
	printf("Workplace Employee Management\n");
	printf("Choose an option: \n");

	while (choice != 6) { // Menu loop continues until the user chooses to exit
		printf("1. Add employee\n");
		printf("2. Remove employee\n");
		printf("3. Display employees\n");
		printf("4. Search by ID\n");
		printf("5. factually incorrect data calculation\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) { // switch statement to handle user choices and call the functions.
			case 1:
				addEmployee();
				break;
			case 2:
				removeEmployee();
				break;
			case 3:
				displayEmployees();
				break;
			case 4:
				searchByID();
				break;
			case 5:
				calculateWageGap();
				break;
			case 6:
				printf("Exiting the program.\n");
				break;
			default:
				printf("Invalid choice. Please try again.\n\n");
				break;
		}
	}
}