#ifndef BEVERAGEITEM_H
#define BEVERAGEITEM_H

#include "MenuItem.h"

class BeverageItem : public MenuItem {
private:
    bool isAlcoholic;
    
public:
    BeverageItem(int i = 0, string n = "", string c = "", double p = 0.0, int s = 0, bool alcohol = false);
    void display() override;
    string getType() override;
    string toFileString() override;
};

#endif