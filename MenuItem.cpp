#include "MenuItem.h"

MenuItem::MenuItem(int i, string n, string c, double p, int s) 
    : id(i), name(n), category(c), price(p), stock(s) {}

void MenuItem::display() {
    cout << "ID: " << id << " | " << name << " | " << category 
         << " | $" << price << " | Stock: " << stock << endl;
}

double MenuItem::getPrice() { 
    return price; 
}

string MenuItem::getType() { 
    return "General"; 
}

int MenuItem::getId() { 
    return id; 
}

string MenuItem::getName() { 
    return name; 
}

string MenuItem::getCategory() { 
    return category; 
}

int MenuItem::getStock() { 
    return stock; 
}

void MenuItem::reduceStock(int quantity) { 
    stock -= quantity; 
}

void MenuItem::addStock(int quantity) { 
    stock += quantity; 
}

string MenuItem::toFileString() {
    return to_string(id) + "," + name + "," + category + "," + 
           to_string(price) + "," + to_string(stock);
}