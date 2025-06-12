#include "ConsoleView.h"
#include <iostream>
#include <limits>
#include <iomanip>
#include "../external_functions/functions.h"
using namespace std;

void ConsoleView::showMainMenu() const {
    cout << "Main Menu:\n";
    cout << "1. Create Account\n";
    cout << "2. View Account\n";
    cout << "3. Exit\n";
}

void ConsoleView::showAccountMenu() const {
    cout << "Account Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. View Balance\n";
    cout << "4. Update Account Details\n";
    cout << "5. Back to Main Menu\n";
}

void ConsoleView::showAdminMenu() const {
    cout << "Admin Menu:\n";
    cout << "1. View All Accounts\n";
    cout << "2. Delete Account\n";
    cout << "3. Back to Main Menu\n";
}

int ConsoleView::getIntInput(const std::string &prompt) const {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid integer:\n";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    return value;
}

double ConsoleView::getDoubleInput(const std::string &prompt) const {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cout << "Invalid input. Please enter a valid number:\n";
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character
    return value;
}

std::string ConsoleView::getStringInput(const std::string &prompt) const {
    string value;
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, value); // Get the string input
    return value;
}

std::string ConsoleView::getPasswordInput(const std::string &prompt) const {
    string password;
    cout << prompt;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
    getline(cin, password); // Get the password input
    return password;
}

void ConsoleView::showAccountDetails(const BankAccount &account) const {
    cout << "Account Details:\n";
    cout << "Account Number: " << account.getAccountNumber() << "\n";
    cout << "Name: " << account.getName() << "\n";
    cout << "Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
}

void ConsoleView::showAllAccounts(const std::vector<BankAccount> &accounts) const {
    cout << "All Accounts:\n";
    for (const auto &account: accounts) {
        cout << "Account Number: " << account.getAccountNumber() << ", Name: " << account.getName()
             << ", Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    }
}

void ConsoleView::showMessage(const std::string &message) const {
    cout << message << "\n";
}

void ConsoleView::showError(const std::string &error) const {
    cerr << "Error: " << error << "\n";
}

void ConsoleView::showSuccess(const std::string &message) const {
    cout << "Success: " << message << "\n";
}

BankAccount ConsoleView::getAccountCreationData() const {
    string name = getStringInput("Enter your name: ");
    int age = getIntInput("Enter your age: ");
    string address = getStringInput("Enter your address: ");
    string password = getPasswordInput("Enter your password: ");
    double initialBalance = getDoubleInput("Enter initial balance (0 if none): ");

    return BankAccount(generateUniqueAccountNumber(), initialBalance, age, name, address, password);
}

std::string ConsoleView::getNewName() const {
    return getStringInput("Enter new name: ");
}

std::string ConsoleView::getNewAddress() const {
    return getStringInput("Enter new address: ");
}

int ConsoleView::getNewAge() const {
    return getIntInput("Enter new age: ");
}

std::string ConsoleView::getNewPassword() const {
    return getPasswordInput("Enter new password: ");
}


