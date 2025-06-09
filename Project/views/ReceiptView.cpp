#include "ReceiptView.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

void ReceiptView::printBalanceReceipt(const BankAccount &account) const {
    cout << "Balance Receipt\n";
    cout << "----------------\n";
    cout << "Account Number: " << account.getAccountNumber() << "\n";
    cout << "Name: " << account.getName() << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    cout << "----------------\n";
}

void ReceiptView::printTransactionReceipt(const BankAccount &account, const string &transactionType,
                                          double amount, double oldBalance) const {
    cout << "Transaction Receipt\n";
    cout << "--------------------\n";
    cout << "Account Number: " << account.getAccountNumber() << "\n";
    cout << "Name: " << account.getName() << "\n";
    cout << "Transaction Type: " << transactionType << "\n";
    cout << "Amount: $" << fixed << setprecision(2) << amount << "\n";
    cout << "Old Balance: $" << fixed << setprecision(2) << oldBalance << "\n";
    cout << "New Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    cout << "--------------------\n";
}

std::string ReceiptView::generateReceiptString(const BankAccount &account) {
    stringstream ss;
    ss << "Receipt\n";
    ss << "----------------\n";
    ss << "Account Number: " << account.getAccountNumber() << "\n";
    ss << "Name: " << account.getName() << "\n";
    ss << "Current Balance: $" << fixed << setprecision(2) << account.getBalance() << "\n";
    ss << "----------------\n";

    return ss.str();
}