#include "AdminController.h"
#include "AccountController.h"
#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

AdminController::AdminController() : repository("accounts.json") {}

bool AdminController::authenticateAdmin(const std::string &password) {
    // Simple authentication: checks if the password matches a hardcoded value
    return password == "admin123";
}

// Prompts the user for the admin password and authenticates
bool AdminController::authenticateAdmin() {
    std::string password;
    std::cout << "Enter admin password: ";
    std::cin >> password;
    if (password == "admin123") {
        std::cout << "Authentication successful.\n";
        return true;
    } else {
        std::cout << "Authentication failed.\n";
        return false;
    }
}

void AdminController::updateUserAccount() {
    int account_number;
    cout << "Enter the account number to update:\n";
    while (!(cin >> account_number)) {
        cout << "Invalid input. Please enter a valid account number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    try {
        BankAccount account = repository.loadAccount(account_number);
        AccountController accountController;
        accountController.updateAccountInfo(account);
        repository.saveAccount(account);
        cout << "Account information updated successfully.\n";
    } catch (const std::exception& e) {
        cout << "Account not found or error updating: " << e.what() << endl;
    }
}

void AdminController::viewAllAccounts() {
    ifstream file("accounts.json");
    if (!file.is_open()) {
        cerr << "Failed to open file!" << endl;
        return;
    }

    try {
        json Doc;
        file >> Doc;

        for (const auto &account: Doc) {
            cout << "Name: " << account["name"] << endl;
            cout << "Account Number: " << account["account_number"] << endl;
            cout << "Account Balance: " << account["balance"] << endl;
        }
    } catch (const json::parse_error &e) {
        cerr << "JSON parse error: " << e.what() << endl;
    }

    file.close();
}

void AdminController::deleteUserAccount() {
    int account_number;
    cout << "Enter the account number to delete:\n";
    while (!(cin >> account_number)) {
        cout << "Invalid input. Please enter a valid account number:\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ifstream file_in("accounts.json");
    if (!file_in.is_open()) {
        cout << "Failed to open accounts.json!\n";
        return;
    }
    json accounts;
    try {
        file_in >> accounts;
    } catch (const json::parse_error &e) {
        cout << "JSON parse error: " << e.what() << endl;
        file_in.close();
        return;
    }
    file_in.close();

    bool found = false;
    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if ((*it)["account_number"] == account_number) {
            accounts.erase(it);
            found = true;
            break;
        }
    }

    if (found) {
        ofstream file_out("accounts.json");
        if (!file_out.is_open()) {
            cout << "Failed to write to accounts.json!\n";
            return;
        }
        file_out << accounts.dump(4);
        file_out.close();
        cout << "Account deleted successfully.\n";
    } else {
        cout << "Account not found.\n";
    }
}

void AdminController::runAdminMenu() {
    bool running = true;
    while (running) {
        cout << "Admin Area\n";
        cout << "1 - View All Accounts\n";
        cout << "2 - Delete Account\n";
        cout << "3 - Update Accounts\n";
        cout << "0 - Exit\n";

        int option;
        cin >> option;
        switch (option) {
            case 1:
                viewAllAccounts();
                break;
            case 2:
                deleteUserAccount();
                break;
            case 3:
                updateUserAccount();
                break;
            case 0:
                running = false;
                return;
            default:
                cout << "Invalid Option.\n";
                break;
        }
    }
}