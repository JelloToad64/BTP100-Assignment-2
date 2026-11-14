// Whole file worked on by Angelo and Ernesto

#define MAX_NAME_LENGTH 100
#define MAX_GENDER_LENGTH 50
#define MAX_ETHNICITY_LENGTH 50
#define MAX_EMPLOYEES 100

struct Employee { // employee struct to hold employee data
	int id;
	char name[MAX_NAME_LENGTH];
	float salary;	
	char gender[MAX_GENDER_LENGTH];
	char ethnicity[MAX_ETHNICITY_LENGTH];
};

struct Employee employees[MAX_EMPLOYEES]; 
int employeeCount = 0;

void addEmployee() { // function to add an employee to the database

	if (employeeCount >= MAX_EMPLOYEES) {
		printf("Database is full!\n");
		return;
	}

	printf("Enter Employee ID: ");
	scanf_s("%d", &employees[employeeCount].id);

	while (getchar() != '\n');

	printf("Enter Employee Name: ");
	fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
	employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = 0;

	printf("Enter Employee Salary: ");
	scanf_s("%f", &employees[employeeCount].salary);

	while (getchar() != '\n');

	printf("Enter Employee Gender: ");
	fgets(employees[employeeCount].gender, sizeof(employees[employeeCount].gender), stdin);
	employees[employeeCount].gender[strcspn(employees[employeeCount].gender, "\n")] = 0;

	printf("Enter Employee Ethnicity: ");
	fgets(employees[employeeCount].ethnicity, sizeof(employees[employeeCount].ethnicity), stdin);
	employees[employeeCount].ethnicity[strcspn(employees[employeeCount].ethnicity, "\n")] = 0;

	employeeCount++;
}

void removeEmployee() { // function to remove an employee from the database by ID

	int searchId;
	int found = 0;
	
	if (employeeCount == 0) {
		printf("No employees in the database.\n\n");
		return;
	}

	printf("Enter the ID of the employee to remove: ");
	scanf_s("%d", &searchId);

	for (int i = 0; i < employeeCount; i++) {
		if (employees[i].id == searchId) {
			for (int j = i; j < employeeCount - 1; j++) {
				employees[j] = employees[j + 1];
			}
			employeeCount--;
			found = 1;
			printf("Employee #%d removed from database.\n\n", searchId);
			break;
		}
	}

	if (!found) {
		printf("No matching ID found.");
	}
}

void displayEmployees() { // function to display all employees in the database
	if (employeeCount == 0) {
		printf("No employees in the database.\n\n");
		return;
	}

	printf("\n--- Employee Records ---\n");
	for (int i = 0; i < employeeCount; i++) {
		printf("#%d | Name: %s | Salary: $%.2f | Gender: %s | Ethnicity: %s\n",
			employees[i].id,
			employees[i].name,
			employees[i].salary,
			employees[i].gender,
			employees[i].ethnicity);
	}
}

void searchByID() { // function to search for an employee by ID and display their information

	int idRequest;
	int found = 0;

	printf("Enter an ID: ");
	scanf_s("%d", &idRequest);

	for (int i = 0; i < employeeCount; i++)
		if (employees[i].id == idRequest) {
			printf("Found ID: #%d \n", employees[i].id);
			printf("Name: %s | Salary: $%.2f | Gender: %s | Ethnicity: %s\n",
				employees[i].id,
				employees[i].name,
				employees[i].salary,
				employees[i].gender,
				employees[i].ethnicity);
			found = 1;
		}

	if (!found) {
		printf("No employee found with ID: #%d\n\n", idRequest);
	}
	return;
}

void calculateWageGap() { // function to calculate the wage gap between two employees based on their IDs

	int idCheckOne, idCheckTwo;
	float salaryOne = 0.0f, salaryTwo = 0.0f;
	float wageGap;

	printf("Enter the ID of the first employee: ");
	scanf_s("%d", &idCheckOne);

	printf("Enter the ID of the second employee: ");
	scanf_s("%d", &idCheckTwo);

	for (int i = 0; i < employeeCount; i++)
		if (employees[i].id == idCheckOne) {
			salaryOne = employees[i].salary;
		}

	for (int i = 0; i < employeeCount; i++)
		if (employees[i].id == idCheckTwo) {
			salaryTwo = employees[i].salary;
		}

	if (salaryOne == 0.0f || salaryTwo == 0.0f) {
		printf("One or both employee IDs not found.\n");
	}
	else {
		if (salaryOne < salaryTwo) { // check to ensure the wage gap a positive number
			int temp = salaryOne;
			salaryOne = salaryTwo;
			salaryTwo = temp;
		}

		wageGap = salaryOne - salaryTwo;
		printf("The wage gap between them is $%.2f\n", wageGap);
	}
}
