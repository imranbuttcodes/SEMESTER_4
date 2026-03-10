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

char top() {
    if (isEmpty()) {
        cout << "Underflow: Stack Is Empty!" << endl;
        return ' ';
    }
    return data_[top_];

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


int precedence(char opt) {

    if (opt == '^')        return 3;
    if (opt == '*' || opt == '/' )     return 2;
    if (opt == '+' || opt == '-')   return 1;
    return 0;
}


string infix_to_postfix(string infix) {
    if (infix.empty())  return infix;
    string postfix = "";
    My_Stack my_stack(infix.size());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == ' ')    continue;
        if (isalnum(infix[i]))  {
            postfix += infix[i];        
        } else if (infix[i] == '(') {
            my_stack.push(infix[i]);
        } else if (infix[i] == ')') {
            while (my_stack.top() != '(' && !my_stack.isEmpty()) {
                postfix += my_stack.top();
                my_stack.pop();
            }
            my_stack.pop();
        } else {
            if (my_stack.isEmpty()) {
                my_stack.push(infix[i]);
            } 
            else {
                if (precedence(infix[i]) > precedence(my_stack.top())) {
                    my_stack.push(infix[i]);
                } else {
                    postfix += my_stack.top();
                    my_stack.pop();
                    my_stack.push(infix[i]);
                }
               
                
            } 
        }
  
    }

    while (!my_stack.isEmpty()) {
        postfix += my_stack.top();
        my_stack.pop();
    }

    return postfix;
    
}

int main() {
    string Expression = "(A+B)*C + (D / E)";
    cout << "Infix: " << Expression << endl; 
    string postfix = infix_to_postfix(Expression);
    cout << "FINAL PostFix: " << postfix << endl;
    return 0;
}