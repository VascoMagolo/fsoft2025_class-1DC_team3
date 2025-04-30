// Classes implementation file
#include "classes.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Bank_Account::Bank_Account() = default; // Default constructor
Bank_Account::Bank_Account(int account_number, double balance, int age, string name, string address, string password)
        : account_number(account_number), balance(balance), password(password) {} // Constructor with parameters

void Bank_Account::deposit(double amount) {
    balance += amount;
} // Function to deposit money later implemented in the main.cpp on menu

void Bank_Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Insufficient funds" << std::endl;
    }
} // Function to withdraw money later implemented in the main.cpp on menu

void Bank_Account::display() const {
    std::cout << "Account Number: " << account_number << "\nBalance: " << balance << std::endl;
} // Function to display the account number and balance

void Bank_Account::saveBalanceToFile(int acc_number) { // Function to save the account balance to a file
    if (acc_number != this->account_number) {
        cout << "Invalid account number.\n";
        return;
    } // Open file only if the account number matches

    // Open file only if the account number matches
    ofstream file("account_balance.txt", ios::app); // Append mode
    if (!file) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    } // Check if file was opened successfully

    file << "Account Number: " << account_number << "\nBalance: " << balance << "\n\n";
    file.close(); // Close the file

    // Check if file exists
    ifstream file2("account_balance.txt");
    if (file2) { // Check if file was created
        cout << "File created successfully.\n";
        cout << "Account balance saved in account_balance.txt\n";
    } else {
        cout << "Error: File was not created.\n";
    }
    file2.close();
}