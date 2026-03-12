// ========== OrderQueue.cpp ==========
// Implementation file - contains actual code for all functions
// This file makes the class work

#include "CircularOrderQueue.h"

// ========== CONSTRUCTOR ==========
// Initializes the queue to empty state
CircularOrderQueue::CircularOrderQueue() {
    front = 0;
    rear = -1;
    currentSize = 0;
    nextOrderId = 1001;
}

// ========== BASIC QUEUE OPERATIONS ==========

// Check if queue is empty
bool CircularOrderQueue::isEmpty() {
    return currentSize == 0;
}

// Check if queue is full
bool CircularOrderQueue::isFull() {
    return currentSize == MAX_ORDERS;
}

// Get current queue size
int CircularOrderQueue::getSize() {
    return currentSize;
}

// ========== ENQUEUE - Add new order to queue ==========
void CircularOrderQueue::enqueue(int roomNo, const char* name, const char* time,
                                  const char* item, int qty, float amount) {

    // Check if queue is full
    if (isFull()) {
        cout << "\n KITCHEN IS FULL! Cannot accept more orders.\n";
        cout << "   Please wait for some orders to be delivered.\n";
        return;
    }

    // Move rear in circular manner
    rear = (rear + 1) % MAX_ORDERS;

    // Set order details
    orders[rear].orderId = nextOrderId++;
    orders[rear].roomNumber = roomNo;
    strcpy(orders[rear].customerName, name);
    strcpy(orders[rear].orderTime, time);
    strcpy(orders[rear].foodItem, item);
    orders[rear].quantity = qty;
    orders[rear].totalAmount = amount;
    orders[rear].isReady = false;

    // Increase size
    currentSize++;

    cout << "\n Order #" << orders[rear].orderId << " placed successfully!\n";
    cout << "   Position in queue: " << currentSize << "\n";
}

// ========== DEQUEUE - Process and remove next order ==========
RoomServiceOrder CircularOrderQueue::dequeue() {
    // Create empty order for return if queue is empty
    RoomServiceOrder emptyOrder;
    emptyOrder.orderId = -1;
    strcpy(emptyOrder.customerName, "None");
    strcpy(emptyOrder.foodItem, "None");

    // Check if queue is empty
    if (isEmpty()) {
        cout << "\n No orders to process! Kitchen is idle.\n";
        return emptyOrder;
    }

    // Get the front order
    RoomServiceOrder processedOrder = orders[front];

    // Display processing message
    cout << "\n🔪 PROCESSING ORDER #" << processedOrder.orderId << "\n";
    cout << "   Customer: " << processedOrder.customerName;
    cout << " (Room " << processedOrder.roomNumber << ")\n";
    cout << "   Item: " << processedOrder.foodItem;
    cout << " x" << processedOrder.quantity << "\n";
    cout << "   Total: Rs" << processedOrder.totalAmount << "\n";

    // Move front in circular manner (remove from queue)
    front = (front + 1) % MAX_ORDERS;
    currentSize--;

    cout << "    Order completed and removed from queue!\n";

    return processedOrder;
}

// ========== MARK ORDER AS READY ==========
void CircularOrderQueue::markOrderReady(int orderId) {
    int temp = front;
    for (int i = 0; i < currentSize; i++) {
        if (orders[temp].orderId == orderId) {
            orders[temp].isReady = true;
            cout << "\n Order #" << orderId << " is READY for delivery!\n";
            return;
        }
        temp = (temp + 1) % MAX_ORDERS;
    }
    cout << "\n Order not found!\n";
}

// ========== DISPLAY ALL ORDERS IN QUEUE ==========
void CircularOrderQueue::displayQueue() {
    if (isEmpty()) {
        cout << "\n📭 No orders in the queue.\n";
        return;
    }

    cout << "\n========== CURRENT ORDERS ==========\n";
    cout << "Total orders: " << currentSize << "\n\n";

    int index = front;
    for (int i = 0; i < currentSize; i++) {
        cout << "Order #" << orders[index].orderId << "\n";
        cout << "   Room: " << orders[index].roomNumber;
        cout << " | Customer: " << orders[index].customerName << "\n";
        cout << "   Item: " << orders[index].foodItem;
        cout << " x" << orders[index].quantity;
        cout << " | Total: Rs" << orders[index].totalAmount << "\n";
        cout << "   Status: " << (orders[index].isReady ? " READY" : " PREPARING");

        if (index == front) {
            cout << " [NEXT TO PROCESS]";
        }
        cout << "\n\n";

        index = (index + 1) % MAX_ORDERS;
    }
    cout << "====================================\n";
}

// ========== PEEK AT FRONT ORDER ==========
void CircularOrderQueue::peekFront() {
    if (isEmpty()) {
        cout << "\nNo orders in queue.\n";
        return;
    }

    cout << "\n NEXT ORDER:\n";
    cout << "   Order #" << orders[front].orderId << "\n";
    cout << "   Room " << orders[front].roomNumber;
    cout << " - " << orders[front].customerName << "\n";
    cout << "   " << orders[front].foodItem;
    cout << " x" << orders[front].quantity << "\n";
}

// ========== DISPLAY QUEUE STATUS ==========
void CircularOrderQueue::displayStatus() {
    cout << "\n QUEUE STATUS:\n";
    cout << "   Capacity: " << MAX_ORDERS << " orders\n";
    cout << "   Current: " << currentSize << " orders\n";
    cout << "   Available: " << (MAX_ORDERS - currentSize) << " slots\n";
    cout << "   Front index: " << front << "\n";
    cout << "   Rear index: " << rear << "\n";

    if (isFull()) {
        cout << "   Status:  FULL - Kitchen busy\n";
    } else if (isEmpty()) {
        cout << "   Status:  EMPTY - Kitchen idle\n";
    } else {
        cout << "   Status:  ACTIVE - Processing orders\n";
    }
}

// ========== SEARCH ORDER BY ID ==========
void CircularOrderQueue::searchOrder(int orderId) {
    int index = front;
    for (int i = 0; i < currentSize; i++) {
        if (orders[index].orderId == orderId) {
            cout << "\n ORDER FOUND:\n";
            cout << "   Order #" << orders[index].orderId << "\n";
            cout << "   Room: " << orders[index].roomNumber << "\n";
            cout << "   Customer: " << orders[index].customerName << "\n";
            cout << "   Item: " << orders[index].foodItem << "\n";
            cout << "   Quantity: " << orders[index].quantity << "\n";
            cout << "   Total: Rs" << orders[index].totalAmount << "\n";
            cout << "   Time: " << orders[index].orderTime << "\n";
            cout << "   Status: " << (orders[index].isReady ? "Ready" : "Preparing") << "\n";
            return;
        }
        index = (index + 1) % MAX_ORDERS;
    }
    cout << "\n Order #" << orderId << " not found!\n";
}
