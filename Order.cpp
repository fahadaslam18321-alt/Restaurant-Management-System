#include "Order.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

Order::Order(int id, Table* t, string type) 
    : orderId(id), table(t), status("Pending"), orderType(type), 
      paymentMethod(""), orderTime(time(0)), totalAmount(0.0), 
      discount(0.0), rating(0) {}

void Order::addItem(MenuItem* item, int quantity) {
    for (int i = 0; i < quantity; i++) {
        items.push_back(item);
        totalAmount += item->getPrice();
    }
}

void Order::display() {
    cout << "Order ID: " << orderId << " | Table: " << (table ? to_string(table->getTableNumber()) : "Takeaway") 
         << " | Type: " << orderType
         << " | Customer: " << (table ? table->getCustomerName() : "Takeaway")
         << " | Status: " << status << " | Total: $" << totalAmount << endl;
    
    cout << "Items: ";
    for (auto item : items) {
        cout << item->getName() << " ($" << item->getPrice() << "), ";
    }
    cout << endl;
}

double Order::getTotalAmount() { 
    double finalAmount = totalAmount - discount;
    return (finalAmount > 0) ? finalAmount : 0;
}

void Order::setStatus(string s) { 
    status = s; 
}

void Order::setPaymentMethod(string method) { 
    paymentMethod = method;
    if (method == "Card") {
        applyCardDiscount();
    }
}

void Order::applyCardDiscount() {
    discount = totalAmount * 0.10;
    cout << "10% discount applied for card payment! Discount: $" << discount << endl;
}

void Order::setRating(int r) {
    if (r >= 1 && r <= 5) {
        rating = r;
    }
}

string Order::getDateString() {
    tm* localTime = localtime(&orderTime);
    stringstream ss;
    ss << (localTime->tm_year + 1900) << "-" 
       << (localTime->tm_mon + 1) << "-" 
       << localTime->tm_mday;
    return ss.str();
}

string Order::getTimeString() {
    tm* localTime = localtime(&orderTime);
    stringstream ss;
    ss << setw(2) << setfill('0') << localTime->tm_hour << ":"
       << setw(2) << setfill('0') << localTime->tm_min << ":"
       << setw(2) << setfill('0') << localTime->tm_sec;
    return ss.str();
}