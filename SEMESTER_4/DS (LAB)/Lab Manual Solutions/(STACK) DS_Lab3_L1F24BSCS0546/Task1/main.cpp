#include <iostream>
#include <string>
#include "Book.h"

using namespace std;

int main() {
    string choice;
    string book_name;
    Book books(5);
    while(true) {
        cout << "[1] Insert(push) Book\n";
        cout << "[2] remove(pop) Book\n";
        cout << "[3] peek\n";
        cout << "[4] Display Stack\n";
        cout << "[0] Exit\n";
        cout << "Enter Your Choice: ";
        getline(cin, choice);
        if (choice == "0")  {
            cout << "Exiting....";
            break;
        }
        if (choice == "1") {
            cout << "Enter Book Name to insert: ";
            getline(cin, book_name);
            books.push(book_name);
        } else if (choice == "2") {
            books.pop();
        } else if (choice == "3") {
            books.peek();
        } else if (choice == "4") {
            books.display();
        }
        
        else {
            cout << "Invalid Input!" << endl;
        }
        
    }
    return 0;
}