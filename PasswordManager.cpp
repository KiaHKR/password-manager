#include "PasswordManager.hpp"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    PasswordManager pm;
    pm.displayAllServices();
    return 0;
}

PasswordManager::PasswordManager() : services(make_unique<unordered_map<string, vector<Credentials>>>())
{

    services = make_unique<unordered_map<string, vector<Credentials>>>();
    services->insert({"Google", {Credentials{"user1", "password1"}}});
    services->at("Google").push_back(Credentials{"user2", "password2"});
    services->insert({"Facebook", {Credentials{"user1", "password1"}}});
}

PasswordManager::~PasswordManager()
{
    // Destructor implementation
}

void PasswordManager::displayAllServices()
{
    int entryIndex = 1; // Initialize entry index for each service

    for (const auto &entry : *services)
    {
        cout << "____________________" << endl;
        cout << entry.first << ":" << endl;
        entryIndex = 1; // Reset entry index for each service

        for (const Credentials &credentials : entry.second)
        {
            cout << "Entry " << entryIndex << ":" << endl;
            int total_width = 15;
            int user_space = 3; // Adjust this value as needed

            cout << setw(user_space) << setfill(' ') << "";
            cout << credentials.login;
            cout << setw(total_width - user_space - credentials.login.length()) << setfill('.') << ".";
            cout << credentials.password << endl;
            entryIndex++; // Increment entry index for each entry
        }
    }
}

void addService(string serviceName)
{
    // Implementation for adding a new service
}

void PasswordManager::AddCredentials()
{
    string myService;
    getline(cin, myService);

    if (services->find(myService) != services->end())
    {
        addService(myService);
    }
    else
    {
        Credentials myvar = inputCredentials(myService);
    }
}