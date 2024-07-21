#include "../include/PasswordManager.hpp"

using namespace std;

PasswordManager::PasswordManager() : services(make_unique<unordered_map<string, vector<Credentials>>>())
{

    services = make_unique<unordered_map<string, vector<Credentials>>>();
    services->insert({"GOOGLE", {Credentials{"user1", "password1"}}});
    services->at("GOOGLE").push_back(Credentials{"user2", "password2"});
    services->insert({"FACEBOOK", {Credentials{"user1", "password1"}}});
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
    Credentials credentials = inputCredentials(myService);                       // Input credentials
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

// Ask the user what they want to change
void PasswordManager::updateCredentials()
{
    string myService = getServiceName();
    transform(myService.begin(), myService.end(), myService.begin(), ::toupper);
    // Credentials credentials = inputCredentials(myService);
    if (services->find(myService) != services->end()) // If service is found
    {
        handleCredentialsUpdate(services, myService);
    }
    else
    {
        cout << "Specified service could not be found." << endl;
    }
}

void PasswordManager::displayOneService()
{
    string serviceName = getServiceName();
    transform(serviceName.begin(), serviceName.end(), serviceName.begin(), ::toupper); // Transform string to upper case

    for (int i = 0; i < services->at(serviceName).size(); i++)
    {
        cout << serviceName << ": " << i + 1 << ". " << endl;
        cout << "Login: " << services->at(serviceName).at(i).login << endl;
        cout << "Password: " << services->at(serviceName).at(i).password << endl;
    }
}

void PasswordManager::deleteCredentials()
{
    string serviceName = getServiceName();
    transform(serviceName.begin(), serviceName.end(), serviceName.begin(), ::toupper); // Transform string to upper case

    if (services->find(serviceName) != services->end())
    {
        handleCredentialsDeletion(services, serviceName);
    }
    else
    {
        cout << "Service not found." << endl;
    }
}

void PasswordManager::deleteService() {
    
}

shared_ptr<unordered_map<string, vector<Credentials>>> PasswordManager::getServices()
{
    // Returns the pointer to the service hashmap
    return services;
}