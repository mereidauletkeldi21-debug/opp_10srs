#include <iostream>
#include <string>
#include <locale>

#include "Klient.h"
#include "Esep.h"
#include "Bank.h"
#include "Bankomat.h"
#include "Operatsiya.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    cout << "====================================\n";
    cout << "          БАНКОМАТ ЖҮЙЕСІ\n";
    cout << "====================================\n";

    Klient klient1(
        1,
        "Айдос",
        "1234567890123456",
        "1234"
    );

    Klient klient2(
        2,
        "Мерей",
        "9876543210987654",
        "4321"
    );

    Esep esepter[2] = {
        Esep(1001, 150000),
        Esep(1002, 200000)
    };

    Bank bank;

    bank.klientKosu(&klient1);
    bank.klientKosu(&klient2);

    cout << "\nБанк жүйесіне клиенттер қосылды.\n";

    bank.klientterdiKorsetu();

    Bankomat bankomat(101);

    string pin;

    cout << "\nPIN кодты енгізіңіз: ";
    cin >> pin;

    if (!bankomat.kiru(klient1, pin)) {
        cout << "Жүйеге кіру мүмкін болмады.\n";
        return 0;
    }

    int tandau;
    double soma;

    do {
        cout << "\n====================================\n";
        cout << "             НЕГІЗГІ МӘЗІР\n";
        cout << "====================================\n";

        cout << "1. Балансты тексеру\n";
        cout << "2. Шотқа ақша салу\n";
        cout << "3. Шоттан ақша шешу\n";
        cout << "4. Операциялар тарихы\n";
        cout << "5. Операциялар санын көру\n";
        cout << "0. Жүйеден шығу\n";

        cout << "------------------------------------\n";
        cout << "Таңдауыңызды енгізіңіз: ";

        cin >> tandau;

        switch (tandau) {

        case 1:
            bankomat.balansKorsetu(esepter[0]);
            break;

        case 2: {
            cout << "\nСалатын ақша сомасын енгізіңіз: ";
            cin >> soma;

            Tolyqtyru operatsiya(soma);

            bankomat.operatsiyaOryndau(
                operatsiya,
                esepter[0]
            );

            break;
        }

        case 3: {
            cout << "\nШешетін ақша сомасын енгізіңіз: ";
            cin >> soma;

            AkshaSheshu operatsiya(soma);

            bankomat.operatsiyaOryndau(
                operatsiya,
                esepter[0]
            );

            break;
        }

        case 4:
            bankomat.jurnalKorsetu();
            break;

        case 5:
            cout << "\nОперациялар саны: "
                 << Operatsiya::operatsiyaSany
                 << endl;
            break;

          case 0:
            cout << "\nЖүйеден сәтті шықтыңыз!\n";
            cout << "Сау болыңыз!\n";
            break;

        default:
            cout << "\nҚате таңдау! Қайта енгізіңіз.\n";
            break;
        }

    } while (tandau != 0);

    return 0;
}
