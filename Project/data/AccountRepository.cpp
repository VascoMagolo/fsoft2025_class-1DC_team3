// data/AccountRepository.cpp
#include "AccountRepository.h"
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

AccountRepository::AccountRepository(const std::string &filename) : accountsFile(filename) {}

bool AccountRepository::saveAccount(const BankAccount &account) {
    vector<BankAccount> accounts = loadAllAccounts();

    // Check if account already exists and update it
    bool found = false;
    for (auto &acc: accounts) {
        if (acc.getAccountNumber() == account.getAccountNumber()) {
            acc = account;
            found = true;
            break;
        }
    }

    // If not found, add new account
    if (!found) {
        accounts.push_back(account);
    }

    return saveAllAccounts(accounts);
}

BankAccount AccountRepository::loadAccount(int accountNumber) {
    vector<BankAccount> accounts = loadAllAccounts();

    for (const auto &account: accounts) {
        if (account.getAccountNumber() == accountNumber) {
            return account;
        }
    }

    throw runtime_error("Account not found");
}

std::vector<BankAccount> AccountRepository::loadAllAccounts() {
    vector<BankAccount> accounts;

    ifstream file(accountsFile);
    if (!file.is_open()) {
        return accounts; // Return empty vector if file doesn't exist
    }

    json allAccounts;
    try {
        if (file.peek() != ifstream::traits_type::eof()) {
            file >> allAccounts;

            for (const auto &acc: allAccounts) {
                accounts.push_back(BankAccount::fromJson(acc));
            }
        }
    } catch (const json::parse_error &e) {
        cerr << "Failed to parse accounts.json: " << e.what() << endl;
    }

    file.close();
    return accounts;
}

bool AccountRepository::deleteAccount(int accountNumber) {
    vector<BankAccount> accounts = loadAllAccounts();

    auto it = remove_if(accounts.begin(), accounts.end(),
                        [accountNumber](const BankAccount &acc) {
                            return acc.getAccountNumber() == accountNumber;
                        });

    if (it != accounts.end()) {
        accounts.erase(it, accounts.end());
        return saveAllAccounts(accounts);
    }

    return false;
}

bool AccountRepository::accountExists(int accountNumber) {
    try {
        loadAccount(accountNumber);
        return true;
    } catch (const runtime_error &) {
        return false;
    }
}

int AccountRepository::generateUniqueAccountNumber() {
    unsigned seed = static_cast<unsigned>(time(nullptr));
    mt19937 gen(seed);
    uniform_int_distribution<> dist(10000, 99999);

    int newAccountNumber;
    do {
        newAccountNumber = dist(gen);
    } while (accountExists(newAccountNumber));

    return newAccountNumber;
}

bool AccountRepository::saveAllAccounts(const std::vector<BankAccount> &accounts) {
    ofstream file(accountsFile);
    if (!file.is_open()) {
        cerr << "Failed to open " << accountsFile << " for writing!" << endl;
        return false;
    }

    json allAccounts = json::array();
    for (const auto &account: accounts) {
        allAccounts.push_back(account.toJson());
    }

    file << allAccounts.dump(4);
    file.close();
    return true;
}
