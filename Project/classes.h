// classes.h
#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Bank_Account {
private:
    int account_number;
    double balance;
    int age;
    std::string name;
    std::string address;
    std::string password;

public:
    // Constructors
    Bank_Account();

    Bank_Account(int account_number, double balance, int age, const std::string &name,
                 const std::string &address, const std::string &password);

    // Account operations
    void deposit(double amount);

    void withdraw(double amount);

    void display() const;

    // File operations
    void saveBalanceToFile(int acc_number);

    // JSON operations
    void saveToJson();

    static void saveToJson(int account_number, double balance, int age,
                           const std::string &name, const std::string &address,
                           const std::string &password);

    static Bank_Account loadFromJson(int account_number);

    static std::vector<Bank_Account> loadAllAccounts();

    // Getters
    int getAccountNumber() const { return account_number; }

    double getBalance() const { return balance; }

    std::string getName() const { return name; }

    // JSON serialization/deserialization
    json toJson() const;

    static Bank_Account fromJson(const json &j);
};

#endif // CLASSES_H