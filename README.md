# Restaurant Management System (RMS)

A robust, enterprise-grade **Restaurant Management System** built entirely in **C++**. This project showcases the practical application of core **Object-Oriented Programming (OOP)** paradigms and advanced **Data Structures (DSA)** to solve real-world business tracking, automation, and management challenges.

---

## 🚀 Key Features

### 🛒 Customer Operations
* **Dynamic Menu Viewing:** Real-time retrieval of food and beverage items with pricing.
* **Table Reservation:** Quick checks on real-time table status and automated availability processing.
* **Combo Deals & Offers:** Dynamic application of predefined restaurant deals.
* **Intelligent Order Placement:** Multi-mode order types (Dine-in, Takeaway, or Combo Deals).
* **Automated Billing:** Instant itemized receipt generation detailing standard tax additions and eligible discounts.

### 🛡️ Admin Dashboard
* **Secure Authentication:** Multi-layered administrative login verification wall.
* **Inventory & Menu Control:** Dynamic CRUD operations (Add, Update, Remove) for standard items and promotional bundles.
* **Live System Monitoring:** Full access to automated order workflow progression, table mappings, and customer updates.
* **Data Intelligence Analytics:** Automated aggregation metrics calculating total sales, visual item popularity counts, and multi-mode payment preferences.

### 💼 Business Logic & Automation
* **Smart Discounts:** Automated 10% discount deduction whenever card payments are captured.
* **Tax Management:** Native 8% tax calculations dynamically added onto raw bills.
* **Capacity Constraint Checks:** Automatic matching engines pairing table sizes with customer group volumes.

---

## 🛠️ System Architecture & Engineering Concepts

### 1. Object-Oriented Programming (OOP)
* **Inheritance & Hierarchy:** A unified polymorphism implementation utilizing `MenuItem` as an abstract base class, branching down into specialized `FoodItem` and `BeverageItem` derived abstractions.
* **Runtime Polymorphism:** Achieved via clean implementation of `virtual` operations (`display()`, `getType()`, `toFileString()`) parsed cleanly at application runtime through base class pointers.
* **Strict Encapsulation:** Safe object-state isolation leveraging private variables and safe access constraints through explicit setters and getters.

### 2. Advanced Data Structures (DSA)
* **Binary Search Tree (BST):** Handled via `MenuBST` using localized node linkages (`BSTNode`) ensuring efficient logarithmic time complexity ($O(\log n)$) for menu insertions, item searches, deletions, and alphabetical In-order sorting traversals.
* **Stack Data Structure:** Active tracking module integrated into the `TableManager` keeping track of unreserved tables for clean stack-allocated table assignments.
* **Hash Tables & Map Mappings:** Efficient tracking implementations mapping out daily transaction counters (`dailySales`), average system rankings (`dailyRatings`), and map structures highlighting the restaurant's highest moving items.
* **Vectors & Sequential Arrays:** Fast structural storage utilities mapping out ongoing dynamic data streams like custom receipts, ongoing customer carts, and global lists (`allOrders`, `deals`).

### 3. File Handling & Persistence
* **State Preservation:** Full file stream implementations mapping transient data variables smoothly across persistent formats via the `FileManager` module.
* **Disk Data Automation:** Automated operations saving or uploading user tables, operational items, active data variables, and generated payment invoices (`Receipt_Order.txt`) directly onto the disk.

---

## 📂 Project Directory Structure

Based on the actual project repository codebase:

```text
├── AdminAuth.h / AdminAuth.cpp               # Administrative Security Controls
├── Analytics.h / Analytics.cpp               # Data Tracking & Report Engine
├── BeverageItem.h / BeverageItem.cpp         # Polymorphic Drinks Control Structure
├── BillingSystem.h / BillingSystem.cpp       # Tax, Discount, and Final Invoice Engines
├── Deal.h / Deal.cpp                         # Specialized Combo Sets & Pricing Logic
├── FileManager.h / FileManager.cpp           # Disk Stream Controllers & File IO
├── FoodItem.h / FoodItem.cpp                 # Polymorphic Entree Control Structure
├── MenuBST.h / MenuBST.cpp                   # Logarithmic BST Engine for Menu Inventory
├── MenuItem.h / MenuItem.cpp                 # Root Polymorphic Base Abstract Interface
├── Order.h / Order.cpp                       # Order Tracking Vectors & Status Workflow
├── Table.h                                   # Individual Table Dimensions & Attributes
├── TableManager.h / TableManager.cpp         # Stack-Allocated Table Reservation Manager
├── RestaurantManagementSystem.h/.cpp         # Main Application Singleton System Orchestrator
├── main.cpp                                  # Execution Entry Point Interface Terminal
├── Student.txt                               # Local System Resource Data File
├── Receipt_Order.txt / Receipt_Order_1.txt   # Auto-Generated Customer Invoices
└── Resturant managment system.exe            # Pre-Compiled Binary Executable File
