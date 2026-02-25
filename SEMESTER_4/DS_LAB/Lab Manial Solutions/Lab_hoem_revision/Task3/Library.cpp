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

    for (int i = 0; i < books_.size() - 1; i++)
    {
        int smallestIndex = i;
        for (int j = 0; j < books_.size(); j++)
        {
            if (books_[j].pages_ < books_[smallestIndex].pages_) {
                smallestIndex = j;
            }
        }

        swap(books_[smallestIndex], books_[i]);
    }
    
}


void Library::sortNewspapersByEdition() {
    for (int i = 0; i < newspapers_.size() - 1; i++) {
        int smallestIndex = i;
        for (int j = 0; j < newspapers_.size(); j++) {            
            if (newspapers_[j].edition_ < newspapers_[smallestIndex].edition_) {
                smallestIndex = j;
            }
        }
        
        swap(newspapers_[i], newspapers_[smallestIndex]);        
    
    }
    
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