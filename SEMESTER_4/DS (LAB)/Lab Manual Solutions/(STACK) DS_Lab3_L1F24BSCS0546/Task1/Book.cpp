#include "Book.h"

Book::Book(int max_size): MAX_SIZE_(max_size) {
	books_ = new string[MAX_SIZE_];
	top_ = -1;
}

void Book::push(string books) {
    if (top_ == MAX_SIZE_ - 1) {
        cout << "Stack Overflow: Stack is full!" << endl;
        return;
    }
    books_[++top_] = books;
}
void Book::pop() {
    if (isEmpty()) {
        cout << "Stack Underflow: Stack is empty!" << endl;
        return;
    }
    books_[top_] = "";
    top_--;
}
void Book::peek() {
    if(!isEmpty()) {
        cout << "Top Element: " << books_[top_]<<endl;
        return;    
    }
    cout << "Stack is Empty right now!" << endl;
}

bool Book::isEmpty() {
    return top_==-1;
}


bool Book::isFull() {
    return top_ == (MAX_SIZE_ - 1);
}

Book::~Book() {
    delete[] books_;
}

    void Book::display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top_; i >= 0; i--) {
            cout << books_[i] << endl;
        }
 }
