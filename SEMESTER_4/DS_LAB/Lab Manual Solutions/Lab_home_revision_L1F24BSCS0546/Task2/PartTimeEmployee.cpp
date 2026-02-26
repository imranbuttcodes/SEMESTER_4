#include "PartTimeEmployee.h"


PartTimeEmployee::PartTimeEmployee(std::string name, int hoursWorked, int hourlyRate) : Employee(name), hoursWorked(hoursWorked), 
hourlyRate(hourlyRate) {}

int PartTimeEmployee::calculateSalary() {
	return hoursWorked * hourlyRate;
}






