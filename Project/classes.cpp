#include "classes.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Constructors
Bank_Account::Bank_Account() = default;

Bank_Account::Bank_Account(int account_number, double balance, int age, const string &name,
                           const string &address, const string &password)
        : account_number(account_number), balance(balance), age(age),
          name(name), address(address), password(password) {}

// Account operations
void Bank_Account::deposit(double amount) {
    balance += amount;
    // After modifying the balance, we could automatically save the changes
    saveToJson();
}

void Bank_Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        // After modifying the balance, we could automatically save the changes
        saveToJson();
    } else {
        std::cerr << "Insufficient funds" << std::endl;
    }
}

void Bank_Account::updateName(const std::string &new_name, int acc_number) {
    if (acc_number != this->account_number) {
        std::cerr << "Invalid account number." << std::endl;
        return;
    }
    name = new_name;
    std::cout << "Name updated successfully.\n";
    saveToJson();
}

void Bank_Account::display() const {
    std::cout << "Account Number: " << account_number << "\n"
              << "Name: " << name << "\n"
              << "Balance: $" << balance << "\n"
              << "Age: " << age << "\n"
              << "Address: " << address << std::endl;
}

// Legacy file operations
void Bank_Account::saveBalanceToFile(int acc_number) {
    if (acc_number != this->account_number) {
        cout << "Invalid account number.\n";
        return;
    }

    ofstream file("account_balance.txt", ios::app);
    if (!file) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }

    file << "Account Number: " << account_number << "\n"
         << "Name: " << name << "\n"
         << "Balance: " << balance << "\n\n";
    file.close();

    ifstream file2("account_balance.txt");
    if (file2) {
        cout << "File created successfully.\n";
        cout << "Account balance saved in account_balance.txt\n";
    } else {
        cout << "Error: File was not created.\n";
    }
    file2.close();

    // Also save to JSON for modern storage
    saveToJson();
}

// JSON operations
json Bank_Account::toJson() const {
    return {
            {"account_number", account_number},
            {"balance",        balance},
            {"age",            age},
            {"name",           name},
            {"address",        address},
            {"password",       password}
    };
}

Bank_Account Bank_Account::fromJson(const json &j) {
    return Bank_Account(
            j["account_number"].get<int>(),
            j["balance"].get<double>(),
            j["age"].get<int>(),
            j["name"].get<string>(),
            j["address"].get<string>(),
            j["password"].get<string>()
    );
}

void Bank_Account::saveToJson() {
    // Convert this account to JSON
    json accountJson = toJson();

    // Read existing data
    json allAccounts;
    std::ifstream readFile("accounts.json");
    if (readFile.is_open()) {
        try {
            if (readFile.peek() != std::ifstream::traits_type::eof()) {
                readFile >> allAccounts;
            }
        } catch (const json::parse_error &e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
            allAccounts = json::array();
        }
        readFile.close();
    }

    // If it's not an array yet, create one
    if (!allAccounts.is_array()) {
        allAccounts = json::array();
    }

    // Check if this account already exists in the array
    bool accountExists = false;
    for (auto &acc: allAccounts) {
        if (acc["account_number"] == account_number) {
            // Update existing account
            acc = accountJson;
            accountExists = true;
            break;
        }
    }

    // If account doesn't exist, add it
    if (!accountExists) {
        allAccounts.push_back(accountJson);
    }

    // Write back to file
    std::ofstream writeFile("accounts.json");
    if (!writeFile.is_open()) {
        std::cerr << "Failed to open accounts.json for writing!" << std::endl;
        return;
    }

    writeFile << allAccounts.dump(4);
    writeFile.close();
    cout << "Account saved to JSON successfully." << endl;
}

void Bank_Account::saveToJson(int account_number, double balance, int age,
                              const std::string &name, const std::string &address,
                              const std::string &password) {
    // Create temporary account and save it
    Bank_Account tempAccount(account_number, balance, age, name, address, password);
    tempAccount.saveToJson();
}

Bank_Account Bank_Account::loadFromJson(int account_number) {
    std::ifstream file("accounts.json");
    if (!file.is_open()) {
        throw std::runtime_error("Could not open accounts.json");
    }

    json allAccounts;
    try {
        file >> allAccounts;
    } catch (const json::parse_error &e) {
        throw std::runtime_error("Failed to parse accounts.json: " + std::string(e.what()));
    }

    file.close();

    // Find account with matching account number
    for (const auto &acc: allAccounts) {
        if (acc["account_number"] == account_number) {
            return fromJson(acc);
        }
    }

    throw std::runtime_error("Account not found");
}

std::vector<Bank_Account> Bank_Account::loadAllAccounts() {
    std::vector<Bank_Account> accounts;

    std::ifstream file("accounts.json");
    if (!file.is_open()) {
        std::cerr << "Could not open accounts.json" << std::endl;
        return accounts;
    }

    json allAccounts;
    try {
        if (file.peek() != std::ifstream::traits_type::eof()) {
            file >> allAccounts;

            for (const auto &acc: allAccounts) {
                accounts.push_back(fromJson(acc));
            }
        }
    } catch (const json::parse_error &e) {
        std::cerr << "Failed to parse accounts.json: " << e.what() << std::endl;
    }

    file.close();
    return accounts;
}


// Admin class methods
Admin::Admin() = default;

Admin::Admin(const std::string &name, const std::string &password)
        : name(name), password(password) {}

void Admin::display() const {
    std::cout << "Admin Name: " << name << "\n"
              << "Password: " << password << std::endl;
}