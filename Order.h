#ifndef ORDER_H
#define ORDER_H

#include "MenuItem.h"
#include "Table.h"
#include <vector>
#include <ctime>
using namespace std;

class Order {
public:
    int orderId;
    Table* table;
    vector<MenuItem*> items;
    string status;
    string orderType;  // "Dine-in", "Takeaway", "Deal"
    string paymentMethod; // "Cash", "Card"
    time_t orderTime;
    double totalAmount;
    double discount;
    int rating; // 1-5 stars
    
    Order(int id, Table* t, string type = "Dine-in");
    void addItem(MenuItem* item, int quantity = 1);
    void display();
    double getTotalAmount();
    void setStatus(string s);
    void setPaymentMethod(string method);
    void applyCardDiscount();
    void setRating(int r);
    string getDateString();
    string getTimeString();
};

#endif