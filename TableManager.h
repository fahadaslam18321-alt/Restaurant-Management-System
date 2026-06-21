#ifndef TABLEMANAGER_H
#define TABLEMANAGER_H

#include "Table.h"
#include <stack>
#include <vector>
#include <map>
using namespace std;

class TableManager {
private:
    stack<Table*> availableTables;
    vector<Table*> allTables;
    map<int, Table*> occupiedTables;

public:
    TableManager();
    void initializeTables();
    Table* allocateTable(string customerName, int requiredCapacity);
    void freeTable(int tableNumber);
    void displayAllTables();
    void displayAvailableTables();
    bool hasAvailableTables();
    int getAvailableTableCount();
    Table* getTable(int tableNumber);
    bool isTableOccupied(int tableNumber);
};

#endif