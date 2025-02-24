#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ctime> 
#include "Owner.h"

class Client : public Owner {
protected:
    std::string surname;
    int cash;
    std::vector<std::pair<double, std::string>> orderHistory;
public:
    Client(int exp, std::string name, std::string surname, int cash);
    void AddOrder(double amount, const std::string& date);
    void ShowOrderHistory() const;
    virtual void ShowInfo() const override;
};
