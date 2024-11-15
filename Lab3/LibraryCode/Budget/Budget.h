#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>

class Budget {
protected:
    int money;
    int koef;
    std::string source;
public:
    Budget(int money, int koef, std::string source);
    void IncreaseBudget(Budget& budget, int percent);
    virtual void ShowInfo() const;
};


