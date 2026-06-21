#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "MenuBST.h"
#include "TableManager.h"
#include <fstream>

class FileManager {
private:
    string menuFile = "menu_data.txt";
    string tablesFile = "tables_data.txt";
    
public:
    void saveMenuToFile(MenuBST& menuBST);
    void loadMenuFromFile(MenuBST& menuBST);
    void saveTablesToFile(TableManager& tableManager);
    void loadTablesFromFile(TableManager& tableManager);
};

#endif