#include "Newspaper.h"


Newspaper::Newspaper(string name,string date_of_pub, string edition):name_(name), edition_(edition), date_of_pub_(date_of_pub) {}

void Newspaper::display() {
    cout << "Newspaper title: " << name_ << "   date_of_pub: " << date_of_pub_ << "   edition: " << edition_ << endl; 
}

