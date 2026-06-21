#ifndef DEAL_H
#define DEAL_H

#include "MenuItem.h"
#include <vector>
using namespace std;

class Deal {
private:
    int dealId;
    string name;
    string description;
    vector<MenuItem*> items;
    double originalPrice;
    double dealPrice;
    bool isAvailable;
    
public:
    Deal(int id, string n, string desc, double op, double dp);
    void addItem(MenuItem* item);
    void display();
    double getDealPrice();
    string getName();
    bool getAvailability();
    void toggleAvailability();
};

#endif