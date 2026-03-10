#include <iostream>
using namespace std;
#pragma once
class Book
{
public:
	const int MAX_SIZE_;
	int top_;
	string* books_;
	Book(int max_size);
	void push(string books);
	void pop();
	void peek();
	bool isEmpty();
	bool isFull();
    void display();
    ~Book();
};

