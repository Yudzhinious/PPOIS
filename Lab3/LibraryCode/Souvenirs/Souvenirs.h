#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Shop.h"
#include "Budget.h"

class Souvenirs : public Budget {
protected:
    int price;
    std::string name;
public:
    Souvenirs(int price, std::string name, int money, int koef, std::string source);
    void ApplyDiscount(int percent);
    bool CanPurchase(int availableMoney) const;
    void IncreasePrice(int percent);
    void CheckAvailability(int stockQuantity) const;
    virtual void ShowInfo() const override;
};