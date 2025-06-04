#include "BankAccount.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructors
BankAccount::BankAccount()
        : accountNumber(0), balance(0.0), age(0), name(""), address(""), password("") {}

BankAccount::BankAccount(int accountNumber, double balance, int age, const string &name,
                         const string &address, const string &password)
        : accountNumber(accountNumber), balance(balance), age(age),
          name(name), address(address), password(password) {}

// Account operations
bool BankAccount::deposit(double amount) {
    if (amount <= 0) {
        cerr << "Deposit amount must be positive" << endl;
        return false;
    }

    balance += amount;
    cout << "Successfully deposited $" << amount << ". New balance: $" << balance << endl;
    return true;
}

bool BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        cerr << "Withdrawal amount must be positive" << endl;
        return false;
    }

    if (amount > balance) {
        cerr << "Insufficient funds. Current balance: $" << balance << endl;
        return false;
    }

    balance -= amount;
    cout << "Successfully withdrew $" << amount << ". New balance: $" << balance << endl;
    return true;
}

// JSON serialization
json BankAccount::toJson() const {
    return json{
            {"account_number", accountNumber},
            {"balance",        balance},
            {"age",            age},
            {"name",           name},
            {"address",        address},
            {"password",       password}
    };
}

BankAccount BankAccount::fromJson(const json &j) {
    try {
        return BankAccount(
                j.at("account_number").get<int>(),
                j.at("balance").get<double>(),
                j.at("age").get<int>(),
                j.at("name").get<string>(),
                j.at("address").get<string>(),
                j.at("password").get<string>()
        );
    } catch (const json::exception &e) {
        throw runtime_error("Failed to parse BankAccount from JSON: " + string(e.what()));
    }
}