#include "Bank.h"
#include <iostream>

Bank::Bank() : accountCount_(0) {}

void Bank::addClient(Client* client) {
    if (client == nullptr) return;
    for (const Client* existing : clients_) {
        if (existing->getId() == client->getId()) return;
    }
    clients_.push_back(client);
}

bool Bank::openAccount(int accountNumber, int ownerId, double initialBalance) {
    if (accountCount_ >= MAX_ACCOUNTS || accountNumber <= 0 || initialBalance < 0)
        return false;

    bool ownerExists = false;
    for (const Client* client : clients_) {
        if (client->getId() == ownerId) ownerExists = true;
    }
    if (!ownerExists || findAccount(accountNumber) != nullptr) return false;

    accounts_[accountCount_].accountNumber_ = accountNumber;
    accounts_[accountCount_].ownerId_ = ownerId;
    accounts_[accountCount_].balance_ = initialBalance;
    ++Account::totalAccounts_;
    ++accountCount_;
    return true;
}

Account* Bank::findAccount(int accountNumber) {
    for (int i = 0; i < accountCount_; ++i)
        if (accounts_[i].getAccountNumber() == accountNumber) return &accounts_[i];
    return nullptr;
}

const Account* Bank::findAccount(int accountNumber) const {
    for (int i = 0; i < accountCount_; ++i)
        if (accounts_[i].getAccountNumber() == accountNumber) return &accounts_[i];
    return nullptr;
}

void Bank::showClients() const {
    std::cout << "\n--- Клиенты банка ---\n";
    for (const Client* client : clients_)
        std::cout << "ID: " << client->getId() << " | " << client->getFullName()
                  << " | Карта: " << client->getCardNumber() << '\n';
}

int Bank::getAccountCount() const { return accountCount_; }
