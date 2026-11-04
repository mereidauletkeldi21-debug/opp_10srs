#include "ATM.h"
#include <sstream>
#include <iomanip>

ATM::ATM(Bank& bank) : bank_(bank) {}

bool ATM::authenticate(const Client& client, const std::string& pin) const {
    return client.authenticate(pin);
}

bool ATM::performTransaction(int accountNumber, Transaction& transaction) {
    Account* account = bank_.findAccount(accountNumber);
    if (account == nullptr) {
        log_.addRecord("Ошибка: счёт " + std::to_string(accountNumber) + " не найден.");
        return false;
    }

    const bool success = transaction.execute(*account);
    std::ostringstream line;
    line << "Операция #" << transaction.getId() << " | " << transaction.getType()
         << " | Счёт: " << accountNumber << " | Сумма: "
         << std::fixed << std::setprecision(2) << transaction.getAmount()
         << " KZT | " << (success ? "Успешно" : "Отклонено");
    log_.addRecord(line.str());
    return success;
}

void ATM::showLog() const { log_.show(); }
