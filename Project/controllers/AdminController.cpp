// controllers/AdminController.cpp
#include "AdminController.h"
#include <iostream>

using namespace std;

AdminController::AdminController() : repository("accounts.json"), admin("admin", "admin123") {}

bool AdminController::authenticateAdmin(const std::string &password) {
    return admin.authenticate(password);
}

void AdminController::runAdminMenu() {
    bool running = true;
    while (running) {
        view.showAdminMenu();
        int choice = view.getIntInput("");

        switch (choice) {
            case 1:
                viewAllAccounts();
                break;
            case 2:
                deleteUserAccount();
                break;
            case 3:
                updateUserAccount();
                break;
            case 0:
                running = false;
                view.showMessage("Returning to main menu.");
                break;
            default:
                view.showError("Invalid choice. Please try again.");
        }
    }
}

void AdminController::viewAllAccounts() {
    vector<BankAccount> accounts = repository.loadAllAccounts();
    view.showAllAccounts(accounts);
}

void AdminController::deleteUserAccount() {
    int accountNumber = view.getIntInput("Enter account number to delete: ");

    try {
        BankAccount account = repository.loadAccount(accountNumber);
        view.showAccountDetails(account);

        string confirmation = view.getStringInput("Type 'DELETE' to confirm deletion: ");
        if (confirmation == "DELETE") {
            if (repository.deleteAccount(accountNumber)) {
                view.showSuccess("Account deleted successfully.");
            } else {
                view.showError("Failed to delete account.");
            }
        } else {
            view.showMessage("Deletion cancelled.");
        }
    } catch (const runtime_error &e) {
        view.showError("Account not found.");
    }
}

void AdminController::updateUserAccount() {
    int accountNumber = view.getIntInput("Enter account number to update: ");

    try {
        BankAccount account = repository.loadAccount(accountNumber);
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

        repository.saveAccount(account);
        view.showSuccess("Account updated successfully!");
    } catch (const runtime_error &e) {
        view.showError("Account not found.");
    }
}
