// controllers/AccountController.cpp
#include "AccountController.h"
#include <iostream>
#include <iomanip>

using namespace std;

AccountController::AccountController() : repository("accounts.json") {}

void AccountController::createAccount() {
    int accountNumber = repository.generateUniqueAccountNumber();
    BankAccount newAccount = view.getAccountCreationData(accountNumber);

    if (repository.saveAccount(newAccount)) {
        view.showSuccess("Account created successfully!");
        cout << "Your account number is: " << accountNumber << "\n";
        cout << "Please remember this number for future logins.\n";
    } else {
        view.showError("Failed to create account. Please try again.");
    }
}

bool AccountController::authenticateUser(int accountNumber, const std::string &password, BankAccount &account) {
    try {
        account = repository.loadAccount(accountNumber);
        if (account.getPassword() == password) {
            return true;
        } else {
            view.showError("Invalid password.");
            return false;
        }
    } catch (const std::runtime_error &e) {
        view.showError("Account not found.");
        return false;
    }
}

void AccountController::runAccountMenu(BankAccount &account) {
    bool running = true;
    while (running) {
        view.showAccountMenu();
        int choice = view.getIntInput("");

        switch (choice) {
            case 1:
                processDeposit(account);
                break;
            case 2:
                processWithdrawal(account);
                break;
            case 3:
                updateAccountInfo(account);
                break;
            case 4:
                showAccountDetails(account);
                break;
            case 5:
                generateReceipt(account);
                break;
            case 6:
                deleteAccount(account);
                running = false;
                break;
            case 0:
                running = false;
                view.showMessage("Logged out successfully.");
                break;
            default:
                view.showError("Invalid choice. Please try again.");
        }
    }
}

void AccountController::processDeposit(BankAccount &account) {
    double amount = view.getDoubleInput("Enter deposit amount: $");
    if (amount <= 0) {
        view.showError("Deposit amount must be positive.");
        return;
    }

    if (account.deposit(amount)) {
        repository.saveAccount(account);
        view.showSuccess("Deposit successful!");
        cout << "New balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    } else {
        view.showError("Deposit failed.");
    }
}

void AccountController::processWithdrawal(BankAccount &account) {
    double amount = view.getDoubleInput("Enter withdrawal amount: $");
    if (amount <= 0) {
        view.showError("Withdrawal amount must be positive.");
        return;
    }

    if (account.withdraw(amount)) {
        repository.saveAccount(account);
        view.showSuccess("Withdrawal successful!");
        cout << "New balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    } else {
        view.showError("Withdrawal failed.");
    }
}

void AccountController::updateAccountInfo(BankAccount &account) {
    view.showAccountDetails(account);

    string newName = view.getNewName();
    if (!newName.empty()) {
        account.updateName(newName);
    }

    string newAddress = view.getNewAddress();
    if (!newAddress.empty()) {
        account.updateAddress(newAddress);
    }

    int newAge = view.getNewAge();
    if (newAge > 0) {
        account.updateAge(newAge);
    }

    string newPassword = view.getNewPassword();
    if (!newPassword.empty()) {
        account.updatePassword(newPassword);
    }

    repository.saveAccount(account);
    view.showSuccess("Account information updated successfully!");
}

void AccountController::showAccountDetails(const BankAccount &account) {
    view.showAccountDetails(account);
}

void AccountController::generateReceipt(const BankAccount &account) {
    cout << "\n=== Account Receipt ===\n";
    cout << "Account Number: " << account.getAccountNumber() << "\n";
    cout << "Name: " << account.getName() << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    cout << "========================\n";
}

void AccountController::deleteAccount(BankAccount &account) {
    cout << "Are you sure you want to delete your account? This action cannot be undone.\n";
    string confirmation = view.getStringInput("Type 'DELETE' to confirm: ");

    if (confirmation == "DELETE") {
        if (repository.deleteAccount(account.getAccountNumber())) {
            view.showSuccess("Account deleted successfully.");
        } else {
            view.showError("Failed to delete account.");
        }
    } else {
        view.showMessage("Account deletion cancelled.");
    }
}
