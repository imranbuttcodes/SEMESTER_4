#include <iostream>
using namespace std;

class Node {
public:
int data;
Node* next;
Node(int data): data(data), next(nullptr) {}
};


class List {
private:
Node* head;
public:
List(): head(nullptr) {}

void push_front(int val){
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void display() {
    if (head==nullptr) {
        cout << "Sorry List is empty!"<<endl;
        return;
    }
    Node* temp_head = head;
    while (temp_head!=nullptr) {
        cout << temp_head->data << " ";
        temp_head = temp_head->next;
    }
    cout << endl;
}

void push_back (int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
} 

void pop_front() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    head = head->next;
    temp->next = nullptr;
    delete temp;
}

void pop_back() {
    if (head == nullptr) {
        return;
    }
    Node* temp = head;
    while(temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void Reverse_list() {
    if (head == nullptr) {
        return;
    }
    Node* current = nullptr;
    Node* previous = nullptr;
    while (head->next != nullptr) {
        current = head;
        head = head->next;
        current->next = previous;
        previous = current;
    }
    head->next = previous;
}

};

int main() {
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(5);
    cout << "List Before Reversing: ";
    l.display();
    cout << "List After Reversing: ";
    l.Reverse_list();
    l.display();
    return 0;
}