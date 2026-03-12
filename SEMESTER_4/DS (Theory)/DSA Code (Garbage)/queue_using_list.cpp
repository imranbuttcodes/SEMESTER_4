#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data): data(data) {next = nullptr;}
};


class queue {
public:

Node* front;
Node* rear;
queue() {
    front = nullptr;
    rear = nullptr;
}

bool isEmpty() {
    return front == nullptr;
}

void Enqueue(int val) {
    Node* newNode = new Node(val);
    
    if (isEmpty()) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = rear->next;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow!" << endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    temp->next = nullptr;
    delete temp;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << "QUEUE: ";
    while (temp != nullptr) {
        cout << temp->data << " "; 
        temp = temp->next;
    }
    cout << endl;
}

};




int main() {
    queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();
        q.dequeue();
    q.display();
        q.dequeue();
    q.display();
    system("pause");
    return 0;
}