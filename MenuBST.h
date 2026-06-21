#ifndef MENUBST_H
#define MENUBST_H

#include "MenuItem.h"

class BSTNode {
public:
    MenuItem* data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(MenuItem* item);
};

class MenuBST {
private:
    BSTNode* root;
    
    BSTNode* insert(BSTNode* node, MenuItem* item);
    void inOrder(BSTNode* node);
    MenuItem* search(BSTNode* node, int id);
    BSTNode* deleteNode(BSTNode* node, int id);
    BSTNode* minValueNode(BSTNode* node);
    
public:
    MenuBST();
    void addItem(MenuItem* item);
    void displayMenu();
    MenuItem* findItem(int id);
    void removeItem(int id);
    bool isEmpty();
};

#endif