#include <iostream>
using namespace std;

class My_Stack {
public:
char* data_;
int Max_size_;
int top_;
My_Stack(int size) {
    Max_size_ = size;
    data_ = new char[Max_size_];
    top_ = -1;
}

void push(char s) {
     if (isFull()) {
        cout << "Overflow: Stack Is Full!" << endl;
        return;
     }
     data_[++top_] = s; 
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
    delete[] data_;
}
};

bool isBalanced(string str) {
    if (str.empty())       return false;
    My_Stack my_stack(str.size());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            my_stack.push(str[i]);
        } else if (str[i] == ')') {
            if(my_stack.isEmpty()) {
                return false;
            }
            my_stack.pop();
        }
    }
    return my_stack.isEmpty();
}


int main() {
    string Expression = "((a + b) * (c - d))";
    cout << "Expression: " << Expression << endl;
    cout << (isBalanced(Expression) ? "Balanced": "Not Balanced") << endl;
    return 0;
}