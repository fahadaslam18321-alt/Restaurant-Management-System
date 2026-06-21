#include "MenuBST.h"
#include <iostream>
using namespace std;

BSTNode::BSTNode(MenuItem* item) : data(item), left(nullptr), right(nullptr) {}

MenuBST::MenuBST() : root(nullptr) {}

BSTNode* MenuBST::insert(BSTNode* node, MenuItem* item) {
    if (node == nullptr) return new BSTNode(item);
    
    if (item->getId() < node->data->getId())
        node->left = insert(node->left, item);
    else
        node->right = insert(node->right, item);
        
    return node;
}

void MenuBST::inOrder(BSTNode* node) {
    if (node != nullptr) {
        inOrder(node->left);
        node->data->display();
        inOrder(node->right);
    }
}

MenuItem* MenuBST::search(BSTNode* node, int id) {
    if (node == nullptr || node->data->getId() == id)
        return (node != nullptr) ? node->data : nullptr;
        
    if (id < node->data->getId())
        return search(node->left, id);
    else
        return search(node->right, id);
}

BSTNode* MenuBST::deleteNode(BSTNode* node, int id) {
    if (node == nullptr) return node;
    
    if (id < node->data->getId())
        node->left = deleteNode(node->left, id);
    else if (id > node->data->getId())
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == nullptr) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }
        
        BSTNode* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data->getId());
    }
    return node;
}

BSTNode* MenuBST::minValueNode(BSTNode* node) {
    BSTNode* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

void MenuBST::addItem(MenuItem* item) {
    root = insert(root, item);
}

void MenuBST::displayMenu() {
    cout << "\n";
    cout << "==========================================================" << endl;
    cout << "|                         MENU                           |" << endl;
    cout << "==========================================================" << endl;
    if (root == nullptr) {
        cout << "|                    MENU IS EMPTY                     |" << endl;
    } else {
        inOrder(root);
    }
    cout << "==========================================================" << endl;
}

MenuItem* MenuBST::findItem(int id) {
    return search(root, id);
}

void MenuBST::removeItem(int id) {
    root = deleteNode(root, id);
}

bool MenuBST::isEmpty() {
    return root == nullptr;
}