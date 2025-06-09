// views/ReceiptView.h
#ifndef RECEIPT_VIEW_H
#define RECEIPT_VIEW_H

#include "../models/BankAccount.h"
#include <string>

class ReceiptView {
public:
    void printBalanceReceipt(const BankAccount &account) const;

    void printTransactionReceipt(const BankAccount &account, const std::string &transactionType,
                                 double amount, double oldBalance) const;

    std::string generateReceiptString(const BankAccount &account);
};

#endif // RECEIPT_VIEW_H