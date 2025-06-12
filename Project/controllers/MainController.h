// controllers/MainController.h
#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "AccountController.h"
#include "AdminController.h"
#include "../views/ConsoleView.h"

class MainController {
private:
    ConsoleView view;
    AccountController accountController;
    AdminController adminController;

public:
    MainController();

    void run();

private:
    void handleLogin();

    void handleAdminArea();
};

#endif // MAIN_CONTROLLER_H
