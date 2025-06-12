// models/Admin.cpp
#include "Admin.h"

using namespace std;

Admin::Admin() : name("admin"), password("admin123") {}

Admin::Admin(const std::string &name, const std::string &password)
        : name(name), password(password) {}

bool Admin::authenticate(const std::string &inputPassword) const {
    return inputPassword == password;
}
