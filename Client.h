#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    class Card {
    private:
        std::string cardNumber_;
        std::string pin_;
    public:
        Card(const std::string& cardNumber = "0000000000000000",
             const std::string& pin = "0000");
        bool checkPin(const std::string& pin) const;
        std::string getMaskedNumber() const;
    };

private:
    int id_;
    std::string fullName_;
    Card card_;

public:
    Client(int id, const std::string& fullName,
           const std::string& cardNumber, const std::string& pin);
    int getId() const;
    const std::string& getFullName() const;
    bool authenticate(const std::string& pin) const;
    std::string getCardNumber() const;
};

#endif
