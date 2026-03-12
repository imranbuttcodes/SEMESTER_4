#include <iostream>
using namespace std;

class Queue {
public:
int MAX_SIZE_;
int front_, rear_;
int* arr_;
Queue(int size): MAX_SIZE_(size) {
    front_ = rear_ = -1;
    arr_ = new int[MAX_SIZE_];
}

bool isEmpty() {
    return front_ == -1 && rear_ == -1;
}

bool isFull() {
    return rear_ == MAX_SIZE_ - 1;
}

void Enqueue(int val) {

    if (isEmpty()) {
        front_ = rear_ = 0;
        arr_[front_] = val;
        return;
    }

    if (isFull())  {
        cout << "Overflow!" << endl;
        return;
    }
  
    arr_[++rear_] = val;
    
}


void dequeue () {
    if (isEmpty()) {
        cout << "Underflow!" << endl;
        return;
    }

    if (front_ == rear_) {
        front_ = rear_ = -1;
        return;
    }

    front_++;
}


int peek() {
 if (isEmpty()) {
    cout << "Queue is Empty!" << endl;
    return -1;
 }   

 return arr_[front_];
}

~Queue() {
    delete[] arr_;
}

};


int main() {

    return 0;
}