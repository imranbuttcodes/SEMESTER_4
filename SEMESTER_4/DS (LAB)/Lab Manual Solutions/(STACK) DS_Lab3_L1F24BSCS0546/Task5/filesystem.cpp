#include <iostream>
#include <string>
using namespace std;

class MyStack {
public:
    string* dirs_;
    int maxSize_;
    int top_;

    MyStack(int size) {
        maxSize_ = size;
        dirs_    = new string[maxSize_];
        top_     = -1;
    }

    void push(const string& s) {
        if (isFull()) {
            cout << "Overflow: Stack Is Full!" << endl;
            return;
        }
        dirs_[++top_] = s;
    }

    string peek() {
        if (isEmpty()) return "";
        return dirs_[top_];
    }

    void pop() {
        if (isEmpty()) {
            cout << "Already at root cannot go up further!" << endl;
            return;
        }
        top_--;
    }

    bool isFull()  const { 
        return top_ == maxSize_ - 1;
    }
    bool isEmpty() const {
         return top_ == -1;
    }
    int  size()  const {
         return top_ + 1;
    }


    void pwd() const {
        if (top_ == -1) {
            cout << "/" << endl;
            return;
        }
        string path = "";
        for (int i = 0; i <= top_; i++) {
            path += "/" + dirs_[i];
        }
        cout << path << endl;
    }

    ~MyStack() { delete[] dirs_; }
};


class FileSystem {
    MyStack path_;

    void printPrompt() {
        cout << "\nshell:";
        path_.pwd();
        cout << "$ ";
    }

public:
    FileSystem(int capacity = 50) : path_(capacity) {}

    void cd(const string& target) {
        if (target == "..") {
            if (path_.isEmpty()) {
                cout << "cd: already at root '/'" << endl;
            } else {
                string leaving = path_.peek();
                path_.pop();
                cout << "cd .. (left '" << leaving << "')" << endl;
            }
        } else {
            path_.push(target);
            cout << "cd " << target << " (entered '" << target << "')" << endl;
        }
        printState();
    }

    void pwd() {
        cout << "pwd -> ";
        path_.pwd();
    }

    void printState() {
        cout << "Stack (top->bottom): ";
        if (path_.isEmpty()) {
            cout << "(empty – at root)";
        } else {
            for (int i = path_.top_; i >= 0; i--) {
                cout << "[" << path_.dirs_[i] << "]";
                if (i > 0) cout << " <- ";
            }
        }
        cout << endl;
    }
};

int main() {
    FileSystem fs;

    cout << "========== File System Navigation Demo ==========\n";
    cout << "Starting at root '/'\n";
    fs.printState();

    cout << "\n--- Moving into nested directories ---";
    fs.cd("home");
    fs.cd("imran");
    fs.cd("projects");
    fs.cd("cpp");

    cout << "\n--- Check current path ---\n";
    fs.pwd();

    cout << "\n--- Go back two levels (cd ..) ---";
    fs.cd("..");
    fs.cd("..");

    cout << "\n--- Enter a different branch ---";
    fs.cd("documents");
    fs.cd("uni");
    fs.cd("semester4");

    cout << "\n--- Check current path ---\n";
    fs.pwd();

    cout << "\n--- Navigate all the way back to root ---";
    fs.cd("..");
    fs.cd("..");
    fs.cd("..");
    fs.cd("..");  

    cout << "\n--- Final path ---\n";
    fs.pwd();

    cout << "\n=================================================";
    return 0;
}

