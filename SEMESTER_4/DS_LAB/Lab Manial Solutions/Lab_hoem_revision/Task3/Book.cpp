#include "Book.h"

Book::Book(string title, string auther, int pages): title_(title), auther_(auther), pages_(pages) {}

void Book::display() {
    cout << "Book title: " << title_ << "   Auther: " << auther_ << "   Pages: " << pages_ << endl; 
}