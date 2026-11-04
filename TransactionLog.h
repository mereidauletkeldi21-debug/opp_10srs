#ifndef TRANSACTION_LOG_H
#define TRANSACTION_LOG_H

#include <string>
#include <vector>

class TransactionLog {
private:
    std::vector<std::string> records_;
public:
    void addRecord(const std::string& record);
    void show() const;
    std::size_t size() const;
};

#endif
