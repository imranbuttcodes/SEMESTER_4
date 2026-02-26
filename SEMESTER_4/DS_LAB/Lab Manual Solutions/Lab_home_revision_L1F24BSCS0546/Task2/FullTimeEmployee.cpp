#include "FullTimeEmployee.h"


int FullTimeEmployee::calculateSalary() {
	return salary;
}


FullTimeEmployee::FullTimeEmployee(std::string name, int salary): Employee(name), salary(salary) {}

