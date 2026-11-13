#include <stdio.h>
#include "employee.h"


int main() {
	int choice = 0;
	while (choice != 6) {
		printf("workplece gender wage gap thingy (this is 'garbage in garbage out' type of data :/)\n");
		printf("choose: \n");
		printf("1. Add employee\n");
		printf("2. Remove employee\n");
		printf("3. Display employees\n");
		printf("4. Search by ID\n");
		printf("5. factually incorrect data calculation\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf_s("%d", &choice);

		switch (choice) {
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
			printf("Invalid choice. Please try again.\n");
			break;
		}
	}
}