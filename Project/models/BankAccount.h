// models/BankAccount.h
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class BankAccount {
private:
    int accountNumber;
    double balance;
    int age;
    std::string name;
    std::string address;
    std::string password;

public:
    // Constructors
    BankAccount();
    BankAccount(int accountNumber, double balance, int age, const std::string &name,
                const std::string &address, const std::string &password);

    // Account operations (business logic)
    bool deposit(double amount);
    bool withdraw(double amount);

    // Getters
    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    int getAge() const { return age; }
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getPassword() const { return password; }

    // Setters
    void updateName(const std::string &newName) { name = newName; }

    void updateAddress(const std::string &newAddress) { address = newAddress; }

    void updateAge(int newAge) { age = newAge; }

    void updatePassword(const std::string &newPassword) { password = newPassword; }

    // JSON serialization
    json toJson() const;
    static BankAccount fromJson(const json &j);
};

#endif // BANK_ACCOUNT_H