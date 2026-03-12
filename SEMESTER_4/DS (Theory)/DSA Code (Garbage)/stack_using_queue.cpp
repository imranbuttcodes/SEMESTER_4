#include <iostream>
#include <queue>
using namespace std;
void display(queue<int> q1);
class MyStack {
public:
queue<int> q1,q2;
void push_bro(int val) {
    if (q1.empty()) {
        q1.push(val);
        cout << "Current Q1: ";
        display(q1);
        return;
    }
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(val);
    while(!q2.empty()) {
        q1.push(q2.front());
        q2.pop();
    }
    cout << "Current Q1: ";
    display(q1);

}

void pop_bro() {
    if (!q1.empty()) {
        cout << "UNDERFLOW!" ;
        return;
    }
    q1.pop();
}
};

void display(queue<int> q1) {
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
    cout << endl;
}
int main() {
    MyStack ms;
    ms.push_bro(1);
    ms.push_bro(2);
    ms.push_bro(3);
    ms.push_bro(4);
    ms.pop_bro();
    display(ms.q1); 
    
    return 0;
}