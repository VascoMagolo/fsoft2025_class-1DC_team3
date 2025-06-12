// models/Admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin {
private:
    std::string name;
    std::string password;

public:
    // Constructors
    Admin();
    Admin(const std::string &name, const std::string &password);

    // Getters
    std::string getName() const { return name; }
    std::string getPassword() const { return password; }

    // Admin-specific operations
    bool authenticate(const std::string &inputPassword) const;
};

#endif // ADMIN_H