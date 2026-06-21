#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "Order.h"
#include <vector>
#include <map>
#include <string>

class Analytics {
private:
    vector<Order*> allOrders;
    
public:
    Analytics(vector<Order*>& orders);
    void showDailySales();
    void showDailyRatings();
    void showTotalRevenue();
    void showPopularItems();
    void showPaymentMethods();
    void generateReport();
};

#endif