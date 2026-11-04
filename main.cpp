#include "ATM.h"
#include <iostream>
#include <limits>

int main() {
    Client client1(1, "Айдос Нұрлан", "4400123412345678", "1234");
    Client client2(2, "Меруерт Ерлан", "4400987612345678", "4321");

    Bank bank;
    bank.addClient(&client1);
    bank.addClient(&client2);

    bank.openAccount(1001, 1, 50000.0);
    bank.openAccount(1002, 2, 75000.0);

    ATM atm(bank);

    std::cout << "========== ATM BANK ==========" << '\n';
    bank.showClients();

    std::string pin;
    std::cout << "\n" << client1.getFullName() << ", PIN енгізіңіз: ";
    std::cin >> pin;

    if (!atm.authenticate(client1, pin)) {
        std::cout << "PIN қате. Қолжетімділік берілмеді.\n";
        return 0;
    }

    std::cout << "\nСәлеметсіз бе, " << client1.getFullName() << "!\n";
    Account* account = bank.findAccount(1001);
    if (account != nullptr) printAccountDetails(*account);

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n1. Ақшаны толықтыру\n"
                  << "2. Ақша шешу\n"
                  << "3. Балансты көру\n"
                  << "4. Операциялар журналын көру\n"
                  << "0. Шығу\n"
                  << "Таңдау: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Қате енгізу. Қайта көріңіз.\n";
            continue;
        }

        if (choice == 1 || choice == 2) {
            double amount;
            std::cout << "Соманы енгізіңіз (KZT): ";
            if (!(std::cin >> amount)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Сома дұрыс енгізілмеді.\n";
                continue;
            }
            if (choice == 1) {
                Deposit transaction(amount);
                std::cout << (atm.performTransaction(1001, transaction)
                    ? "Ақша толықтырылды.\n" : "Операция орындалмады.\n");
            } else {
                Withdrawal transaction(amount);
                std::cout << (atm.performTransaction(1001, transaction)
                    ? "Ақша шешілді.\n" : "Қаражат жеткіліксіз немесе сома қате.\n");
            }
        } else if (choice == 3) {
            account = bank.findAccount(1001);
            if (account != nullptr) printAccountDetails(*account);
        } else if (choice == 4) {
            atm.showLog();
        } else if (choice != 0) {
            std::cout << "Мәзірде мұндай таңдау жоқ.\n";
        }
    }

    std::cout << "\nБағдарлама аяқталды.\n";
    std::cout << "Шоттар саны: " << Account::getTotalAccounts() << '\n';
    std::cout << "Құрылған операциялар саны: " << Transaction::getTransactionCount() << '\n';
    return 0;
}
