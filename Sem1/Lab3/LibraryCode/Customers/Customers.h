#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Budget.h"

class Customers : public Budget{
protected:
    int cash;
public:
    Customers(int money, int koef, std::string source,int cash);
    void AddExpense(int amount);
    void ReduceExpense(int amount);
    void AverageMonthlyExpense(int months) const;
    bool HasHigherExpenseThan(const Customers& other) const;
    void ShowInfoCust();
};