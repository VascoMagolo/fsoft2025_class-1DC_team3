// views/ConsoleView.cpp
#include "ConsoleView.h"

#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

void ConsoleView::showMainMenu() const {
  cout << "\n=== Bank Account Management System ===\n";
  cout << "1. Create Account\n";
  cout << "2. Login to Account\n";
  cout << "3. Admin Area\n";
  cout << "0. Exit\n";
  cout << "Choose an option: ";
}

void ConsoleView::showAccountMenu() const {
  cout << "\n=== Account Menu ===\n";
  cout << "1. Deposit\n";
  cout << "2. Withdraw\n";
  cout << "3. Update Account Info\n";
  cout << "4. View Account Details\n";
  cout << "5. Generate Receipt\n";
  cout << "6. Delete Account\n";
  cout << "0. Logout\n";
  cout << "Choose an option: ";
}

void ConsoleView::showAdminMenu() const {
  cout << "\n=== Admin Menu ===\n";
  cout << "1. View All Accounts\n";
  cout << "2. Delete User Account\n";
  cout << "3. Update User Account\n";
  cout << "0. Back to Main Menu\n";
  cout << "Choose an option: ";
}

void ConsoleView::updateAccountMenu() const {
  cout << "\n=== Update Account Info ===\n";
  cout << "1. Update Name\n";
  cout << "2. Update Address\n";
  cout << "3. Update Age\n";
  cout << "4. Update Password\n";
  cout << "0. Back to Account Menu\n";
}

int ConsoleView::getIntInput(const std::string &prompt) const {
  int value;
  cout << prompt;
  while (!(cin >> value)) {
    cout << "Invalid input. Please enter a valid integer: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return value;
}

double ConsoleView::getDoubleInput(const std::string &prompt) const {
  double value;
  cout << prompt;
  while (!(cin >> value) || value < 0) {
    cout << "Invalid input. Please enter a valid positive number: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return value;
}

std::string ConsoleView::getStringInput(const std::string &prompt) const {
  string value;
  cout << prompt;
  getline(cin, value);
  return value;
}

std::string ConsoleView::getPasswordInput(const std::string &prompt) const {
  std::string password;
  do {
    password = getStringInput(prompt);
    if (!PasswordService::isValidPassword(password)) {
      std::cout << PasswordService::getPasswordRequirements() << std::endl;
      std::cout << "Please try again.\n";
    }
  } while (!PasswordService::isValidPassword(password));

  // Return plain password - don't hash here
  return password;
}

void ConsoleView::showAccountDetails(const BankAccount &account) const {
  cout << "\n=== Account Details ===\n";
  cout << "Account Number: " << account.getAccountNumber() << "\n";
  cout << "Name: " << account.getName() << "\n";
  cout << "Age: " << account.getAge() << "\n";
  cout << "Address: " << account.getAddress() << "\n";
  cout << "Balance: $" << fixed << setprecision(2) << account.getBalance()
       << "\n";
  cout << "========================\n";
}

void ConsoleView::showAllAccounts(
    const std::vector<BankAccount> &accounts) const {
  cout << "\n=== All Accounts ===\n";
  if (accounts.empty()) {
    cout << "No accounts found.\n";
    return;
  }

  for (const auto &account : accounts) {
    cout << "Account #" << account.getAccountNumber()
         << " | Name: " << account.getName() << " | Balance: $" << fixed
         << setprecision(2) << account.getBalance() << "\n";
  }
  cout << "====================\n";
}

void ConsoleView::showMessage(const std::string &message) const {
  cout << message << "\n";
}

void ConsoleView::showError(const std::string &error) const {
  cerr << "Error: " << error << "\n";
}

void ConsoleView::showSuccess(const std::string &message) const {
  cout << "Success: " << message << "\n";
}

BankAccount ConsoleView::getAccountCreationData(int accountNumber) const {
  cout << "\n=== Create New Account ===\n";

  string name = getStringInput("Enter your full name: ");
  int age = getIntInput("Enter your age: ");
  while (age < 18) {
    cout << "You must be at least 18 years old to create an account.\n";
    age = getIntInput("Enter your age: ");
  }

  string address = getStringInput("Enter your address: ");
  string password = getPasswordInput("Create a password: ");

  // Hash the password before creating the account
  string hashedPassword = PasswordService::hashPassword(password);

  double initialBalance =
      getDoubleInput("Enter initial deposit (minimum $0): ");

  return BankAccount(accountNumber, initialBalance, age, name, address,
                     hashedPassword);
}

std::string ConsoleView::getNewName() const {
  return getStringInput("Enter new name (or press Enter to keep current): ");
}

std::string ConsoleView::getNewAddress() const {
  return getStringInput("Enter new address (or press Enter to keep current): ");
}

int ConsoleView::getNewAge() const {
  int age = getIntInput("Enter new age (or 0 to keep current): ");
  if (age != 0 && age < 18) {
    cout << "Age must be at least 18. Keeping current age.\n";
    return 0;
  }
  return age;
}

std::string ConsoleView::getNewPassword() const {
  std::string password =
      getStringInput("Enter new password (or press Enter to keep current): ");
  if (password.empty()) {
    return password;  // Keep current password
  }

  // Validate the password
  if (!PasswordService::isValidPassword(password)) {
    std::cout << PasswordService::getPasswordRequirements() << std::endl;
    return "";  // Return empty to keep current password
  }

  // Hash before returning
  return PasswordService::hashPassword(password);
}
