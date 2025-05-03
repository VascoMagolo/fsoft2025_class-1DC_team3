// Functions File
#include "classes.h"
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <cstdlib>
#include <random>
#include <ctime>// Library to generate random numbers
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

// Function to create a bank account
int login_verify(int account_number, const std::string &password) {
    //read from json file and 'see' if there is any account that matches password and account_number, if yes, calls menu function and passes object otherwise returns false
    try {
        Bank_Account account = Bank_Account::loadFromJson(account_number);
        if (account.getAccountPassword() == password) {
            return 1;
        } else {
            cout << "Invalid Account Number or Password.\n";
            return 0;
        }
    } catch (const std::exception &e) {
        cout << "Login failed: " << e.what() << endl;
        return 0;
    }
}

// Function to display the menu
void menu(int account_number) {
    int option;
    string new_name;
    Bank_Account account;
    // Load account from JSON
    try {
        account = Bank_Account::loadFromJson(account_number);
    } catch (const std::runtime_error &e) {
        cout << "Error loading account: " << e.what() << endl;
        return;
    }
    while (true) {
        cout << "Menu\n 1 - Deposit\n 2 - Withdraw\n 3 - Change Name \n 4 - Delete Account\n 0 - Exit\n";
        cin >> option;
        switch (option) {
            case 1:
                cout << "How much do you intend to deposit?.\n";
                double deposit_amount;
                while (!(cin >> deposit_amount)) {
                    cout << "Invalid input. Please enter a valid amount:\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                }
                account.deposit(deposit_amount);
                break;
            case 2:
                cout << "How much do you intend to withdraw?.\n";
                double withdraw_amount;
                while (!(cin >> withdraw_amount)) {
                    cout << "Invalid input. Please enter a valid amount:\n";
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                }
                account.withdraw(withdraw_amount);
                break;
            case 3:
                cout << "Enter new name:\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
                getline(cin, new_name); // Get the new name
                account.updateName(new_name, account_number);
                break;
            case 0:
                return;
            default:
                cout << "Invalid Option.\n";
                break;
        }
    }
}
// Function to generate a unique account number
int generateUniqueAccountNumber() {
        // Get current time as seed
        unsigned seed = static_cast<unsigned>(time(nullptr));

        // Use a proper random number generator
        mt19937 gen(seed);

        // Generate 5-digit account numbers (10000-99999)
        uniform_int_distribution<> dist(10000, 99999);

        int newAccountNumber = dist(gen);

        // You could check here if the account number already exists in your system
        // by trying to load an account with this number
        try {
            Bank_Account::loadFromJson(newAccountNumber);
            // If we get here, account exists, so recursively try again
            return generateUniqueAccountNumber();
        } catch (const std::runtime_error &) {
            // If we get an exception, account doesn't exist, so we can use this number
            return newAccountNumber;
        }
    }

void create_bank_account() {
    string name, address, password;
    int age, op = 0;
    double balance = 0.0;

    cout << "Name:\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, name); // Get the name

    cout << "Age:\n";
    while (!(cin >> age)) {
        cout << "Invalid input. Please enter a valid age:\n";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }
    if (age < 18) {
        cout << "You must be at least 18 years old to create an account.\n";
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer after reading age

    cout << "Address:\n";
    getline(cin, address); // Get the address

    cout << "Password:\n";
    getline(cin, password); // Get the password

    while (op != 1 && op != 2) {
        cout << "Do you want to add balance? \n Yes-1 No-2\n";
        while (!(cin >> op)) {
            cout << "Invalid input. Please enter 1 for Yes or 2 for No:\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (op == 1) {
            cout << "Add Balance:\n";
            while (!(cin >> balance)) {
                cout << "Invalid input. Please enter a valid balance:\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (op != 2 && op != 1) {
            cout << "Invalid option. Please enter 1 or 2.\n";
        }
    }

    // Generate unique account number
    int accountNumber = generateUniqueAccountNumber();

    // Create account with generated number
    Bank_Account account(accountNumber, balance, age, name, address, password);

    // Save account to JSON file
    account.saveToJson();

    cout << "\nAccount Created Successfully!\n";
    cout << "Your account number is: " << accountNumber << "\n";
    cout << "Please remember your account number for future transactions.\n\n";

    cout << "Account Details:\n";
    account.display(); // Display account details
}

int login() {
    string password;
    int account_number;
    cout << "Account Number:\n";
    while (!(cin >> account_number)) {
        cout << "Invalid input. Please enter a valid account number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Password:\n";
    getline(cin, password);

    if (login_verify(account_number, password)) {
        cout << "Login Successful!\n";
        menu(account_number);  // Pass the account number to the menu
        return 1;
    } else {
        cout << "Login failed.\n";
        return 0;
    }
}

void read_from_json() {
    std::ifstream file("accounts.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return;
    }

    try {
        json Doc;
        file >> Doc;

        // Example: Access fields
        for (const auto &account: Doc) {
            std::cout << "Name: " << account["name"] << std::endl;
            std::cout << "Account Number: " << account["account_number"] << std::endl;
            std::cout << "Account Balance: " << account["balance"] << std::endl;
        }
    } catch (const json::parse_error &e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }

    file.close();
}