#include "../include/HelperFunctions.hpp"
#include <algorithm>
#include <ctype.h>

using namespace std;

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

string getServiceName()
{
    string myService;
    fflush(stdin);
    cout << "Enter Service Name: " << endl;
    getline(cin, myService);
    fflush(stdin);
    return myService;
}

// Prints out the Credentials in a specified service
// This function is only called when the service exists
// So error handling for if the service does not exist is not needed
void handleCredentialsUpdate(shared_ptr<unordered_map<string, vector<Credentials>>> services, string serviceName)
{
    transform(serviceName.begin(), serviceName.end(), serviceName.begin(), ::toupper); // Transform string to upper case

    for (int i = 0; i < services->at(serviceName).size(); i++)
    {
        cout << serviceName << ": " << i + 1 << ". " << endl;
        cout << "Login: " << services->at(serviceName).at(i).login << endl;
        cout << "Password: " << services->at(serviceName).at(i).password << endl;
    }

    int choice;
    cout << "Enter Credential Number To Modify (Type -1 to cancel): ";
    cin >> choice;
    fflush(stdin);
    if(choice == -1) {
        return;
    }
    while (choice < 0 || choice > services->at(serviceName).size() || choice == 0)
    {
        cout << "Invalid Choice." << endl;
        cout << "Enter Credential Number To Modify: ";
        cin >> choice;
        fflush(stdin);
    }

    int subMenuChoice;
    cout << "1. Update Login for " << serviceName << endl;
    cout << "2. Update Password for " << serviceName << endl;
    cout << "3. Update Login and Password for " << serviceName << endl;
    cout << "4. Return to Main Menu" << endl;
    cin >> subMenuChoice;
    Credentials myCred;
    do
    {
        switch (subMenuChoice)
        {
        case 1:
            updateLogin(services, serviceName, choice);
            break;
        case 2:
            updatePassword(services, serviceName, choice);
            break;
        case 3:
            myCred = inputCredentials(serviceName);
            services->at(serviceName).at(choice - 1) = myCred;
            break;
        case 4:
            return;
            break;
        default:
            cout << "Invalid Choice." << endl;
            break;
        }
        break;
    } while (subMenuChoice != 4);
}

void updateLogin(shared_ptr<unordered_map<string, vector<Credentials>>> services, string serviceName, int choice) {
    string login;
    cout << "Enter new Login: ";
    cin >> login;
    fflush(stdin);
    services->at(serviceName).at(choice - 1).login = login;

}

void updatePassword(shared_ptr<unordered_map<string, vector<Credentials>>> services, string serviceName, int choice) {
    string pass;
    cout << "Enter new Login: ";
    cin >> pass;
    fflush(stdin);
    services->at(serviceName).at(choice - 1).password = pass;
}

void handleCredentialsDeletion(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string serviceName) {
    
    for (int i = 0; i < services->at(serviceName).size(); i++)
    {
        cout << serviceName << ": " << i + 1 << ". " << endl;
        cout << "Login: " << services->at(serviceName).at(i).login << endl;
        cout << "Password: " << services->at(serviceName).at(i).password << endl;
    }
    int choice;
    cout << "Enter Credential Number To Delete (Type -1 to cancel): ";
    cin >> choice;
    fflush(stdin);
    if(choice == -1) {
        return;
    }
    while (choice < 0 || choice > services->at(serviceName).size() || choice == 0)
    {
        cout << "Invalid Choice." << endl;
        cout << "Enter Credential Number To Delete: ";
        cin >> choice;
        fflush(stdin);
    }
    
    auto index = services->at(serviceName).begin() + (choice - 1);
    services->at(serviceName).erase(index);
}
