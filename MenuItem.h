#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    int id;
    string name;
    string category;
    double price;
    int stock;
    
public:
    MenuItem(int i = 0, string n = "", string c = "", double p = 0.0, int s = 0);
    virtual void display();
    virtual double getPrice();
    virtual string getType();
    
    // Getters
    int getId();
    string getName();
    string getCategory();
    int getStock();
    void reduceStock(int quantity);
    void addStock(int quantity);
    
    // File handling
    virtual string toFileString();
};

#endif