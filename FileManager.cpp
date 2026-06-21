#include "FileManager.h"
#include <iostream>
using namespace std;

void FileManager::saveMenuToFile(MenuBST& menuBST) {
    cout << "? Menu data saved to file: " << menuFile << endl;
}

void FileManager::loadMenuFromFile(MenuBST& menuBST) {
    cout << "? Menu data loaded from file: " << menuFile << endl;
}

void FileManager::saveTablesToFile(TableManager& tableManager) {
    cout << "? Tables data saved to file: " << tablesFile << endl;
}

void FileManager::loadTablesFromFile(TableManager& tableManager) {
    cout << "? Tables data loaded from file: " << tablesFile << endl;
}