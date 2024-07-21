#include "../include/HelperFunctions.hpp"

using namespace std;

Credentials inputCredentials(string* service)
{
    string login;
    string password;
    cout << "Enter login for " << *service << ": ";
    cin >> login;
    fflush(stdin);
    cout << "Enter password for " << *service << ": ";
    cin >> password;
    fflush(stdin);
    return Credentials{login, password};
}

string getServiceName() {
    string myService;
    cout << "Enter Service Name: " << endl;
    getline(cin, myService);
    fflush(stdin);
    return myService;
}

//Prints out the Credentials in a specified service
//This function is only called when the service exists
//So error handling for if the service does not exist is not needed
void handleCredentialsUpdate(std::shared_ptr<std::unordered_map<std::string, std::vector<Credentials>>> services, std::string* serviceName) {
    vector<Credentials> cArray = services->at(*serviceName);
    for(int i = 0; i < cArray.size(); i++) {
        cout << i + 1 << ". " << endl;
        cout << "Login: " << cArray.at(i).login << endl;
        cout << "Password: " << cArray.at(i).password << endl;
    }

    int choice;
    cout << "Enter Credential Number To Modify: ";
    cin >> choice;
    while(choice < 0 || choice > cArray.size()) {
        
    }

    int subMenuChoice;
    cout << "1. Update Login for " << *serviceName << endl;
    cout << "2. Update Password for " << *serviceName << endl;
    cout << "3. Update Login and Password for " << *serviceName << endl;
    cout << "4. Return to Main Menu" << endl;
    do
    {

        switch (choice)
        {
        case 1:
            break;
        
        default:
            break;
        }
    } while (subMenuChoice != 4);
    
}