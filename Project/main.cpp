#include <iostream>
#include <string>

using namespace std;

#include "classes.h"
#include "functions.h"

int main() {
    int option;
    // Inicial menu, later going to changed by a graphical interface

    while (true) {
        cout
                << "Menu\n 1 - Create Account\n 2 - Login into account\n 3 - Json test read\n0 - Exit\n";
        cin >> option;
        //menu just for testing, later going to be replace, only being able to choose between create and login
        switch (option) {
            case 1:
                create_bank_account();
                break;
            case 2:
                login();
                break;
            case 3:
                read_from_json();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid Option.\n";
                break;
        }
    }
}
