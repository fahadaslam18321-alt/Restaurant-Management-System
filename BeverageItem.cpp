#include "BeverageItem.h"
#include <iostream>
using namespace std;

BeverageItem::BeverageItem(int i, string n, string c, double p, int s, bool alcohol)
    : MenuItem(i, n, c, p, s), isAlcoholic(alcohol) {}

void BeverageItem::display() {
    cout << "ID: " << id << " | " << name << " | " << category 
         << " | $" << price << " | Stock: " << stock 
         << " | Type: " << (isAlcoholic ? "Alcoholic" : "Non-Alcoholic") << endl;
}

string BeverageItem::getType() { 
    return "Beverage"; 
}

string BeverageItem::toFileString() {
    return MenuItem::toFileString() + "," + (isAlcoholic ? "true" : "false");
}