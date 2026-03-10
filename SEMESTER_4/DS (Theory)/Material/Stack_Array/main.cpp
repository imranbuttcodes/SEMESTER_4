#include "Browser_History.h"
#include <iostream>
using namespace std;

int main() {
    // Create browser history with capacity of 5 pages
    BrowserHistory myHistory(5);

    cout << "\n=== BROWSER SESSION STARTED ===\n" << endl;

    // Simulate browsing - PUSH operations
    cout << "--- Visiting websites ---" << endl;
    myHistory.visitPage("google.com");
    myHistory.visitPage("youtube.com");
    myHistory.visitPage("github.com");
    myHistory.visitPage("stackoverflow.com");
    myHistory.visitPage("wikipedia.org");

    // Try to visit one more (stack full)
    myHistory.visitPage("netflix.com");

    // Display current history
    myHistory.displayHistory();

    // Check current page (PEEK)
    cout << "\n--- Current Session ---" << endl;
    cout << "Currently viewing: " << myHistory.currentPage() << endl;
    cout << "Pages in history: " << myHistory.getSize() << endl;

    // Navigate back (POP operations)
    cout << "\n--- Navigating Back ---" << endl;
    myHistory.goBack();  // Back from wikipedia
    myHistory.goBack();  // Back from stackoverflow
    myHistory.goBack();  // Back from github

    // Check current page after going back
    cout << "\n--- After Going Back ---" << endl;
    cout << "Currently viewing: " << myHistory.currentPage() << endl;
    myHistory.displayHistory();

    // Visit new page after going back (PUSH after POP)
    cout << "\n--- Visiting new page after going back ---" << endl;
    myHistory.visitPage("medium.com");
    myHistory.displayHistory();

    // Clear history
    cout << "\n--- Clearing History ---" << endl;
    myHistory.clearHistory();

    // Try operations on empty stack
    cout << "\n--- Testing empty stack ---" << endl;
    cout << "Is history empty? " << (myHistory.isEmpty() ? "Yes" : "No") << endl;
    cout << "Current page: " << myHistory.currentPage() << endl;
    myHistory.goBack();  // Try to pop from empty stack

    cout << "\n=== BROWSER SESSION ENDED ===" << endl;

    // Destructor automatically called
    return 0;
}
