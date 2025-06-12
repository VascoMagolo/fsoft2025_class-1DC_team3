// controllers/MainController.cpp
#include "MainController.h"
#include <iostream>

using namespace std;

MainController::MainController() {}

void MainController::run() {
    view.showMessage("Welcome to the Bank Account Management System!");

    bool running = true;
    while (running) {
        view.showMainMenu();
        int choice = view.getIntInput("");

        switch (choice) {
            case 1:
                accountController.createAccount();
                break;
            case 2:
                handleLogin();
                break;
            case 3:
                handleAdminArea();
                break;
            case 0:
                running = false;
                view.showMessage("Thank you for using our banking system. Goodbye!");
                break;
            default:
                view.showError("Invalid choice. Please try again.");
        }
    }
}

void MainController::handleLogin() {
    int accountNumber = view.getIntInput("Enter your account number: ");
    string password = view.getPasswordInput("Enter your password: ");

    BankAccount account;
    if (accountController.authenticateUser(accountNumber, password, account)) {
        view.showSuccess("Login successful!");
        view.showMessage("Welcome, " + account.getName() + "!");
        accountController.runAccountMenu(account);
    } else {
        view.showError("Login failed.");
    }
}

void MainController::handleAdminArea() {
    string password = view.getPasswordInput("Enter admin password: ");

    if (adminController.authenticateAdmin(password)) {
        view.showSuccess("Admin login successful!");
        adminController.runAdminMenu();
    } else {
        view.showError("Invalid admin password.");
    }
}