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
        if (commentText == nullptr || (actionType < 1 || actionType > 2) ) {
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
            return CommentOperation();
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
        cout << "--------------------- Last Peek Action ---------------------\n";
        cout << "Last Action: " << (stack[top].actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
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
            cout << "Action Type: " << (stack[temp_top].actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
            cout << "Post Id: " << stack[temp_top].postId << endl;
            cout << "TimeStamp: " << stack[temp_top].timestamp << endl;
            cout << "Comment: " << stack[temp_top].commentText << endl << endl;
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
        
        bool foundAny = false;
        for (int i = 0; i <= top; i++) {
            bool found = false;
            for (int j = 0; j < strlen(stack[i].commentText); j++) {
                if (keyword[0] == stack[i].commentText[j]) {
                    int k = j;
                    found = true;
                    for (int l = 0; (l < strlen(keyword) && k < strlen(stack[i].commentText)); l++, k++) {
                        if (keyword[l] != stack[i].commentText[k]) {
                            found = false;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                    
                }
            }
            if (found) {
            foundAny = true;
            cout << "Comment Found Containing Keyword: " << keyword << endl;
            cout << "Comment Details" << endl;
            cout << "Action Type: " << (stack[i].actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
            cout << "Post Id: " << stack[i].postId << endl;
            cout << "TimeStamp: " << stack[i].timestamp << endl;
            cout << "Comment: " << stack[i].commentText << endl;
            }
        }
        if (!foundAny) {
            cout << "No Commnets Found COntaining the keyword: " << keyword << "!" << endl;
        }
        

    }
    
    // TODO: Get stack size
    int getSize() {
       return top + 1;
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
        return count == 0;
    }
    
    // TODO: Check if queue is full
    bool isFull() {
        // Implement this function
       return count == MAX_QUEUE_SIZE;
    }
    
    // TODO: Add message to queue
    void enqueueMessage(int senderId, int receiverId, 
                        const char* messageText, int priority) {
       
         
        // Write your code here

        if (isFull()) {
            cout << "Queue Already full! Please Wait..." << endl;
            return;
        }
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear].priority = priority;
        queue[rear].senderId = senderId;
        queue[rear].receiverId = receiverId;
        queue[rear].status = 0;
        strcpy(queue[rear].messageText, messageText);
        ++count;

        cout << "Message queued successfully." << endl;
    }
    
    // TODO: Remove and process message from queue
    Message dequeueMessage() {
        
        // Write your code here
        Message emptyMsg;
        if (isEmpty()) {
            cout << "Sorry There Are No Messages to remove!" << endl;
            return emptyMsg;
        }

        Message front_msg = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        --count;
        return front_msg;
    }
    
    // TODO: Display all messages in queue
    void displayQueue() {
        
        cout << "\n===== MESSAGE QUEUE CONTENTS =====" << endl;
        // Write your code here to display all messages
        if (isEmpty()) {
            cout << "No Messages to display!" << endl;
            return;
        }
        int temp_front = front;
        for (int current_count = 0; current_count < count; current_count++) {
            cout << "Sender ID: " << queue[temp_front].senderId << endl;
            cout << "Receiver ID: " << queue[temp_front].receiverId << endl;
            cout << "Priority: " << queue[temp_front].priority << endl;
            cout << "Status: " << (queue[temp_front].status == 0 ? "Pending": "Sent" ) << endl;
            cout << "Message: " << queue[temp_front].messageText << endl<<endl;;
            temp_front = (temp_front + 1) % MAX_QUEUE_SIZE;
        }
    }
    
    // TODO: Process message with highest priority
    void processHighestPriority() {
        
        cout << "Processing highest priority message..." << endl;
        // Write your code here to find and process highest priority message
        if (isEmpty()) {
            cout << "Sorry! There are Zero messages available!" << endl;
            return;
        }

        int max_priority = queue[front].priority;
        int max_prority_idx = front;
        int temp_front = front;
        for (int current_count = 0; current_count < count; current_count++)
        {
            if (queue[temp_front].priority > max_priority) {
                max_priority = queue[temp_front].priority;
                max_prority_idx = temp_front;
            }
            temp_front = (temp_front + 1) % MAX_QUEUE_SIZE;
        }

        cout << "--------------------- Message With the highest priority ---------------------" << endl;
        cout << "Sender ID: " << queue[max_prority_idx].senderId << endl;
        cout << "Receiver ID: " << queue[max_prority_idx].receiverId << endl;
        cout << "Priority: " << queue[max_prority_idx].priority << endl;
        cout << "Status: " << (queue[max_prority_idx].status == 0 ? "Pending": "Sent" ) << endl;
        cout << "Message: " << queue[max_prority_idx].messageText << endl;
        
    }
    
    // TODO: Search messages by sender
    void searchBySender(int senderId) {
        cout << "Searching for messages from sender: " << senderId << endl;
        
        // Write your code here  
        if (isEmpty()) {
            cout << "Sorry! There are Zero messages available!" << endl;
            return;
        }

        bool found = false;
        int temp_front = front;
        cout << "------------------ Search Results --------------------" << endl;
        for (int current_count = 0; current_count < count; current_count++) {
            if (queue[temp_front].senderId == senderId) {
                found = true;
                cout << "Sender ID: " << queue[temp_front].senderId << endl;
                cout << "Receiver ID: " << queue[temp_front].receiverId << endl;
                cout << "Priority: " << queue[temp_front].priority << endl;
                cout << "Status: " << (queue[temp_front].status == 0 ? "Pending": "Sent" ) << endl;
                cout << "Message: " << queue[temp_front].messageText << endl << endl;
            }
            temp_front = (temp_front + 1) % MAX_QUEUE_SIZE;
        }
        if (!found) {
            cout << "Sender with this id " << senderId << " not found!" << endl;
        }
    }
    
    // TODO: Count messages by priority
    int countMessagesByPriority(int priority) {
        
        
        // Write your code here
        if (isEmpty()) {
            cout << "Zero Messages Available!" << endl;
            return -1;
        }

        int t_count = 0;
        int temp_front = front;
        for (int i = 0; i < count; i++) {
            if (queue[temp_front].priority == priority) {
                t_count++;
            }
            temp_front = (temp_front + 1) % MAX_QUEUE_SIZE;

        }
        return t_count;

        
    }
    
    // TODO: View front message without removing
    void peekFront() {
        
        // Write your code here

            if (isEmpty()) {
            cout << "Zero Messages Avaialable!" << endl;
            return;
        }
    
        cout << "----------------- Peek Front Message Details -------------------\n";
        cout << "Sender ID: " << queue[front].senderId << endl;
        cout << "Receiver ID: " << queue[front].receiverId << endl;
        cout << "Priority: " << queue[front].priority << endl;
        cout << "Status: " << (queue[front].status == 0 ? "Pending": "Sent" ) << endl;
        cout << "Message: " << queue[front].messageText << endl << endl;

    }
    
    // TODO: View rear message without removing
    void peekRear() {
        
        
        // Write your code here

            if (isEmpty()) {
            cout << "Zero Messages Avaialable!" << endl;
            return;
        }
    
        cout << "----------------- Peek Rear Message Details -------------------\n";
        cout << "Sender ID: " << queue[rear].senderId << endl;
        cout << "Receiver ID: " << queue[rear].receiverId << endl;
        cout << "Priority: " << queue[rear].priority << endl;
        cout << "Status: " << (queue[rear].status == 0 ? "Pending": "Sent" ) << endl;
        cout << "Message: " << queue[rear].messageText << endl << endl;


    }
    
    // TODO: Get queue size
    int getSize() {
        // Write your code here
        return count;
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
            case 1: {
                cout << "Enter Post ID: ";
                cin >> postId;
                cin.ignore();
                cout << "Enter Comment Text: ";
                cin.getline(text, MAX_STRING_LENGTH);
                cout << "Enter Action Type (1-Add, 2-Delete): ";
                cin >> actionType;
                undoStack.pushComment(postId, text, actionType);
            
                break;
            }    
            case 2:
             {   // TODO: Call popComment and display result
                if (!undoStack.isEmpty()) {
                CommentOperation l_comment = undoStack.popComment();
                cout << "--------------------- Poped Comment Details ---------------------\n";
                cout << "Action Type: " << (l_comment.actionType == 1 ? "Added Comment" : "Deleted Comment!" ) << endl;
                cout << "Post Id: " << l_comment.postId << endl;
                cout << "TimeStamp: " << l_comment.timestamp << endl;
                cout << "Comment: " << l_comment.commentText << endl;
                } else  {
                    cout << "Sorry There are no comments to undo!" << endl;
                }
                break;
             }  
            case 3:
              {  undoStack.peekLastAction();
                break;
              } 
            case 4:
               { undoStack.displayStack();
                break;
               }
            case 5:
                {
                cin.ignore();
                cout << "Enter keyword to search: ";
                cin.getline(keyword, MAX_STRING_LENGTH);
                undoStack.searchComment(keyword);
                break;
                }
            case 6:
                {
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
                }
            case 7:
                {// TODO: Call dequeueMessage and display result
                if (!msgQueue.isEmpty()) {
                Message msg = msgQueue.dequeueMessage();
                cout << "--------------------- Message Details ---------------------\n";
                cout << "Sender ID: " << msg.senderId << endl;
                cout << "Receiver ID: " << msg.receiverId << endl;
                cout << "Priority: " << msg.priority << endl;
                cout << "Status: " << (msg.status == 0 ? "Pending": "Sent" ) << endl;
                cout << "Message: " << msg.messageText << endl;
                } else {
                    cout << "No Messages to process!" << endl;
                }
                break;
                }
            case 8:
                {
                msgQueue.displayQueue();
                break;
                }
            case 9:
                {
                msgQueue.processHighestPriority();
                break;
                }
            case 10:
                {
                cout << "Enter Sender ID to search: ";
                cin >> senderId;
                msgQueue.searchBySender(senderId);
                break;
                }
            case 11:
                {
                cout << "Enter priority to count: ";
                cin >> priority;
                cout << "Messages with priority " << priority << ": " 
                     << msgQueue.countMessagesByPriority(priority) << endl;
                break;
                }
            case 12:
                {
                msgQueue.peekFront();
                break;
                }
            case 13:
                {
                msgQueue.peekRear();
                break;
                }
            case 0:
                {
                cout << "Exiting system. Goodbye!" << endl;
                break;
                }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while(choice != 0);
    
    return 0;
}