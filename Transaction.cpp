#include "Transaction.h"

int Transaction::nextId_ = 1;
int Transaction::transactionCount_ = 0;

Transaction::Transaction(double amount) : id_(nextId_++), amount_(amount) {
    ++transactionCount_;
}

int Transaction::getId() const { return id_; }
double Transaction::getAmount() const { return amount_; }
int Transaction::getTransactionCount() { return transactionCount_; }

Deposit::Deposit(double amount) : Transaction(amount) {}
bool Deposit::execute(Account& account) { return account.deposit(amount_); }
std::string Deposit::getType() const { return "Пополнение"; }

Withdrawal::Withdrawal(double amount) : Transaction(amount) {}
bool Withdrawal::execute(Account& account) { return account.withdraw(amount_); }
std::string Withdrawal::getType() const { return "Снятие"; }
