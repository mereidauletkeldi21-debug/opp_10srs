#ifndef ATM_H
#define ATM_H

#include "Bank.h"
#include "Transaction.h"
#include "TransactionLog.h"
#include <string>

class ATM {
private:
    Bank& bank_;
    TransactionLog log_;

public:
    explicit ATM(Bank& bank);
    bool authenticate(const Client& client, const std::string& pin) const;
    bool performTransaction(int accountNumber, Transaction& transaction);
    void showLog() const;
};

#endif
