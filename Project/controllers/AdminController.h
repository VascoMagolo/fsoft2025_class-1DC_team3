// controllers/AdminController.h
#ifndef ADMIN_CONTROLLER_H
#define ADMIN_CONTROLLER_H

#include "../models/Admin.h"
#include "../views/ConsoleView.h"
#include "../data/AccountRepository.h"

class AdminController {
private:
    ConsoleView view;
    AccountRepository repository;

public:
    AdminController();

    // Admin operations
    bool authenticateAdmin(const std::string &password);
    bool authenticateAdmin();

    void runAdminMenu();

    void viewAllAccounts();

    void deleteUserAccount();

    void updateUserAccount();
};

#endif // ADMIN_CONTROLLER_H