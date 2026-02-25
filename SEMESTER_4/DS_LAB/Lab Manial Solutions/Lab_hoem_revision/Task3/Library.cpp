#include <algorithm>
#include "Library.h"


// vector<Book> books_;
// vector<Newspaper> newspapers_;
void Library::addBook(Book book){
    books_.push_back(book);
}

void Library::addNewspaper(Newspaper newspaper) {
    newspapers_.push_back(newspaper);
}

void Library::displayCollection() {
    cout << "-------------- Books ------------------\n";
    for(auto& book: books_) {
        book.display();
    }
    cout << "\n\n";
     cout << "-------------- Newspapers ------------------\n";
    for(auto& newspaper: newspapers_) {
        newspaper.display();
    }

}

void Library::sortBooksByPages() {
    sort(books_.begin(), books_.end(),[](Book book1, Book book2) {
        return book1.pages_ < book2.pages_;
    } );
}


void Library::sortNewspapersByEdition() {
    sort(newspapers_.begin(), newspapers_.end(),[](Newspaper np1, Newspaper np2) {
        return np1.edition_ < np2.edition_;
    } );
}


Book* Library::searchBookByTitle(string title) {
    for(auto& book: books_) {
        if (book.title_ == title) {
            return &book;
        }
    }
    return nullptr;
}


Newspaper* Library::searchNewspaperByName(string name) {
    for (auto& newspaper: newspapers_) {
        if (newspaper.name_ == name) {
            return &newspaper;
        }
    }
    return nullptr;
}