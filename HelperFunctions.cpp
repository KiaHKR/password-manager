#include "Credentials.hpp"
#include "HelperFunctions.hpp"
#include <iostream>

Credentials inputCredentials(string service)
{
    string login;
    string password;
    cout << "Enter login for " << service << ": ";
    cin >> login;
    cout << "Enter password for " << service << ": ";
    cin >> password;
    return Credentials{login, password};
}