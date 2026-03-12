#include <iostream>
using namespace std;


class CircularQueue {
public:
    int capacity;
    int current_Size;
    int front, rear;
    int* queue;
    CircularQueue(int capacity): capacity(capacity) {
        front = rear = -1;
        queue = new int[capacity];
        current_Size = 0;
    }
    bool isFull() {
        return current_Size == capacity;
    }

    bool isEmpty() {
        return current_Size == 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Overflow!" << endl;
            return;
        }
        
        if (isEmpty()) {
            front = rear = 0;
            queue[rear] = val;
            current_Size++;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = val;
        current_Size++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow!" << endl;
            return;
        }

        if (current_Size == 1) {
            front = rear = -1;
            current_Size = 0;
            return;
        }


        front = (front + 1) % capacity;
        --current_Size;
    
    }

    int peek () {
        if (isEmpty()) {
            return -1;
        }
        return queue[front];

    }
 
void display() {
   if (isEmpty()) {
       cout << "Queue Is Empty!" << endl;
       return;   
    }
    int i = front;
    cout << "Queue: ";
    for (int count = 0; count < current_Size; count++) {
        cout << queue[i] << ' ';
        i = (i + 1) % capacity;
    }


}

~CircularQueue() {
    delete[] queue;
}

};



int main() {
    CircularQueue cq(5);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.pop();
    cq.pop();
    cq.pop(); 
    cq.pop();
    cq.push(1);
    cq.display();
    return 0;
}