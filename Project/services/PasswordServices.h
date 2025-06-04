// services/PasswordService.h
#ifndef PASSWORD_SERVICE_H
#define PASSWORD_SERVICE_H

#include <string>

class PasswordService {
public:
    // Password validation
    static bool isValidPassword(const std::string &password);

    static std::string getPasswordRequirements();

    // Password hashing (SHA-256)
    static std::string hashPassword(const std::string &password);

    static bool verifyPassword(const std::string &inputPassword, const std::string &hashedPassword);

private:
    static bool hasUppercase(const std::string &password);

    static bool hasLowercase(const std::string &password);

    static bool hasDigit(const std::string &password);

    static bool hasSpecialChar(const std::string &password);
};

#endif // PASSWORD_SERVICE_H