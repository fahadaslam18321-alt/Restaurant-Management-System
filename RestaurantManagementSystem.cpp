#include "RestaurantManagementSystem.h"
#include <iostream>
#include <limits>
#include "FoodItem.h"
#include "BeverageItem.h"
using namespace std;

RestaurantManagementSystem::RestaurantManagementSystem() 
    : nextOrderId(1), nextDealId(1) {
    initializeSampleData();
    analytics = new Analytics(allOrders);
}

RestaurantManagementSystem::~RestaurantManagementSystem() {
    delete analytics;
    for (auto deal : deals) delete deal;
    for (auto order : allOrders) delete order;
}

void RestaurantManagementSystem::initializeSampleData() {
    menuBST.addItem(new FoodItem(101, "Burger", "Main Course", 8.99, 50, 10));
    menuBST.addItem(new FoodItem(102, "Pizza", "Main Course", 12.99, 30, 15));
    menuBST.addItem(new FoodItem(103, "Salad", "Appetizer", 6.99, 40, 5));
    menuBST.addItem(new BeverageItem(201, "Cola", "Beverage", 2.99, 100, false));
    menuBST.addItem(new BeverageItem(202, "Juice", "Beverage", 3.99, 80, false));
    
    Deal* combo1 = new Deal(1, "Family Combo", "Burger + Pizza + 2 Colas", 30.0, 24.99);
    combo1->addItem(menuBST.findItem(101));
    combo1->addItem(menuBST.findItem(102));
    combo1->addItem(menuBST.findItem(201));
    combo1->addItem(menuBST.findItem(201));
    deals.push_back(combo1);
    
    Deal* combo2 = new Deal(2, "Lunch Special", "Burger + Salad + Juice", 18.0, 14.99);
    combo2->addItem(menuBST.findItem(101));
    combo2->addItem(menuBST.findItem(103));
    combo2->addItem(menuBST.findItem(202));
    deals.push_back(combo2);
}

void RestaurantManagementSystem::showMainMenu() {
    cout << "\n";
    cout << "==============================================" << endl;
    cout << "|        RESTAURANT MANAGEMENT SYSTEM        |" << endl;
    cout << "==============================================" << endl;
    cout << "|   1. Customer Functions                    |" << endl;
    cout << "|   2. Admin Functions                       |" << endl;
    cout << "|   0. Exit                                  |" << endl;
    cout << "==============================================" << endl;
    cout << "Enter choice: ";
}

void RestaurantManagementSystem::showCustomerMenu() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                    CUSTOMER MENU                       |" << endl;
    cout << "==========================================================" << endl;
    cout << "|  1.  View Menu                                         |" << endl;
    cout << "|  2.  View Table Status                                 |" << endl;
    cout << "|  3.  View Deals & Packages                             |" << endl;
    cout << "|  4.  Place Order (Dine-in/Takeaway/Deal)               |" << endl;
    cout << "|  5.  Update My Order                                   |" << endl;
    cout << "|  6.  Generate Bill & Pay                               |" << endl;
    cout << "|  7.  Update My Details                                 |" << endl;
    cout << "|  0.  Back to Main Menu                                 |" << endl;
    cout << "==========================================================" << endl;
    cout << "Enter your choice: ";
}

void RestaurantManagementSystem::showOrderTypeMenu() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                     ORDER TYPE                         |" << endl;
    cout << "==========================================================" << endl;
    cout << "|  1.  Dine-in                                           |" << endl;
    cout << "|  2.  Takeaway                                          |" << endl;
    cout << "|  3.  Deal/Package                                      |" << endl;
    cout << "|  0.  Back                                              |" << endl;
    cout << "==========================================================" << endl;
    cout << "Enter your choice: ";
}

void RestaurantManagementSystem::showAdminMenu() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                      ADMIN MENU                        |" << endl;
    cout << "==========================================================" << endl;
    cout << "|  1.  Add Menu Item                                     |" << endl;
    cout << "|  2.  Update Menu Item                                  |" << endl;
    cout << "|  3.  Remove Menu Item                                  |" << endl;
    cout << "|  4.  Add New Deal                                      |" << endl;
    cout << "|  5.  Update Deal                                       |" << endl;
    cout << "|  6.  Manage Deals                                      |" << endl;
    cout << "|  7.  View All Orders                                   |" << endl;
    cout << "|  8.  Update Order Status                               |" << endl;
    cout << "|  9.  Update Table Details                              |" << endl;
    cout << "| 10.  Update Customer Details                           |" << endl;
    cout << "| 11.  Free Table                                        |" << endl;
    cout << "| 12.  Analytics Dashboard                               |" << endl;
    cout << "| 13.  Save Data to File                                 |" << endl;
    cout << "| 14.  Load Data from File                               |" << endl;
    cout << "|  0.  Back to Main Menu                                 |" << endl;
    cout << "==========================================================" << endl;
    cout << "Enter your choice: ";
}

void RestaurantManagementSystem::showAnalyticsMenu() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                   ANALYTICS MENU                       |" << endl;
    cout << "==========================================================" << endl;
    cout << "|  1.  Daily Sales Report                                |" << endl;
    cout << "|  2.  Daily Ratings Report                              |" << endl;
    cout << "|  3.  Total Revenue                                     |" << endl;
    cout << "|  4.  Popular Items                                     |" << endl;
    cout << "|  5.  Payment Methods Analysis                          |" << endl;
    cout << "|  6.  Generate Complete Report                          |" << endl;
    cout << "|  0.  Back to Admin Menu                                |" << endl;
    cout << "==========================================================" << endl;
    cout << "Enter your choice: ";
}

void RestaurantManagementSystem::run() {
    int choice;
    do {
        showMainMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                customerFunctions();
                break;
            case 2:
                adminFunctions();
                break;
            case 0:
                cout << "Thank you for using Restaurant Management System!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
}

void RestaurantManagementSystem::customerFunctions() {
    int choice;
    do {
        showCustomerMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                menuBST.displayMenu();
                break;
            case 2:
                tableManager.displayAllTables();
                break;
            case 3:
                viewDeals();
                break;
            case 4:
                {
                    int orderTypeChoice;
                    do {
                        showOrderTypeMenu();
                        cin >> orderTypeChoice;
                        
                        switch(orderTypeChoice) {
                            case 1:
                                allocateTableToCustomer();
                                placeOrder("Dine-in");
                                break;
                            case 2:
                                orderTakeaway();
                                break;
                            case 3:
                                orderDeal();
                                break;
                            case 0:
                                break;
                            default:
                                cout << "Invalid choice!" << endl;
                        }
                    } while (orderTypeChoice != 0);
                }
                break;
            case 5:
                updateCustomerOrder();
                break;
            case 6:
                generateBillWithPayment();
                break;
            case 7:
                updateCustomerDetailsMenu();
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void RestaurantManagementSystem::viewDeals() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                  AVAILABLE DEALS                       |" << endl;
    cout << "==========================================================" << endl;
    if (deals.empty()) {
        cout << "|                No deals available!                   |" << endl;
    } else {
        for (auto deal : deals) {
            if (deal->getAvailability()) {
                deal->display();
            }
        }
    }
    cout << "==========================================================" << endl;
}

void RestaurantManagementSystem::placeOrder(string orderType) {
    int tableNumber = 0;
    Table* table = nullptr;
    
    if (orderType == "Dine-in") {
        cout << "Enter table number for order: ";
        cin >> tableNumber;
        
        if (!tableManager.isTableOccupied(tableNumber)) {
            cout << "Table is not occupied! Please allocate table first." << endl;
            return;
        }
        table = tableManager.getTable(tableNumber);
    }
    
    Order* order = new Order(nextOrderId++, table, orderType);
    int itemId, quantity;
    
    cout << "Placing " << orderType << " order" << endl;
    if (table) {
        cout << "For Table " << tableNumber << " (" << table->getCustomerName() << ")" << endl;
    }
    
    menuBST.displayMenu();
    
    cout << "Enter Item ID (0 to finish): ";
    while (cin >> itemId && itemId != 0) {
        MenuItem* item = menuBST.findItem(itemId);
        if (item != nullptr) {
            cout << "Enter quantity: ";
            cin >> quantity;
            order->addItem(item, quantity);
            cout << "Added " << quantity << "x " << item->getName() << endl;
        } else {
            cout << "Item not found!" << endl;
        }
        cout << "Enter Item ID (0 to finish): ";
    }
    
    order->setStatus("Confirmed");
    allOrders.push_back(order);
    cout << "Order placed successfully! Order ID: " << order->orderId << endl;
}

void RestaurantManagementSystem::orderTakeaway() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                    TAKEAWAY ORDER                      |" << endl;
    cout << "==========================================================" << endl;
    cout << "|            Welcome! No table needed.                   |" << endl;
    cout << "==========================================================" << endl;
    
    string customerName;
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, customerName);
    
    Order* order = new Order(nextOrderId++, nullptr, "Takeaway");
    int itemId, quantity;
    
    menuBST.displayMenu();
    
    cout << "Enter Item ID (0 to finish): ";
    while (cin >> itemId && itemId != 0) {
        MenuItem* item = menuBST.findItem(itemId);
        if (item != nullptr) {
            cout << "Enter quantity: ";
            cin >> quantity;
            order->addItem(item, quantity);
            cout << "Added " << quantity << "x " << item->getName() << endl;
        } else {
            cout << "Item not found!" << endl;
        }
        cout << "Enter Item ID (0 to finish): ";
    }
    
    order->setStatus("Ready for Pickup");
    allOrders.push_back(order);
    cout << "Takeaway order placed! Order ID: " << order->orderId << endl;
    cout << "Please collect your order in 15 minutes." << endl;
}

void RestaurantManagementSystem::orderDeal() {
    viewDeals();
    
    if (deals.empty()) {
        cout << "No deals available!" << endl;
        return;
    }
    
    int dealChoice;
    cout << "Enter Deal number to order (0 to cancel): ";
    cin >> dealChoice;
    
    if (dealChoice > 0 && dealChoice <= deals.size()) {
        Deal* selectedDeal = deals[dealChoice - 1];
        if (!selectedDeal->getAvailability()) {
            cout << "This deal is currently unavailable!" << endl;
            return;
        }
        
        Order* order = new Order(nextOrderId++, nullptr, "Deal: " + selectedDeal->getName());
        order->addItem(nullptr, 1);
        order->totalAmount = selectedDeal->getDealPrice();
        
        order->setStatus("Confirmed");
        allOrders.push_back(order);
        cout << "Deal ordered successfully! Order ID: " << order->orderId << endl;
        cout << "Deal: " << selectedDeal->getName() << " - $" << selectedDeal->getDealPrice() << endl;
    }
}

void RestaurantManagementSystem::generateBillWithPayment() {
    int orderId;
    cout << "Enter Order ID to generate bill: ";
    cin >> orderId;
    
    Order* targetOrder = nullptr;
    for (auto order : allOrders) {
        if (order->orderId == orderId) {
            targetOrder = order;
            break;
        }
    }
    
    if (targetOrder != nullptr) {
        int paymentChoice;
        cout << "\nSelect Payment Method:" << endl;
        cout << "1. Cash (No discount)" << endl;
        cout << "2. Card (10% discount)" << endl;
        cout << "Enter choice: ";
        cin >> paymentChoice;
        
        if (paymentChoice == 1) {
            targetOrder->setPaymentMethod("Cash");
        } else if (paymentChoice == 2) {
            targetOrder->setPaymentMethod("Card");
        } else {
            cout << "Invalid choice! Defaulting to Cash." << endl;
            targetOrder->setPaymentMethod("Cash");
        }
        
        billingSystem.generateBill(targetOrder);
        
        if (targetOrder->table) {
            tableManager.freeTable(targetOrder->table->getTableNumber());
            cout << "Table " << targetOrder->table->getTableNumber() << " freed after payment." << endl;
        }
    } else {
        cout << "Order not found!" << endl;
    }
}

void RestaurantManagementSystem::adminFunctions() {
    if (!adminAuth.authenticate()) {
        return;
    }
    
    int choice;
    do {
        showAdminMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                addMenuItem();
                break;
            case 2:
                updateMenuItem();
                break;
            case 3:
                removeMenuItem();
                break;
            case 4:
                addDeal();
                break;
            case 5:
                updateDeal();
                break;
            case 6:
                manageDeals();
                break;
            case 7:
                displayAllOrders();
                break;
            case 8:
                updateOrderStatus();
                break;
            case 9:
                updateTableDetails();
                break;
            case 10:
                updateCustomerDetails();
                break;
            case 11:
                freeTableAdmin();
                break;
            case 12:
                analyticsFunctions();
                break;
            case 13:
                fileManager.saveMenuToFile(menuBST);
                fileManager.saveTablesToFile(tableManager);
                break;
            case 14:
                fileManager.loadMenuFromFile(menuBST);
                fileManager.loadTablesFromFile(tableManager);
                break;
            case 0:
                cout << "Returning to main menu..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void RestaurantManagementSystem::analyticsFunctions() {
    int choice;
    do {
        showAnalyticsMenu();
        cin >> choice;
        
        switch(choice) {
            case 1:
                analytics->showDailySales();
                break;
            case 2:
                analytics->showDailyRatings();
                break;
            case 3:
                analytics->showTotalRevenue();
                break;
            case 4:
                analytics->showPopularItems();
                break;
            case 5:
                analytics->showPaymentMethods();
                break;
            case 6:
                analytics->generateReport();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);
}

void RestaurantManagementSystem::addMenuItem() {
    int id, stock, prepTime;
    string name, category, type;
    double price;
    
    cout << "Enter Item ID: "; cin >> id;
    cout << "Enter Name: "; cin >> name;
    cout << "Enter Category: "; cin >> category;
    cout << "Enter Price: "; cin >> price;
    cout << "Enter Stock: "; cin >> stock;
    cout << "Enter Type (food/beverage): "; cin >> type;
    
    if (type == "food") {
        cout << "Enter Preparation Time: "; cin >> prepTime;
        menuBST.addItem(new FoodItem(id, name, category, price, stock, prepTime));
    } else {
        bool isAlcoholic;
        cout << "Is Alcoholic? (1 for yes, 0 for no): "; cin >> isAlcoholic;
        menuBST.addItem(new BeverageItem(id, name, category, price, stock, isAlcoholic));
    }
    
    cout << "Menu item added successfully!" << endl;
}

void RestaurantManagementSystem::removeMenuItem() {
    int id;
    cout << "Enter Item ID to remove: ";
    cin >> id;
    
    MenuItem* item = menuBST.findItem(id);
    if (item != nullptr) {
        menuBST.removeItem(id);
        cout << "Menu item removed successfully!" << endl;
    } else {
        cout << "Item not found!" << endl;
    }
}

void RestaurantManagementSystem::addDeal() {
    string name, description;
    double originalPrice, dealPrice;
    
    cout << "Enter Deal Name: ";
    cin.ignore();
    getline(cin, name);
    
    cout << "Enter Description: ";
    getline(cin, description);
    
    cout << "Enter Original Price: $";
    cin >> originalPrice;
    
    cout << "Enter Deal Price: $";
    cin >> dealPrice;
    
    Deal* newDeal = new Deal(nextDealId++, name, description, originalPrice, dealPrice);
    
    menuBST.displayMenu();
    int itemId;
    cout << "Add items to deal (0 to finish): ";
    while (cin >> itemId && itemId != 0) {
        MenuItem* item = menuBST.findItem(itemId);
        if (item != nullptr) {
            newDeal->addItem(item);
            cout << "Added " << item->getName() << " to deal" << endl;
        } else {
            cout << "Item not found!" << endl;
        }
        cout << "Add items to deal (0 to finish): ";
    }
    
    deals.push_back(newDeal);
    cout << "Deal added successfully!" << endl;
}

void RestaurantManagementSystem::manageDeals() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                     MANAGE DEALS                       |" << endl;
    cout << "==========================================================" << endl;
    for (int i = 0; i < deals.size(); i++) {
        cout << "Deal #" << (i+1) << ": ";
        deals[i]->display();
    }
    
    int dealNumber, action;
    cout << "Enter deal number to manage (0 to cancel): ";
    cin >> dealNumber;
    
    if (dealNumber > 0 && dealNumber <= deals.size()) {
        cout << "1. Toggle Availability" << endl;
        cout << "2. Remove Deal" << endl;
        cout << "Enter action: ";
        cin >> action;
        
        if (action == 1) {
            deals[dealNumber-1]->toggleAvailability();
            cout << "Deal availability updated!" << endl;
        } else if (action == 2) {
            delete deals[dealNumber-1];
            deals.erase(deals.begin() + dealNumber - 1);
            cout << "Deal removed!" << endl;
        }
    }
}

void RestaurantManagementSystem::displayAllOrders() {
    if (allOrders.empty()) {
        cout << "No orders placed yet!" << endl;
        return;
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                     ALL ORDERS                         |" << endl;
    cout << "==========================================================" << endl;
    for (auto order : allOrders) {
        order->display();
    }
    cout << "==========================================================" << endl;
}

void RestaurantManagementSystem::freeTableAdmin() {
    int tableNumber;
    cout << "Enter table number to free: ";
    cin >> tableNumber;
    tableManager.freeTable(tableNumber);
}

void RestaurantManagementSystem::allocateTableToCustomer() {
    if (!tableManager.hasAvailableTables()) {
        cout << "Sorry! Restaurant is full. No tables available." << endl;
        return;
    }
    
    string customerName;
    int requiredCapacity;
    
    cout << "Enter customer name: ";
    cin.ignore();
    getline(cin, customerName);
    
    cout << "Enter required capacity: ";
    cin >> requiredCapacity;
    
    tableManager.allocateTable(customerName, requiredCapacity);
}

void RestaurantManagementSystem::updateMenuItem() {
    int id;
    cout << "Enter Menu Item ID to update: ";
    cin >> id;
    
    MenuItem* item = menuBST.findItem(id);
    if (item != nullptr) {
        int choice;
        cout << "\n";
        cout << "==========================================================" << endl;
        cout << "|                  UPDATE MENU ITEM                      |" << endl;
        cout << "==========================================================" << endl;
        cout << "|  1.  Update Name                                       |" << endl;
        cout << "|  2.  Update Price                                      |" << endl;
        cout << "|  3.  Update Stock                                      |" << endl;
        cout << "|  4.  Update Category                                   |" << endl;
        cout << "|  0.  Cancel                                            |" << endl;
        cout << "==========================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                string newName;
                cout << "Current Name: " << item->getName() << endl;
                cout << "Enter new Name: ";
                cin.ignore();
                getline(cin, newName);
                cout << "Name updated to: " << newName << endl;
                break;
            }
            case 2: {
                double newPrice;
                cout << "Current Price: $" << item->getPrice() << endl;
                cout << "Enter new Price: $";
                cin >> newPrice;
                cout << "Price updated to: $" << newPrice << endl;
                break;
            }
            case 3: {
                int newStock;
                cout << "Current Stock: " << item->getStock() << endl;
                cout << "Enter new Stock quantity: ";
                cin >> newStock;
                cout << "Stock updated to: " << newStock << endl;
                break;
            }
            case 4: {
                string newCategory;
                cout << "Current Category: " << item->getCategory() << endl;
                cout << "Enter new Category: ";
                cin >> newCategory;
                cout << "Category updated to: " << newCategory << endl;
                break;
            }
            case 0:
                cout << "Update cancelled." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } else {
        cout << "Menu item not found!" << endl;
    }
}

void RestaurantManagementSystem::updateOrderStatus() {
    int orderId;
    cout << "Enter Order ID to update status: ";
    cin >> orderId;
    
    Order* targetOrder = nullptr;
    for (auto order : allOrders) {
        if (order->orderId == orderId) {
            targetOrder = order;
            break;
        }
    }
    
    if (targetOrder != nullptr) {
        int statusChoice;
        cout << "\nCurrent Status: " << targetOrder->status << endl;
        cout << "Select new status:" << endl;
        cout << "1. Pending" << endl;
        cout << "2. Preparing" << endl;
        cout << "3. Ready" << endl;
        cout << "4. Served" << endl;
        cout << "5. Completed" << endl;
        cout << "6. Cancelled" << endl;
        cout << "Enter choice: ";
        cin >> statusChoice;
        
        switch(statusChoice) {
            case 1: targetOrder->setStatus("Pending"); break;
            case 2: targetOrder->setStatus("Preparing"); break;
            case 3: targetOrder->setStatus("Ready"); break;
            case 4: targetOrder->setStatus("Served"); break;
            case 5: targetOrder->setStatus("Completed"); break;
            case 6: targetOrder->setStatus("Cancelled"); break;
            default: cout << "Invalid choice!" << endl;
        }
        
        if (statusChoice >= 1 && statusChoice <= 6) {
            cout << "Order status updated to: " << targetOrder->status << endl;
        }
    } else {
        cout << "Order not found!" << endl;
    }
}

void RestaurantManagementSystem::updateTableDetails() {
    int tableNumber;
    cout << "Enter Table Number to update: ";
    cin >> tableNumber;
    
    Table* table = tableManager.getTable(tableNumber);
    if (table != nullptr) {
        int choice;
        cout << "\n";
        cout << "==========================================================" << endl;
        cout << "|                   UPDATE TABLE                         |" << endl;
        cout << "==========================================================" << endl;
        cout << "|  1.  Update Capacity                                  |" << endl;
        cout << "|  2.  Update Customer Name                             |" << endl;
        cout << "|  3.  Update Status                                    |" << endl;
        cout << "|  0.  Cancel                                           |" << endl;
        cout << "==========================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int newCapacity;
                cout << "Current Capacity: " << table->getCapacity() << endl;
                cout << "Enter new Capacity: ";
                cin >> newCapacity;
                cout << "Table capacity updated to: " << newCapacity << endl;
                break;
            }
            case 2: {
                if (table->getIsOccupied()) {
                    string newName;
                    cout << "Current Customer: " << table->getCustomerName() << endl;
                    cout << "Enter new Customer Name: ";
                    cin.ignore();
                    getline(cin, newName);
                    cout << "Customer name updated to: " << newName << endl;
                } else {
                    cout << "Table is not occupied!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Current Status: " << (table->getIsOccupied() ? "Occupied" : "Available") << endl;
                int statusChoice;
                cout << "1. Mark as Available" << endl;
                cout << "2. Mark as Occupied" << endl;
                cout << "Enter choice: ";
                cin >> statusChoice;
                
                if (statusChoice == 1) {
                    table->freeTable();
                    cout << "Table marked as Available" << endl;
                } else if (statusChoice == 2) {
                    string customerName;
                    cout << "Enter Customer Name: ";
                    cin.ignore();
                    getline(cin, customerName);
                    table->occupyTable(customerName);
                    cout << "Table marked as Occupied by " << customerName << endl;
                }
                break;
            }
            case 0:
                cout << "Update cancelled." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } else {
        cout << "Table not found!" << endl;
    }
}

void RestaurantManagementSystem::updateDeal() {
    if (deals.empty()) {
        cout << "No deals available to update!" << endl;
        return;
    }
    
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                     AVAILABLE DEALS                    |" << endl;
    cout << "==========================================================" << endl;
    for (int i = 0; i < deals.size(); i++) {
        cout << i+1 << ". ";
        deals[i]->display();
    }
    
    int dealChoice;
    cout << "Select deal number to update (0 to cancel): ";
    cin >> dealChoice;
    
    if (dealChoice > 0 && dealChoice <= deals.size()) {
        Deal* deal = deals[dealChoice-1];
        int choice;
        cout << "\n";
        cout << "==========================================================" << endl;
        cout << "|                     UPDATE DEAL                        |" << endl;
        cout << "==========================================================" << endl;
        cout << "|  1.  Update Price                                     |" << endl;
        cout << "|  2.  Update Availability                              |" << endl;
        cout << "|  3.  Update Description                               |" << endl;
        cout << "|  0.  Cancel                                           |" << endl;
        cout << "==========================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                double newPrice;
                cout << "Current Deal Price: $" << deal->getDealPrice() << endl;
                cout << "Enter new Deal Price: $";
                cin >> newPrice;
                cout << "Deal price updated to: $" << newPrice << endl;
                break;
            }
            case 2: {
                deal->toggleAvailability();
                cout << "Deal availability toggled!" << endl;
                cout << "New Status: " << (deal->getAvailability() ? "Available" : "Not Available") << endl;
                break;
            }
            case 3: {
                string newDesc;
                cout << "Enter new description: ";
                cin.ignore();
                getline(cin, newDesc);
                cout << "Description updated!" << endl;
                break;
            }
            case 0:
                cout << "Update cancelled." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

void RestaurantManagementSystem::updateCustomerDetails() {
    int orderId;
    cout << "Enter Order ID to update customer details: ";
    cin >> orderId;
    
    Order* targetOrder = nullptr;
    for (auto order : allOrders) {
        if (order->orderId == orderId) {
            targetOrder = order;
            break;
        }
    }
    
    if (targetOrder != nullptr && targetOrder->table != nullptr) {
        string newName;
        cout << "Current Customer Name: " << targetOrder->table->getCustomerName() << endl;
        cout << "Enter new Customer Name: ";
        cin.ignore();
        getline(cin, newName);
        
        targetOrder->table->occupyTable(newName);
        cout << "Customer name updated to: " << newName << endl;
    } else {
        cout << "Order not found or not a dine-in order!" << endl;
    }
}

void RestaurantManagementSystem::updateCustomerOrder() {
    int orderId;
    cout << "Enter your Order ID to update: ";
    cin >> orderId;
    
    Order* targetOrder = nullptr;
    for (auto order : allOrders) {
        if (order->orderId == orderId) {
            targetOrder = order;
            break;
        }
    }
    
    if (targetOrder != nullptr) {
        if (targetOrder->status == "Pending" || targetOrder->status == "Preparing") {
            int choice;
            cout << "\n";
            cout << "==========================================================" << endl;
            cout << "|                 UPDATE YOUR ORDER                      |" << endl;
            cout << "==========================================================" << endl;
            cout << "|  1.  Add More Items                                   |" << endl;
            cout << "|  2.  Remove Items                                     |" << endl;
            cout << "|  3.  Cancel Order                                     |" << endl;
            cout << "|  0.  Back                                             |" << endl;
            cout << "==========================================================" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            
            switch(choice) {
                case 1: {
                    menuBST.displayMenu();
                    int itemId, quantity;
                    cout << "Enter Item ID to add (0 to finish): ";
                    while (cin >> itemId && itemId != 0) {
                        MenuItem* item = menuBST.findItem(itemId);
                        if (item != nullptr) {
                            cout << "Enter quantity: ";
                            cin >> quantity;
                            targetOrder->addItem(item, quantity);
                            cout << "Added " << quantity << "x " << item->getName() << endl;
                        } else {
                            cout << "Item not found!" << endl;
                        }
                        cout << "Enter Item ID to add (0 to finish): ";
                    }
                    cout << "Order updated successfully!" << endl;
                    break;
                }
                case 2: {
                    cout << "Current items in order:" << endl;
                    for (int i = 0; i < targetOrder->items.size(); i++) {
                        cout << i+1 << ". " << targetOrder->items[i]->getName() 
                             << " ($" << targetOrder->items[i]->getPrice() << ")" << endl;
                    }
                    int itemNum;
                    cout << "Enter item number to remove (0 to cancel): ";
                    cin >> itemNum;
                    
                    if (itemNum > 0 && itemNum <= targetOrder->items.size()) {
                        cout << "Item removed from order!" << endl;
                    }
                    break;
                }
                case 3: {
                    char confirm;
                    cout << "Are you sure you want to cancel this order? (y/n): ";
                    cin >> confirm;
                    if (confirm == 'y' || confirm == 'Y') {
                        targetOrder->setStatus("Cancelled");
                        cout << "Order cancelled successfully!" << endl;
                    }
                    break;
                }
                case 0:
                    cout << "Returning..." << endl;
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
        } else {
            cout << "Cannot update order. Current status: " << targetOrder->status << endl;
            cout << "Only orders with 'Pending' or 'Preparing' status can be updated." << endl;
        }
    } else {
        cout << "Order not found!" << endl;
    }
}

void RestaurantManagementSystem::updateCustomerDetailsMenu() {
    int tableNumber;
    cout << "Enter your Table Number: ";
    cin >> tableNumber;
    
    Table* table = tableManager.getTable(tableNumber);
    if (table != nullptr && table->getIsOccupied()) {
        string newName;
        cout << "Current name: " << table->getCustomerName() << endl;
        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, newName);
        
        table->occupyTable(newName);
        cout << "Your details updated successfully!" << endl;
    } else {
        cout << "Table not found or not occupied!" << endl;
    }
}