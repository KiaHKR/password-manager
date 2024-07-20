#include "Credentials.hpp"
#include "HelperFunctions.hpp"
#include <iostream>

Credentials inputCredentials(string service)
{
    string login;
    string password;
    cout << "Enter login for " << service << ": ";
    cin >> login;
    fflush(stdin);
    cout << "Enter password for " << service << ": ";
    cin >> password;
    fflush(stdin);
    return Credentials{login, password};
}

void updateCredentialsSubMenu() {
    cout << "1. Update Login" << endl;
    cout << "2. Update Password" << endl;
    cout << "3. Update Both" << endl;
    cout << "4. Return to Main Menu" << endl;
}

string inputPassword() {
    string password;
    cout << "Enter New Password to Update: " << endl;
    cin >> password;
    return password;
}

string inputLogin() {
    string login;
    cout << "Enter New Login to Update: " << endl;
    cin >> login;
    return login;
}

void updatePassword(string* service) {
    
}