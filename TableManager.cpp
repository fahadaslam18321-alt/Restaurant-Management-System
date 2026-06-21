#include "TableManager.h"
#include <iostream>
using namespace std;

TableManager::TableManager() {
    initializeTables();
}

void TableManager::initializeTables() {
    for (int i = 10; i >= 1; i--) {
        int capacity = (i % 2 == 0) ? 4 : 2;
        Table* table = new Table(i, capacity);
        availableTables.push(table);
        allTables.push_back(table);
    }
}

Table* TableManager::allocateTable(string customerName, int requiredCapacity) {
    if (availableTables.empty()) {
        cout << "RESTAURANT IS FULL! No tables available." << endl;
        return nullptr;
    }
    
    stack<Table*> tempStack;
    Table* suitableTable = nullptr;
    
    while (!availableTables.empty()) {
        Table* current = availableTables.top();
        availableTables.pop();
        
        if (current->getCapacity() >= requiredCapacity) {
            suitableTable = current;
            break;
        } else {
            tempStack.push(current);
        }
    }
    
    while (!tempStack.empty()) {
        availableTables.push(tempStack.top());
        tempStack.pop();
    }
    
    if (suitableTable != nullptr) {
        suitableTable->occupyTable(customerName);
        occupiedTables[suitableTable->getTableNumber()] = suitableTable;
        cout << "Table " << suitableTable->getTableNumber() << " allocated to " << customerName << endl;
        return suitableTable;
    } else {
        cout << "No table available with capacity " << requiredCapacity << " or more." << endl;
        return nullptr;
    }
}

void TableManager::freeTable(int tableNumber) {
    if (occupiedTables.find(tableNumber) != occupiedTables.end()) {
        Table* table = occupiedTables[tableNumber];
        table->freeTable();
        availableTables.push(table);
        occupiedTables.erase(tableNumber);
        cout << "Table " << tableNumber << " is now available" << endl;
    } else {
        cout << "Table " << tableNumber << " is not occupied!" << endl;
    }
}

void TableManager::displayAllTables() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                    TABLE STATUS                        |" << endl;
    cout << "==========================================================" << endl;
    for (auto table : allTables) {
        cout << "| ";
        table->display();
    }
    cout << "| Available Tables: " << availableTables.size() << "/" << allTables.size() << "                           |" << endl;
    cout << "==========================================================" << endl;
}

void TableManager::displayAvailableTables() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                  AVAILABLE TABLES                      |" << endl;
    cout << "==========================================================" << endl;
    stack<Table*> temp = availableTables;
    
    if (temp.empty()) {
        cout << "|                ALL TABLES OCCUPIED                   |" << endl;
    } else {
        while (!temp.empty()) {
            cout << "| ";
            temp.top()->display();
            temp.pop();
        }
    }
    cout << "==========================================================" << endl;
}

bool TableManager::hasAvailableTables() {
    return !availableTables.empty();
}

int TableManager::getAvailableTableCount() {
    return availableTables.size();
}

Table* TableManager::getTable(int tableNumber) {
    for (auto table : allTables) {
        if (table->getTableNumber() == tableNumber) {
            return table;
        }
    }
    return nullptr;
}

bool TableManager::isTableOccupied(int tableNumber) {
    Table* table = getTable(tableNumber);
    return table != nullptr && table->getIsOccupied();
}