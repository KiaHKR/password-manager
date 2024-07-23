#include "../include/HelperFunctions.hpp"
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

//User inputs the service name that they want to use
//And returns that service name
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
    updateCredentialsSubMenu(services, serviceName, choice);
}

void updateCredentialsSubMenu(shared_ptr<unordered_map<string, vector<Credentials>>> services, string serviceName, int choice) {
    int subMenuChoice;
    Credentials myCred;
    cout << "1. Update Login for " << serviceName << endl;
    cout << "2. Update Password for " << serviceName << endl;
    cout << "3. Update Login and Password for " << serviceName << endl;
    cout << "4. Return to Main Menu" << endl;
    cin >> subMenuChoice;
    fflush(stdin);
    do
    {
        switch (subMenuChoice)
        {
        case 1:
            updateLogin(services, serviceName, choice);
            cout << "Login Successfully Updated" << endl;
            break;
        case 2:
            updatePassword(services, serviceName, choice);
            cout << "Password Successfully Updated" << endl;
            break;
        case 3:
            myCred = inputCredentials(serviceName);
            services->at(serviceName).at(choice - 1) = myCred;
            cout << "Login and Password Successfully Updated" << endl;
            break;
        case 4:
            cout << "No changes has been made. Returning to main menu..." << endl;
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
    // Displays all credentials in a service
    for (int i = 0; i < services->at(serviceName).size(); i++)
    {
        cout << serviceName << ": " << i + 1 << ". " << endl;
        cout << "Login: " << services->at(serviceName).at(i).login << endl;
        cout << "Password: " << services->at(serviceName).at(i).password << endl;
    }
    // Handles which credentials to delete
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
    if(services->at(serviceName).size() < 1) {
        services->erase(serviceName);
    }
    cout << "Credentials at Service " << serviceName << " Has been successfully deleted." << endl;
    cout << "No more credentials stored at service " << serviceName << ". Service has been deleted" << endl;
}