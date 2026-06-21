#include "Deal.h"
#include <iostream>
using namespace std;

Deal::Deal(int id, string n, string desc, double op, double dp)
    : dealId(id), name(n), description(desc), originalPrice(op), 
      dealPrice(dp), isAvailable(true) {}

void Deal::addItem(MenuItem* item) {
    items.push_back(item);
}

void Deal::display() {
    cout << "DEAL: " << name << endl;
    cout << "Description: " << description << endl;
    cout << "Items included: ";
    for (auto item : items) {
        cout << item->getName() << ", ";
    }
    cout << "\nOriginal Price: $" << originalPrice << endl;
    cout << "Deal Price: $" << dealPrice << " (Save $" << (originalPrice - dealPrice) << ")" << endl;
    cout << "Status: " << (isAvailable ? "Available" : "Not Available") << endl;
}

double Deal::getDealPrice() { 
    return dealPrice; 
}

string Deal::getName() { 
    return name; 
}

bool Deal::getAvailability() { 
    return isAvailable; 
}

void Deal::toggleAvailability() { 
    isAvailable = !isAvailable; 
}