#include "Client.h"

Client::Card::Card(const std::string& cardNumber, const std::string& pin)
    : cardNumber_(cardNumber), pin_(pin) {}

bool Client::Card::checkPin(const std::string& pin) const {
    return pin == pin_;
}

std::string Client::Card::getMaskedNumber() const {
    if (cardNumber_.size() <= 4) return cardNumber_;
    return std::string(cardNumber_.size() - 4, '*') + cardNumber_.substr(cardNumber_.size() - 4);
}

Client::Client(int id, const std::string& fullName,
               const std::string& cardNumber, const std::string& pin)
    : id_(id), fullName_(fullName), card_(cardNumber, pin) {}

int Client::getId() const { return id_; }
const std::string& Client::getFullName() const { return fullName_; }
bool Client::authenticate(const std::string& pin) const { return card_.checkPin(pin); }
std::string Client::getCardNumber() const { return card_.getMaskedNumber(); }
