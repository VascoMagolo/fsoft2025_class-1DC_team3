// views/ConsoleView.h
#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>
#include <vector>

#include "../models/BankAccount.h"
#include "../services/PasswordServices.h"

class ConsoleView {
 public:
  // Menu displays
  void showMainMenu() const;
  void showAccountMenu() const;
  void showAdminMenu() const;
  void updateAccountMenu() const;

  // Input methods
  int getIntInput(const std::string &prompt) const;
  double getDoubleInput(const std::string &prompt) const;
  std::string getStringInput(const std::string &prompt) const;
  std::string getPasswordInput(const std::string &prompt) const;

  // Display methods
  void showAccountDetails(const BankAccount &account) const;
  void showAllAccounts(const std::vector<BankAccount> &accounts) const;
  void showMessage(const std::string &message) const;
  void showError(const std::string &error) const;
  void showSuccess(const std::string &message) const;

  // Account creation form
  BankAccount getAccountCreationData(int accountNumber) const;

  // Update forms
  std::string getNewName() const;
  std::string getNewAddress() const;
  int getNewAge() const;
  std::string getNewPassword() const;
};

#endif  // CONSOLE_VIEW_H
