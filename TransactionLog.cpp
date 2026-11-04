#include "TransactionLog.h"
#include <iostream>

void TransactionLog::addRecord(const std::string& record) { records_.push_back(record); }

void TransactionLog::show() const {
    std::cout << "\n--- Журнал операций ---\n";
    if (records_.empty()) {
        std::cout << "Операций пока нет.\n";
        return;
    }
    for (const std::string& record : records_) std::cout << record << '\n';
}

std::size_t TransactionLog::size() const { return records_.size(); }
