#ifndef BILLINGSYSTEM_H
#define BILLINGSYSTEM_H

#include "Order.h"
#include <iomanip>

class BillingSystem {
public:
    void generateBill(Order* order);
    void printReceipt(Order* order);
};

#endif