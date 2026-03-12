// ========== OrderQueue.h ==========
// Header file containing class definition and structures
// This file declares what the class looks like



#include <iostream>
#include <cstring>
using namespace std;

// ========== CONSTANTS ==========
const int MAX_ORDERS = 5;        // Maximum orders kitchen can handle
const int NAME_LENGTH = 50;

// ========== DATA STRUCTURE ==========
// Simplified Room Service Order with single food item
struct RoomServiceOrder {
    int orderId;
    int roomNumber;
    char customerName[NAME_LENGTH];
    char foodItem[50];     // Only ONE food item per order
    int quantity;          // Quantity of that item
    float totalAmount;
    char orderTime[10];    // Format: HH:MM
    bool isReady;          // true if ready for delivery
};

// ========== CIRCULAR QUEUE CLASS ==========
// Class declaration - tells what functions are available
class CircularOrderQueue {
private:
    RoomServiceOrder orders[MAX_ORDERS];
    int front;           // Index for dequeue (remove orders)
    int rear;            // Index for enqueue (add orders)
    int currentSize;     // Current number of orders
    int nextOrderId;     // Auto-increment order ID
    
public:
    // Constructor
    CircularOrderQueue();
    
    // Basic queue operations
    bool isEmpty();
    bool isFull();
    int getSize();
    
    // Main operations
    void enqueue(int roomNo, const char* name, const char* time, 
                 const char* item, int qty, float amount);
    RoomServiceOrder dequeue();
    
    // Helper functions
    void markOrderReady(int orderId);
    void displayQueue();
    void peekFront();
    void displayStatus();
    void searchOrder(int orderId);
};
