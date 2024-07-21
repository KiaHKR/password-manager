#include "../include/PasswordManager.hpp"

using namespace std;

int main()
{
    PasswordManager pm;
    // cout << pm.getServices()->at("Google").size() << endl;
    // while (1)
    // {
    //     pm.displayAllServices();
    //     pm.addNewCredentials();
    // }
    // return 0;
    string name = "Google";
    // printCredentials(pm.getServices(),&name);
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

void PasswordManager::addNewCredentials()
{
    string myService = getServiceName();
    Credentials credentials = inputCredentials(&myService);                       // Input credentials
    transform(myService.begin(), myService.end(), myService.begin(), ::toupper); // Transform string to upper case
    if (services->find(myService) != services->end())                            // If Service is found
    {
        services->at(myService).push_back(credentials); // Add credentials to pre-existing service
    }
    else
    {
        services->insert({myService, {credentials}}); // Create new service and add the credentials to it
    }
}

// Get the name of the service to update
// Ask the user what they want to change
void PasswordManager::updateCredentials()
{
    string myService = getServiceName();
    transform(myService.begin(), myService.end(), myService.begin(), ::toupper);
    // Credentials credentials = inputCredentials(myService);
    if (services->find(myService) != services->end()) // If service is found
    {

    }
    else
    {
        cout << "Specified service could not be found." << endl;
    }
}

shared_ptr<unordered_map<string, vector<Credentials>>> PasswordManager::getServices()
{
    // Returns the pointer to the service hashmap
    return services;
}