#include "Account.h"
#include <iostream>

int Account::totalAccounts_ = 0;

Account::Account() : accountNumber_(0), ownerId_(0), balance_(0.0) {}

Account::Account(int accountNumber, int ownerId, double initialBalance)
    : accountNumber_(accountNumber), ownerId_(ownerId), balance_(initialBalance) {
    ++totalAccounts_;
}

int Account::getAccountNumber() const { return accountNumber_; }
int Account::getOwnerId() const { return ownerId_; }
double Account::getBalance() const { return balance_; }

bool Account::deposit(double amount) {
    if (amount <= 0) return false;
    balance_ += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (amount <= 0 || amount > balance_) return false;
    balance_ -= amount;
    return true;
}

int Account::getTotalAccounts() { return totalAccounts_; }

void printAccountDetails(const Account& account) {
    std::cout << "Шот нөмірі: " << account.accountNumber_
              << " | Иесінің ID нөмірі: " << account.ownerId_
              << " | Баланс: " << account.balance_ << " KZT\n";
}
