#ifndef ADMINAUTH_H
#define ADMINAUTH_H
#include <string>
using namespace std;
class AdminAuth {
private:
    string adminUsername = "admin";
    string adminPassword = "admin123";    
public:
    bool authenticate();
};

#endif