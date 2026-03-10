#include <iostream>
#include <string>
using namespace std;

class MyStack {
public:
    string* calls_;
    int Max_size_;
    int top_;

    MyStack(int size) {
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
            cout << "  (empty)" << endl;
            return;
        }
        for (int i = top_; i >= 0; i--) {
            cout << "  [" << calls_[i] << "]" << endl;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Underflow: Stack Is Empty!" << endl;
            return;
        }
        top_--;
    }

    bool isFull()  { return top_ == Max_size_ - 1; }
    bool isEmpty() { return top_ == -1; }

    ~MyStack() { delete[] calls_; }
};

class TextEditor {
    string  text;
    MyStack undoStack;
    MyStack redoStack;

    void printState(const string& op) {
        cout << "\n>>> " << op << endl;
        cout << "Text   : \"" << text << "\"" << endl;
        cout << "Undo   (top->bottom):" << endl;
        undoStack.display();
        cout << "Redo   (top->bottom):" << endl;
        redoStack.display();
    }

public:
    TextEditor(int capacity = 20)
        : undoStack(capacity), redoStack(capacity) {}

    void type(char x) {
        text += x;
        undoStack.push(string(1, x));  

        while (!redoStack.isEmpty()) redoStack.pop();
        printState(string("type('") + x + "')");
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "\n>>> undo()  -- nothing to undo!" << endl;
            return;
        }
        string action = undoStack.peek();
        undoStack.pop();
        if (!text.empty()) {
            text.pop_back();
        }
        redoStack.push(action);
        printState("undo()");
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "\n>>> redo()  -- nothing to redo!" << endl;
            return;
        }
        string action = redoStack.peek();
        redoStack.pop();
        text += action;                 
        undoStack.push(action);
        printState("redo()");
    }

    string getText() const { return text; }
};


int main() {
    TextEditor editor;
    cout << "========== Undo/Redo Demo ==========\n";
    editor.type('H');   
    editor.type('i');   
    editor.type('!');   
    editor.undo();
    editor.undo();      
    editor.redo();      
    editor.type('.');
    editor.undo();
    editor.redo();

    cout << "\n====================================";
    cout << "\nFinal text: \"" << editor.getText() << "\"" << endl;

    return 0;
}




// why two stacks are an efficient/practical method

// 1. O(1) operations – push/pop are constant time; no
//    shifting of elements needed.

// 2. Natural LIFO order – the most recent action is always
//    on top, matching the expected undo/redo behaviour.

// 3. Clear separation of concerns – Undo holds "what can
//    be undone"; Redo holds "what can be redone". A new
//    type() simply clears Redo, keeping history consistent.

// 4. Memory efficient and only the actions actually performed
//    are stored; nothing extra is allocated.

// 5. Simple to reason about – the two-stack model maps
//    directly onto the mental model users have of undo/redo,
//    making the code easy to maintain and extend.

