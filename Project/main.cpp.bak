#include <iostream>
#include <string>

using namespace std;

#include "classes.h"
#include "functions.h"

int main() {
    cout << "Welcome to the Bank Account Management System\n";
    cout << "Please choose an option from the menu below:\n";
    int option;
    // Inicial menu, later going to be changed by a graphical interface
    while (true) {
        cout << " 1 - Create Account\n 2 - Login into account\n 3 - Admin Area\n 0 - Exit\n";
        cin >> option;

        switch (option) {
            case 1:
                create_bank_account();
                break;
            case 2:
                login();
                break;
            case 3:
                //read_from_json();
                admin_area();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid Option.\n";
                break;
        }
    }
}
