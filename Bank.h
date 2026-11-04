#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include "Client.h"
#include <vector>

class Bank {
private:
    static const int MAX_ACCOUNTS = 10;
    Account accounts_[MAX_ACCOUNTS];
    int accountCount_;
    std::vector<Client*> clients_;

public:
    Bank();
    void addClient(Client* client);
    bool openAccount(int accountNumber, int ownerId, double initialBalance);
    Account* findAccount(int accountNumber);
    const Account* findAccount(int accountNumber) const;
    void showClients() const;
    int getAccountCount() const;
};

#endif
