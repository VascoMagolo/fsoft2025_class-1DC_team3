#ifndef CLASSES_H
#define CLASSES_H

#include <string>

using namespace std;

class Bank_Account { // Class for the bank accounts
private: // Private members
    double balance{};
    string password;

public:
    Bank_Account(); // Default constructor
    Bank_Account(int account_number, double initial_balance, int age, string name, string address,
                 string password); // Constructor with parameters
    void deposit(double amount); // Function to deposit money later implemented in the main.cpp on menu
    void withdraw(double amount); // Function to withdraw money later implemented in the main.cpp on menu
    void display() const; // Function to display the account number and balance
    void saveBalanceToFile(int account_number); // Function to save the account balance to a file
    int account_number;
};

#endif // CLASSES_H