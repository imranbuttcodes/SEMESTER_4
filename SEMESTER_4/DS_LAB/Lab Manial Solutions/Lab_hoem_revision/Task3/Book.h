#pragma once
#include <iostream>
using namespace std;

class Book {
public:
string title_, auther_;
int pages_;
Book(string title, string auther, int pages);
void display();
};