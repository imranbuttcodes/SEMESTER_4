// ========== main.cpp ==========
// Main program that uses the CircularOrderQueue class
// This file contains the user interface

#include "CircularOrderQueue.h"

// ========== MAIN FUNCTION ==========
int main() {
    CircularOrderQueue kitchen;
    int choice;
    int roomNo, orderId, qty;
    char name[NAME_LENGTH];
    char time[10];
    char item[50];
    float amount;


    cout << "  HOTEL ROOM SERVICE SYSTEM\n";

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. ENQUEUE - New Order\n";
        cout << "2. DEQUEUE - Process Order\n";
        cout << "3. Mark Order Ready\n";
        cout << "4. Display All Orders\n";
        cout << "5. PEEK - View Next Order\n";
        cout << "6. Queue Status\n";
        cout << "7. Search Order\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: // ENQUEUE
                cout << "\n--- New Order ---\n";
                cout << "Room number: ";
                cin >> roomNo;
                cin.ignore();
                cout << "Customer name: ";
                cin.getline(name, NAME_LENGTH);
                cout << "Food item: ";
                cin.getline(item, 50);
                cout << "Quantity: ";
                cin >> qty;
                cout << "Total amount: $";
                cin >> amount;
                cout << "Order time (HH:MM): ";
                cin >> time;

                kitchen.enqueue(roomNo, name, time, item, qty, amount);
                break;

            case 2: // DEQUEUE
                kitchen.dequeue();
                break;

            case 3: // Mark Ready
                cout << "\nEnter Order ID: ";
                cin >> orderId;
                kitchen.markOrderReady(orderId);
                break;

            case 4: // Display
                kitchen.displayQueue();
                break;

            case 5: // Peek
                kitchen.peekFront();
                break;

            case 6: // Status
                kitchen.displayStatus();
                break;

            case 7: // Search
                cout << "\nEnter Order ID: ";
                cin >> orderId;
                kitchen.searchOrder(orderId);
                break;

            case 0:
                cout << "\n Thank you for using the system!\n";
                break;

            default:
                cout << "\n Invalid choice!\n";
        }
    } while(choice != 0);

    return 0;
}
