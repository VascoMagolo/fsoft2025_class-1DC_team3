// Functions File
#include "classes.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <ctime>// Library to generate random numbers

using namespace std;

// Function to create a bank account
void create_bank_account() {
    string name, address, password;
    int age, op = 0;
    double balance = 0.0;

    cout << "Name:\n";
    cin.ignore(); // Clear the input buffer
    getline(cin, name); // Get the name

    cout << "Age:\n";
    while (!(cin >> age)) {
        cout << "Invalid input. Please enter a valid age:\n";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }

    cout << "Address:\n";
    cin.ignore(); // Clear the input buffer
    getline(cin, address); // Get the address

    cout << "Password:\n";
    getline(cin, password); // Get the password

    while (op != 1 && op != 2) {
        cout << "Do you want to add balance? \n Yes-1 No-2\n";
        cin >> op;
        if (op == 1) {
            cout << "Add Balance:\n";
            while (!(cin >> balance)) {
                cout << "Invalid input. Please enter a valid balance:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (op != 2 && op != 1) {
            cout << "Invalid\n";
        }
    }
    Bank_Account account(rand(), balance, age, name, address,
                         password);// Creates an account with a random account number, later its going to be change by a unique number
    cout << "Account Created!\n";
    account.display(); // Display the account number and balance
    account.saveBalanceToFile(account.account_number); // Save the account balance to a file
}

// Function to login into an account, later going to be created when connecting to a database
int login() {
    return 0;
}

// Function to display the menu
void menu() {

}

void create_mysqlcon() {
    //creats mysql connection to the database localhost 3306 root vasco2005 fsoft_project

}
