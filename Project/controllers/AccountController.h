// controllers/AccountController.h
#ifndef ACCOUNT_CONTROLLER_H
#define ACCOUNT_CONTROLLER_H

#include "../models/BankAccount.h"
#include "../views/ConsoleView.h"
#include "../data/AccountRepository.h"

class AccountController {
private:
    ConsoleView view;
    AccountRepository repository;

public:
    AccountController();

    // Main operations
    void createAccount();

    bool authenticateUser(int accountNumber, const std::string &password, BankAccount &account);
    void runAccountMenu(BankAccount &account);

    // Account operations
    void processDeposit(BankAccount &account);
    void processWithdrawal(BankAccount &account);
    void updateAccountInfo(BankAccount &account);
    void showAccountDetails(const BankAccount &account);
    void generateReceipt(const BankAccount &account);
    void deleteAccount(BankAccount &account);
};

#endif // ACCOUNT_CONTROLLER_H