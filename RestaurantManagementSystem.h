#ifndef RESTAURANTMANAGEMENTSYSTEM_H
#define RESTAURANTMANAGEMENTSYSTEM_H

#include "MenuBST.h"
#include "TableManager.h"
#include "FileManager.h"
#include "BillingSystem.h"
#include "AdminAuth.h"
#include "Order.h"
#include "Deal.h"
#include "Analytics.h"
#include <vector>

class RestaurantManagementSystem {
private:
    MenuBST menuBST;
    TableManager tableManager;
    FileManager fileManager;
    BillingSystem billingSystem;
    AdminAuth adminAuth;
    vector<Order*> allOrders;
    vector<Deal*> deals;
    Analytics* analytics;
    int nextOrderId;
    int nextDealId;
    
public:
    RestaurantManagementSystem();
    ~RestaurantManagementSystem();
    void initializeSampleData();
    void run();
    
    // Menus
    void showMainMenu();
    void showCustomerMenu();
    void showOrderTypeMenu();
    void showAdminMenu();
    void showAnalyticsMenu();
    
    // Customer Functions
    void customerFunctions();
    void placeOrder(string orderType);
    void viewDeals();
    void orderTakeaway();
    void orderDeal();
    void generateBillWithPayment();
    
    // Admin Functions
    void adminFunctions();
    void analyticsFunctions();
    void addMenuItem();
    void removeMenuItem();
    void addDeal();
    void manageDeals();
    void displayAllOrders();
    void freeTableAdmin();
    
    // Add these in private section:
void updateMenuItem();
void updateOrderStatus();
void updateTableDetails();
void updateDeal();
void updateCustomerOrder();
void updateCustomerDetails();
void updateCustomerDetailsMenu();
// Add in public section if needed
    
    // Utility
    void allocateTableToCustomer();
};

#endif