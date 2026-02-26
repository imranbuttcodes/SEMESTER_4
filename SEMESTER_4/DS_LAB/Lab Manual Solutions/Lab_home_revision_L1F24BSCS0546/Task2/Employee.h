#pragma once
#include <iostream>
class Employee
{
public:
	virtual int calculateSalary() = 0;
	std::string name_;
	Employee(std::string name) : name_(name) {}

};

