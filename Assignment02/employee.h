#define MAX_NAME_LENGTH 50
#define MAX_GENDER_LENGTH 10
#define MAX_ETHNICITY_LENGTH 20
#define MAX_EMPLOYEES 100

struct Employee{
	int id;
	char name[MAX_NAME_LENGTH];
	float salary;	
	char gender[MAX_GENDER_LENGTH];
	char ethnicity[MAX_ETHNICITY_LENGTH];
};

struct Employee employees[MAX_EMPLOYEES];

void addemployee() {}
void removeemployee() {}
void displayemployees() {}
void searchbyid() {}
void calculatewagegap() {}
