#include "ConsoleView.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void ConsoleView::showMainMenu() const {
    cout << "Main Menu:\n";
    cout << "1. Create Account\n";
    cout << "2. View Account\n";
    cout << "3. Exit\n";
}

void ConsoleView::showAccountMenu() const {
    cout << "Account Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. View Balance\n";
    cout << "4. Update Account Details\n";
    cout << "5. Back to Main Menu\n";
}

void ConsoleView::showAdminMenu() const {
    cout << "Admin Menu:\n";
    cout << "1. View All Accounts\n";
    cout << "2. Delete Account\n";
    cout << "3. Back to Main Menu\n";
}

