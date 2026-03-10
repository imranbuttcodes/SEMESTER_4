
#include <iostream>
#include <string>
using namespace std;


class CallStack {
public:
string* calls_;
int Max_size_;
int top_;
CallStack(int size) {
    Max_size_ = size;
    calls_ = new string[Max_size_];
    top_ = -1;
}

void push(string s) {
     if (isFull()) {
        cout << "Overflow: Stack Is Full!" << endl;
        return;
     }
     calls_[++top_] = s; 
}

string peek() {
    if (isEmpty()) {
        cout << "Underflow: Stack Is Empty!" << endl;
        return "";
    }
    return calls_[top_];

}


void display() {
     if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = top_; i >= 0; i--) {
            cout << calls_[i] << endl;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Underflow: Stack Is Empty!" << endl;
        return ;
    }
    top_--;
}

bool isFull() {
    return top_ == Max_size_ - 1;
}

bool isEmpty() {
    return top_ == -1;
}

~CallStack() {
    delete[] calls_;
}

};

int main() {
    
    int maxCalls;
    cout << "Enter maximum number of calls: ";
    cin >> maxCalls;
    cin.ignore();
    CallStack myCalls(maxCalls);

    string choice;
    string callName;

    while(true) {
        cout << "\n==== Mobile Call Stack Menu ====" << endl;
        cout << "1. Push (New Call)" << endl;
        cout << "2. Pop (End Current Call)" << endl;
        cout << "3. Peek (Check Current Call)" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Display All Calls" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        getline(cin, choice);
        if (choice == "1" ) {
            
                cout << "Enter call name/number: ";
                getline(cin, callName);
                myCalls.push(callName);
        } else if (choice == "2"){
                myCalls.pop();
        }
        else if (choice == "3"){
                cout << "Current call: " << myCalls.peek() << endl;
        }else if (choice == "4") {
                if(myCalls.isEmpty()) 
                    cout << "No ongoing calls." << endl;
                else 
                    cout << "There are ongoing calls." << endl;
        } else if (choice == "5") {
                cout << "All ongoing calls:" << endl;
                myCalls.display();
        } else if (choice == "0") {
                cout << "Exiting program." << endl;
                break;
        } else {
                cout << "Invalid choice! Try again." << endl;
        }

    }

    return 0;
}


