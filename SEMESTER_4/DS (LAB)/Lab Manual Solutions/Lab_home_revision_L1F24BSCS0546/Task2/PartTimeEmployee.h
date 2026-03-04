#pragma once
#include "Employee.h"

class PartTimeEmployee : public Employee
{
public:
	int hoursWorked, hourlyRate;
	PartTimeEmployee(std::string name, int hoursWorked, int hourlyRate);
	int calculateSalary() override;
};



