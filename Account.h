#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Bank;
class Account;
void printAccountDetails(const Account& account);

class Account {
private:
    int accountNumber_;
    int ownerId_;
    double balance_;
    static int totalAccounts_;

    friend class Bank;
    friend void printAccountDetails(const Account& account);

public:
    Account();
    Account(int accountNumber, int ownerId, double initialBalance);
    int getAccountNumber() const;
    int getOwnerId() const;
    double getBalance() const;
    bool deposit(double amount);
    bool withdraw(double amount);
    static int getTotalAccounts();
};

#endif
