#ifndef FOODITEM_H
#define FOODITEM_H

#include "MenuItem.h"

class FoodItem : public MenuItem {
private:
    int preparationTime;
    
public:
    FoodItem(int i = 0, string n = "", string c = "", double p = 0.0, int s = 0, int pt = 0);
    void display() override;
    string getType() override;
    string toFileString() override;
};

#endif