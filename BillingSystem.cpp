#include "BillingSystem.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void BillingSystem::generateBill(Order* order) {
    double subtotal = order->totalAmount;
    double discount = order->discount;
    double tax = (subtotal - discount) * 0.08;
    double total = subtotal - discount + tax;
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                       FINAL BILL                       |" << endl;
    cout << "==========================================================" << endl;
    cout << "| Order ID: " << setw(48) << left << order->orderId << "|" << endl;
    cout << "| Order Type: " << setw(46) << left << order->orderType << "|" << endl;
    if (order->table) {
        cout << "| Table: " << setw(51) << left << order->table->getTableNumber() << "|" << endl;
        cout << "| Customer: " << setw(48) << left << order->table->getCustomerName() << "|" << endl;
    } else {
        cout << "| Customer: " << setw(48) << left << "Takeaway Customer" << "|" << endl;
    }
    cout << "| Payment: " << setw(49) << left << order->paymentMethod << "|" << endl;
    cout << "| Date: " << setw(52) << left << order->getDateString() << "|" << endl;
    cout << "| Time: " << setw(52) << left << order->getTimeString() << "|" << endl;
    cout << "==========================================================" << endl;
    cout << "| Subtotal: $" << setw(46) << right << fixed << setprecision(2) << subtotal << "|" << endl;
    cout << "| Discount: $" << setw(46) << right << discount << "|" << endl;
    cout << "| Tax (8%): $" << setw(46) << right << tax << "|" << endl;
    cout << "==========================================================" << endl;
    cout << "| TOTAL:    $" << setw(46) << right << total << "|" << endl;
    cout << "==========================================================" << endl;
    
    if (order->paymentMethod != "") {
        int rating;
        cout << "\nPlease rate your experience (1-5 stars): ";
        cin >> rating;
        order->setRating(rating);
        cout << "Thank you for your feedback!" << endl;
    }
    
    printReceipt(order);
}

void BillingSystem::printReceipt(Order* order) {ofstream obj("Student.txt",ios::app);
    string filename = "Receipt_Order.txt";
    ofstream file(filename);
    
    if (file.is_open()) {
        file << "==========================================================" << endl;
        file << "|                 RESTAURANT RECEIPT                     |" << endl;
        file << "==========================================================" << endl;
        file << "| Order ID: " << setw(49) << left << order->orderId << "|" << endl;
        file << "| Order Type: " << setw(47) << left << order->orderType << "|" << endl;
        if (order->table) {
            file << "| Table: " << setw(52) << left << order->table->getTableNumber() << "|" << endl;
            file << "| Customer: " << setw(49) << left << order->table->getCustomerName() << "|" << endl;
        }
        file << "| Date: " << setw(53) << left << order->getDateString() << "|" << endl;
        file << "| Time: " << setw(53) << left << order->getTimeString() << "|" << endl;
        file << "| Payment Method: " << setw(44) << left << order->paymentMethod << "|" << endl;
        file << "==========================================================" << endl;
        file << "| Items:                                                |" << endl;
        for (auto item : order->items) {
            file << "|   - " << setw(48) << left << item->getName() 
                 << " $" << fixed << setprecision(2) << item->getPrice() << " |" << endl;
        }
        file << "==========================================================" << endl;
        file << "| Subtotal: $" << setw(47) << right << fixed << setprecision(2) << order->totalAmount << "|" << endl;
        file << "| Discount: $" << setw(47) << right << order->discount << "|" << endl;
        file << "| Tax: $" << setw(50) << right << (order->totalAmount - order->discount) * 0.08 << "|" << endl;
        file << "==========================================================" << endl;
        file << "| TOTAL:    $" << setw(47) << right << order->getTotalAmount() + ((order->totalAmount - order->discount) * 0.08) << "|" << endl;
        file << "==========================================================" << endl;
        file.close();
        cout << "Receipt saved as: " << filename << endl;
    }
}