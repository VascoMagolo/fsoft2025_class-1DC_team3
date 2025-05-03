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

    void updateName(const std::string &new_name, int acc_number);

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

    std::string getAccountPassword() const { return password; }

    double getBalance() const { return balance; }

    std::string getName() const { return name; }

    // JSON serialization/deserialization
    json toJson() const;

    static Bank_Account fromJson(const json &j);
};

class Admin {
private:
    std::string name;
    std::string password;
public:
    // Constructors
    Admin();

    Admin(const std::string &name, const std::string &password);

    void display() const;

    // Add more admin-specific methods if needed
};

#endif // CLASSES_H