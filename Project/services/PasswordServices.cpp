//
// Created by vasco on 05/06/2025.
//

#include "PasswordServices.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

bool PasswordService::isValidPassword(const std::string &password) {
  // Check minimum length (at least 8 characters)
  if (password.length() < 8) {
    return false;
  }

  // Check all requirements
  return hasUppercase(password) && hasLowercase(password) &&
         hasDigit(password) && hasSpecialChar(password);
}

std::string PasswordService::getPasswordRequirements() {
  return "Password must contain:\n"
         "- At least 8 characters\n"
         "- At least 1 uppercase letter (A-Z)\n"
         "- At least 1 lowercase letter (a-z)\n"
         "- At least 1 digit (0-9)\n"
         "- At least 1 special character (._*!@#$%^&+=)";
}

std::string PasswordService::hashPassword(const std::string &password) {
  // Simple hash function using djb2 algorithm
  unsigned long hash = 5381;

  for (char c : password) {
    hash = ((hash << 5) + hash) + c;  // hash * 33 + c
  }

  // Convert to hex string
  std::stringstream ss;
  ss << std::hex << hash;

  return ss.str();
}

bool PasswordService::verifyPassword(const std::string &inputPassword,
                                     const std::string &hashedPassword) {
  return hashPassword(inputPassword) == hashedPassword;
}

bool PasswordService::hasUppercase(const std::string &password) {
  return std::any_of(password.begin(), password.end(),
                     [](char c) { return c >= 'A' && c <= 'Z'; });
}

bool PasswordService::hasLowercase(const std::string &password) {
  return std::any_of(password.begin(), password.end(),
                     [](char c) { return c >= 'a' && c <= 'z'; });
}

bool PasswordService::hasDigit(const std::string &password) {
  return std::any_of(password.begin(), password.end(),
                     [](char c) { return c >= '0' && c <= '9'; });
}

bool PasswordService::hasSpecialChar(const std::string &password) {
  const std::string specialChars = "._*!@#$%^&+=";
  return std::any_of(password.begin(), password.end(), [&specialChars](char c) {
    return specialChars.find(c) != std::string::npos;
  });
}