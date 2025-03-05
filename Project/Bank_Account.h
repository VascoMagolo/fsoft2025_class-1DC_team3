#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

class Bank_Account {
private:
    int account_number;
    double balance;

public:
    Bank_Account(int account_number, double initial_balance);
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};

#endif // BANK_ACCOUNT_H