

#include <string>
using namespace std;

class BrowserHistory {
private:
    string* history;     // Pointer to dynamically allocate stack array
    int capacity;        // Maximum stack size
    int top;             // Index of top element (-1 if empty)

public:
    // Constructor and Destructor
    BrowserHistory(int size);
    ~BrowserHistory();

    // Core Stack Operations
    void visitPage(string url);     // Push
    void goBack();                   // Pop
    string currentPage();            // Peek/Top
    bool isEmpty();
    bool isFull();
    void displayHistory();
    void clearHistory();
    int getSize();
};


