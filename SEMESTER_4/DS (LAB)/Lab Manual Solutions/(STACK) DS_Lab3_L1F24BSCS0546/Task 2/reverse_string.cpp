#include <iostream>
using namespace std;

class My_Stack {
public:
char* string_to_reverse_;
int Max_size_;
int top_;
My_Stack(int size) {
    Max_size_ = size;
    string_to_reverse_ = new char[Max_size_];
    top_ = -1;
}

void push(char s) {
     if (isFull()) {
        cout << "Overflow: Stack Is Full!" << endl;
        return;
     }
     string_to_reverse_[++top_] = s; 
}

char top() {
    if (isEmpty()) {
        cout << "Underflow: Stack Is Empty!" << endl;
        return ' ';
    }
    return string_to_reverse_[top_--];

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
~My_Stack() {
    delete[] string_to_reverse_;
}
};

string reverse_String(string str) {
    int n = str.size();
    My_Stack my_stack(n);
    for (char c: str) {
        my_stack.push(c);
    }
    string reversed_str = "";
    
    while (!my_stack.isEmpty()) {
        reversed_str += my_stack.top();
    }
    return reversed_str;
}


int main() {
    string str = "HELLO";
    cout << "Original String: " << str << endl;
    cout <<"Reversed String: " << reverse_String(str) << endl;
    return 0;
}