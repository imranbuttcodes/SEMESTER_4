#include "Browser_History.h"
#include <iostream>
using namespace std;

// Constructor - allocate memory for stack
BrowserHistory::BrowserHistory(int size) {
    capacity = size;
    top = -1;  // Stack is empty
    history = new string[capacity];
    cout << "Browser history initialized. Can store up to " << capacity << " pages." << endl;
}

// Destructor - free memory
BrowserHistory::~BrowserHistory() {
    delete[] history;
    cout << "Browser history cleared from memory." << endl;
}

// Push - visit a new page
void BrowserHistory::visitPage(string url) {
    if (isFull()) {
        cout << "History full! Cannot store more pages." << endl;
        return;
    }

    top++;
    history[top] = url;
    cout << "Visited: " << url << " (Position: " << top << ")" << endl;
}

// Pop - go back to previous page
void BrowserHistory::goBack() {
    if (isEmpty()) {
        cout << "No history to go back to!" << endl;
        return;
    }

    cout << "Going back from: " << history[top] << endl;
    top--;

    if (!isEmpty()) {
        cout << "Now at: " << history[top] << endl;
    } else {
        cout << "History is now empty." << endl;
    }
}

// Peek - see current page
string BrowserHistory::currentPage() {
    if (isEmpty()) {
        return "No page currently open";
    }
    return history[top];
}

// Check if stack is empty
bool BrowserHistory::isEmpty() {
    return (top == -1);
}

// Check if stack is full
bool BrowserHistory::isFull() {
    return (top == capacity - 1);
}

// Display entire browsing history (from oldest to newest)
void BrowserHistory::displayHistory() {
    if (isEmpty()) {
        cout << "\nNo browsing history available." << endl;
        return;
    }

    cout << "\n=== Browsing History (Oldest to Newest) ===" << endl;
    for (int i = 0; i <= top; i++) {
        cout << i + 1 << ". " << history[i];
        if (i == top) {
            cout << " <-- Current Page";
        }
        cout << endl;
    }
    cout << "==========================================" << endl;
}

// Clear all history
void BrowserHistory::clearHistory() {
    top = -1;
    cout << "All browsing history cleared!" << endl;
}

// Get current size of stack
int BrowserHistory::getSize() {
    return top + 1;
}
