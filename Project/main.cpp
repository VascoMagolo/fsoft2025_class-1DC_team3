#include <iostream>
#include <string>

using namespace std;

#include "classes.h"
#include "functions.h"
#include "db_connection.h"

int main() {
    int option;
    // Inicial menu, later going to changed by a graphical interface
    DBConnection db("localhost", "root", "password", "fsoft_project");

    if (db.getConnection()) {
        std::cout << "Ready to run queries!" << std::endl;
    }

    while (true) {
        cout << "Menu\n 1 - Create Account\n 2 - Login into account\n 0 - Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                create_bank_account();
                break;
            case 2:
                login();
                break;
            case 0:
                return 0;
            default:
                cout << "Invalid Option.\n";
                break;
        }
    }
}// C:\Program Files\MySQL\MySQL Connector C++ 9.2 is the path to the MySQL Connector C++ 9.2
