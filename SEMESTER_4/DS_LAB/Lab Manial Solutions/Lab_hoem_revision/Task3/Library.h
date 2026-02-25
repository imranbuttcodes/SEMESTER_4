#pragma once
#include "Book.h"
#include "Newspaper.h"
#include <vector>
class Library {
public:
vector<Book> books_;
vector<Newspaper> newspapers_;
void addBook(Book book);
void addNewspaper(Newspaper newspaper);

void displayCollection();

void sortBooksByPages();

void sortNewspapersByEdition();

Book* searchBookByTitle(string title);

Newspaper* searchNewspaperByName(string name); 


};


