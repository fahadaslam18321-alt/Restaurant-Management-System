#include "Analytics.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
using namespace std;

Analytics::Analytics(vector<Order*>& orders) : allOrders(orders) {}

void Analytics::showDailySales() {
    map<string, double> dailySales;
    map<string, int> dailyOrders;
    
    for (auto order : allOrders) {
        string date = order->getDateString();
        dailySales[date] += order->getTotalAmount();
        dailyOrders[date]++;
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                    DAILY SALES                         |" << endl;
    cout << "==========================================================" << endl;
    for (auto& entry : dailySales) {
        cout << "| Date: " << setw(12) << left << entry.first 
             << " | Orders: " << setw(3) << dailyOrders[entry.first]
             << " | Revenue: $" << setw(8) << fixed << setprecision(2) << entry.second << " |" << endl;
    }
    cout << "==========================================================" << endl;
}

void Analytics::showDailyRatings() {
    map<string, pair<double, int>> dailyRatings;
    
    for (auto order : allOrders) {
        if (order->rating > 0) {
            string date = order->getDateString();
            dailyRatings[date].first += order->rating;
            dailyRatings[date].second++;
        }
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                   DAILY RATINGS                        |" << endl;
    cout << "==========================================================" << endl;
    for (auto& entry : dailyRatings) {
        double avgRating = entry.second.first / entry.second.second;
        cout << "| Date: " << setw(12) << left << entry.first
             << " | Avg Rating: " << fixed << setprecision(1) << avgRating << "/5"
             << " | Total Reviews: " << entry.second.second << " |" << endl;
    }
    cout << "==========================================================" << endl;
}

void Analytics::showTotalRevenue() {
    double totalRevenue = 0.0;
    int totalOrders = allOrders.size();
    
    for (auto order : allOrders) {
        totalRevenue += order->getTotalAmount();
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                   TOTAL REVENUE                        |" << endl;
    cout << "==========================================================" << endl;
    cout << "| Total Orders: " << setw(43) << left << totalOrders << "|" << endl;
    cout << "| Total Revenue: $" << setw(41) << left << fixed << setprecision(2) << totalRevenue << "|" << endl;
    cout << "| Average Order Value: $" << setw(36) << left << (totalOrders > 0 ? totalRevenue/totalOrders : 0) << "|" << endl;
    cout << "==========================================================" << endl;
}

void Analytics::showPopularItems() {
    map<string, int> itemCount;
    
    for (auto order : allOrders) {
        for (auto item : order->items) {
            itemCount[item->getName()]++;
        }
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                   POPULAR ITEMS                        |" << endl;
    cout << "==========================================================" << endl;
    vector<pair<string, int>> items(itemCount.begin(), itemCount.end());
    sort(items.begin(), items.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });
    
    int count = 0;
    for (auto& item : items) {
        if (count++ < 5) {
            cout << "| " << setw(20) << left << item.first 
                 << " | Sold: " << setw(3) << right << item.second << " times"
                 << " |" << endl;
        }
    }
    cout << "==========================================================" << endl;
}

void Analytics::showPaymentMethods() {
    int cashCount = 0, cardCount = 0;
    double cashAmount = 0, cardAmount = 0;
    
    for (auto order : allOrders) {
        if (order->paymentMethod == "Cash") {
            cashCount++;
            cashAmount += order->getTotalAmount();
        } else if (order->paymentMethod == "Card") {
            cardCount++;
            cardAmount += order->getTotalAmount();
        }
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                  PAYMENT METHODS                       |" << endl;
    cout << "==========================================================" << endl;
    cout << "| Cash Payments: " << setw(4) << cashCount 
         << " | Amount: $" << setw(8) << fixed << setprecision(2) << cashAmount << " |" << endl;
    cout << "| Card Payments: " << setw(4) << cardCount 
         << " | Amount: $" << setw(8) << cardAmount 
         << " | Discount Given: $" << setw(6) << cardAmount * 0.10 << " |" << endl;
    cout << "==========================================================" << endl;
}

void Analytics::generateReport() {
    showTotalRevenue();
    showDailySales();
    showDailyRatings();
    showPopularItems();
    showPaymentMethods();
}