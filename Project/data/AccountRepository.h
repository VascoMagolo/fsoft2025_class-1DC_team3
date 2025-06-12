// data/AccountRepository.h
#ifndef ACCOUNT_REPOSITORY_H
#define ACCOUNT_REPOSITORY_H

#include "../models/BankAccount.h"
#include <vector>
#include <string>

class AccountRepository {
private:
    std::string accountsFile;

public:
    AccountRepository(const std::string &filename = "accounts.json");

    // Account operations
    bool saveAccount(const BankAccount &account);
    BankAccount loadAccount(int accountNumber);
    std::vector<BankAccount> loadAllAccounts();
    bool deleteAccount(int accountNumber);
    bool accountExists(int accountNumber);

    // Utility functions
    int generateUniqueAccountNumber();

private:
    bool saveAllAccounts(const std::vector<BankAccount> &accounts);
};

#endif // ACCOUNT_REPOSITORY_H