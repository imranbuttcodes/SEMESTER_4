// =============================================
// SOCIAL MEDIA MESSAGING SYSTEM - ASSIGNMENT 1
// Student Starter Template
// Topics: Stack and Queue using Arrays
// =============================================

#include <iostream>
#include <cstring>
using namespace std;

// ========== CONSTANTS ==========
const int MAX_STACK_SIZE = 100;
const int MAX_QUEUE_SIZE = 50;
const int MAX_STRING_LENGTH = 500;

// ========== DATA STRUCTURES ==========

// Structure for Stack operations (Undo/Redo comments)
struct CommentOperation {
    int postId;
    char commentText[MAX_STRING_LENGTH];
    int actionType;     // 1 = Add comment, 2 = Delete comment
    int timestamp;      // Simulated using counter
    // TODO: Add additional fields as needed
};

// Structure for Queue messages
struct Message {
    int senderId;
    int receiverId;
    char messageText[MAX_STRING_LENGTH];
    int priority;       // 1-5 (5 being highest)
    int status;         // 0 = pending, 1 = sent
    // TODO: Add additional fields as needed
};

// ========== STACK CLASS ==========
class CommentStack {
private:
    CommentOperation stack[MAX_STACK_SIZE];
    int top;            // Index of top element
    int operationCounter; // For timestamp simulation
    
public:
    // Constructor
    CommentStack() {
        // Implement this function
        top = -1;
        operationCounter = 0;
    }
    
    // TODO: Check if stack is empty
    bool isEmpty() {
        // Implement this function
        return top == -1;
    }
    
    // TODO: Check if stack is full
    bool isFull() {
        // Implement this function
        return top == MAX_STACK_SIZE - 1;
        
    }
    
    // TODO: Push a comment operation onto stack
    void pushComment(int postId, const char* commentText, int actionType) {
        
        // Write your code here
        if (isFull()) {
            cout << "Overflow! Comment Stack is full right now!" << endl;
            return;
        }
        if (commentText == nullptr || (actionType < 1 && actionType > 2) ) {
            cout << "Operation Can't be performed as either commentText is empty or action Type is invalid!" << endl;
            return;
        }
        stack[++top].postId = postId;
        strcpy(stack[top].commentText, commentText);
        stack[top].actionType = actionType;
        stack[top].timestamp = ++operationCounter;
        cout << "Comment operation pushed to stack." << endl;
    }
    
    // TODO: Pop a comment operation from stack
    CommentOperation popComment() {
       
        // Write your code here
         
        if (isEmpty()) {
            cout << "Sorry! No Comments remained to pop!" << endl;
            return;
        }
        
        CommentOperation top_comment_operation = stack[top];
        --top;
        return top_comment_operation;
        
    }
    
    // TODO: View last action without removing
    void peekLastAction() {
               
        // Write your code here
        if (isEmpty()) {
            cout << "No Action Performed yet!" << endl;
            return;
        }
        cout << "Last Action: " << (stack[top].actionType == 1 ? "A Comment Added" : "Comment Deleted!" ) << endl;
        cout << (stack[top].actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
        cout << "Post Id: " << stack[top].postId << endl;
        cout << "TimeStamp: " << stack[top].timestamp << endl;
        cout << "Comment: " << stack[top].commentText << endl;

    }
    
    // TODO: Display all operations in stack
    void displayStack() {
               
        cout << "\n===== UNDO STACK CONTENTS =====" << endl;
        // Write your code here to display from top to bottom
        if (isEmpty()) {
            cout <<"Sorry! No comment Operations to display!" << endl;
            return;
        }
        for (int temp_top = top; temp_top >= 0; temp_top--) {
            cout << (stack[temp_top].actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
            cout << "Post Id: " << stack[temp_top].postId << endl;
            cout << "TimeStamp: " << stack[temp_top].timestamp << endl;
            cout << "Comment: " << stack[temp_top].commentText << endl;
        }
    }
    
    // TODO: Search comments containing keyword
    void searchComment(const char* keyword) {
        cout << "Searching for comments containing: " << keyword << endl;
          
        // Write your code here to search through stack
       
        if (isEmpty()) {
            cout <<"Sorry! there are 0 comments right now!" << endl;
            return;
        }
        
        for (int i = 0; i <= top; i++) {
            string matching_keyword = "";
            for (int j = 0; )
        }
        

    }
    
    // TODO: Get stack size
    int getSize() {
       // Write your code here
    }
};

// ========== QUEUE CLASS ==========
class MessageQueue {
private:
    Message queue[MAX_QUEUE_SIZE];
    int front;      // Index of front element
    int rear;       // Index of rear element
    int count;      // Number of elements in queue
    
public:
    // Constructor
    MessageQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }
    
    // TODO: Check if queue is empty
    bool isEmpty() {
        // Implement this function
       
    }
    
    // TODO: Check if queue is full
    bool isFull() {
        // Implement this function
       
    }
    
    // TODO: Add message to queue
    void enqueueMessage(int senderId, int receiverId, 
                        const char* messageText, int priority) {
       
        
        // Write your code here
        
        cout << "Message queued successfully." << endl;
    }
    
    // TODO: Remove and process message from queue
    Message dequeueMessage() {
        
        // Write your code here
        
        return emptyMsg;
    }
    
    // TODO: Display all messages in queue
    void displayQueue() {
        
        cout << "\n===== MESSAGE QUEUE CONTENTS =====" << endl;
        // Write your code here to display all messages
    }
    
    // TODO: Process message with highest priority
    void processHighestPriority() {
        
        cout << "Processing highest priority message..." << endl;
        // Write your code here to find and process highest priority message
    }
    
    // TODO: Search messages by sender
    void searchBySender(int senderId) {
        cout << "Searching for messages from sender: " << senderId << endl;
        
        // Write your code here
        
    }
    
    // TODO: Count messages by priority
    int countMessagesByPriority(int priority) {
        
        
        // Write your code here
        
        
    }
    
    // TODO: View front message without removing
    void peekFront() {
        
        
        // Write your code here
    }
    
    // TODO: View rear message without removing
    void peekRear() {
        
        
        // Write your code here
    }
    
    // TODO: Get queue size
    int getSize() {
        // Write your code here
    }
};

// ========== MAIN MENU SYSTEM ==========
int main() {
    CommentStack undoStack;
    MessageQueue msgQueue;
    
    int choice;
    int postId, senderId, receiverId, actionType, priority;
    char text[MAX_STRING_LENGTH];
    char keyword[MAX_STRING_LENGTH];
    
    do {
        cout << "\n========== SOCIAL MEDIA MESSAGING SYSTEM ==========" << endl;
        cout << "1. Add Comment Operation (Push to Stack)" << endl;
        cout << "2. Undo Last Comment (Pop from Stack)" << endl;
        cout << "3. View Last Action (Stack Peek)" << endl;
        cout << "4. Display Undo Stack" << endl;
        cout << "5. Search Comments in Stack" << endl;
        cout << "6. Send Message (Enqueue)" << endl;
        cout << "7. Process Message (Dequeue)" << endl;
        cout << "8. Display Message Queue" << endl;
        cout << "9. Process Highest Priority Message" << endl;
        cout << "10. Search Messages by Sender" << endl;
        cout << "11. Count Messages by Priority" << endl;
        cout << "12. View Queue Front" << endl;
        cout << "13. View Queue Rear" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter Post ID: ";
                cin >> postId;
                cin.ignore();
                cout << "Enter Comment Text: ";
                cin.getline(text, MAX_STRING_LENGTH);
                cout << "Enter Action Type (1-Add, 2-Delete): ";
                cin >> actionType;
                undoStack.pushComment(postId, text, actionType);
                break;
                
            case 2:
                // TODO: Call popComment and display result
                break;
                
            case 3:
                undoStack.peekLastAction();
                break;
                
            case 4:
                undoStack.displayStack();
                break;
                
            case 5:
                cin.ignore();
                cout << "Enter keyword to search: ";
                cin.getline(keyword, MAX_STRING_LENGTH);
                undoStack.searchComment(keyword);
                break;
                
            case 6:
                cout << "Enter Sender ID: ";
                cin >> senderId;
                cout << "Enter Receiver ID: ";
                cin >> receiverId;
                cin.ignore();
                cout << "Enter Message Text: ";
                cin.getline(text, MAX_STRING_LENGTH);
                cout << "Enter Priority (1-5): ";
                cin >> priority;
                msgQueue.enqueueMessage(senderId, receiverId, text, priority);
                break;
                
            case 7:
                // TODO: Call dequeueMessage and display result
                break;
                
            case 8:
                msgQueue.displayQueue();
                break;
                
            case 9:
                msgQueue.processHighestPriority();
                break;
                
            case 10:
                cout << "Enter Sender ID to search: ";
                cin >> senderId;
                msgQueue.searchBySender(senderId);
                break;
                
            case 11:
                cout << "Enter priority to count: ";
                cin >> priority;
                cout << "Messages with priority " << priority << ": " 
                     << msgQueue.countMessagesByPriority(priority) << endl;
                break;
                
            case 12:
                msgQueue.peekFront();
                break;
                
            case 13:
                msgQueue.peekRear();
                break;
                
            case 0:
                cout << "Exiting system. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 0);
    
    return 0;
}