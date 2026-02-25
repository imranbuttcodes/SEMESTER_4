#pragma once
#include "Employee.h"
class FullTimeEmployee :public Employee
{
public:
	int salary;
	FullTimeEmployee(std::string name, int salary);
	int calculateSalary() override;
	
};

