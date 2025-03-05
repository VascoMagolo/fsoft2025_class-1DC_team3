// Bank_Account.cpp
#include "Bank_Account.h"
#include <iostream>

Bank_Account::Bank_Account(int account_number, double balance) : account_number(account_number), balance(balance) {}

void Bank_Account::deposit(double amount) {
    balance += amount;
}

void Bank_Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cerr << "Insufficient funds" << std::endl;
    }
}

void Bank_Account::display() const {
    std::cout << "Account Number: " << account_number << "\nBalance: " << balance << std::endl;
}