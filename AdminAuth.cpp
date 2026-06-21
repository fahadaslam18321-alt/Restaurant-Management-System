#include "AdminAuth.h"
#include <iostream>
using namespace std;

bool AdminAuth::authenticate() {
    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username == adminUsername && password == adminPassword) {
        cout << "Admin access granted!" << endl;
        return true;
    } else {
        cout << "Invalid credentials!" << endl;
        return false;
    }
}