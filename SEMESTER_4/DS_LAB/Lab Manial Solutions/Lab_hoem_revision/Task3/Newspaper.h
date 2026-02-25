#pragma once
#include <iostream>
using namespace std;
class Newspaper
{
public:

	string name_, edition_, date_of_pub_;
	Newspaper(string name,string date_of_pub, string edition);

	void display();
};

