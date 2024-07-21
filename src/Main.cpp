#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <climits>
#include <../include/PasswordManager.hpp>

using namespace std;

int menuLoop();

int main()
{

    PasswordManager pm;

    int choice;
    do
    {
        choice = menuLoop();
        switch (choice)
        {
        case 1:
            cout << "\x1B[2J\x1B[H"; // Clear the screen
            pm.displayAllServices(); // Wait for the user to press Enter
            break;
        case 2:
            pm.displayOneService();
            break;
        case 3:
            pm.updateCredentials();
            break;
        case 4:
            pm.addNewCredentials();
            break;
        case 5:
            pm.deleteCredentials();
            break;
        case 6:
            pm.deleteService();
            break;
        case 7:
            cout << "Exiting..." << endl
                 << "Thank you for using KTPM." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            break;
        }
        cout << "Press Enter to continue..." << endl;
        cin.ignore(); // Clear the newline character left in the buffer
        fflush(stdin);
    } while (choice != 7);
    return 0;
}

int menuLoop()
{
    int choice;
    cout << "1. Display all Services" << endl;
    cout << "2. Display Credentials in 1 service" << endl;
    cout << "3. Update Service" << endl;
    cout << "4. Add a new Credential/Service" << endl;
    cout << "5. Delete a Credential" << endl;
    cout << "6. Delete Service (Will remove all Credentials in this service)" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    fflush(stdin);
    return choice;
}
