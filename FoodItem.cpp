#include "FoodItem.h"
#include <iostream>
using namespace std;

FoodItem::FoodItem(int i, string n, string c, double p, int s, int pt)
    : MenuItem(i, n, c, p, s), preparationTime(pt) {}

void FoodItem::display() {
    cout << "ID: " << id << " | " << name << " | " << category 
         << " | $" << price << " | Stock: " << stock 
         << " | Prep: " << preparationTime << " mins" << endl;
}

string FoodItem::getType() { 
    return "Food"; 
}

string FoodItem::toFileString() {
    return MenuItem::toFileString() + "," + to_string(preparationTime);
}