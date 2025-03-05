#include <iostream>
#include "Bank_Account.h"

int main() {
    Bank_Account account(12345, 1000);
    account.deposit(500);
    account.withdraw(200);
    account.display();
    return 0;
}