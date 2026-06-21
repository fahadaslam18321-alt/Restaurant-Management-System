#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(int num, int cap) : tableNumber(num), capacity(cap), isOccupied(false), customerName("") {}

int Table::getTableNumber() { 
    return tableNumber; 
}

int Table::getCapacity() { 
    return capacity; 
}

bool Table::getIsOccupied() { 
    return isOccupied; 
}

string Table::getCustomerName() { 
    return customerName; 
}

void Table::occupyTable(string name) {
    isOccupied = true;
    customerName = name;
}

void Table::freeTable() {
    isOccupied = false;
    customerName = "";
}

void Table::display() {
    cout << "Table " << tableNumber << " | Capacity: " << capacity 
         << " | Status: " << (isOccupied ? "Occupied by " + customerName : "Available") << endl;
}