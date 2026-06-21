#ifndef TABLE_H
#define TABLE_H

#include <string>
using namespace std;

class Table {
private:
    int tableNumber;
    int capacity;
    bool isOccupied;
    string customerName;

public:
    Table(int num, int cap);
    
    int getTableNumber();
    int getCapacity();
    bool getIsOccupied();
    string getCustomerName();
    
    void occupyTable(string name);
    void freeTable();
    void display();
};

#endif