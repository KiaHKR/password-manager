#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

int menuLoop();

int main()
{
    int choice;
    do
    {   
        system("cls");
        choice = menuLoop();
        system("cls");
        switch (choice)
        {
        case 1:
            cout << "Display all Services" << endl;
            break;
        case 2:
            cout << "Display one service" << endl;
            break;
        case 3:
            cout << "Search for specific (1) Credential" << endl;
            break;
        case 4:
            cout << "Add a new Credential" << endl;
            break;
        case 5:
            cout << "Exiting..." << endl
                 << "Thank you for using KTPM." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}

int menuLoop()
{
    int choice;
    cout << "1. Display all Services" << endl;
    cout << "2. Display one service" << endl;
    cout << "3. Search for specific (1) Credential" << endl;
    cout << "4. Add a new Credential" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}
