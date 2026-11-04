#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Account.h"
#include <string>

class Transaction {
protected:
    int id_;
    double amount_;
    static int nextId_;
    static int transactionCount_;

public:
    explicit Transaction(double amount);
    virtual ~Transaction() = default;
    virtual bool execute(Account& account) = 0;
    virtual std::string getType() const = 0;
    int getId() const;
    double getAmount() const;
    static int getTransactionCount();
};

class Deposit : public Transaction {
public:
    explicit Deposit(double amount);
    bool execute(Account& account) override;
    std::string getType() const override;
};

class Withdrawal : public Transaction {
public:
    explicit Withdrawal(double amount);
    bool execute(Account& account) override;
    std::string getType() const override;
};

#endif
