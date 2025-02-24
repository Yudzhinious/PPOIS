#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Rent.h"
#include "Souvenirs.h"

class Shop {
protected:
    int data;
    std::string name;
    std::vector<Rent> rents;
public:
    Shop(int data, std::string name);
    void ShowInfoShop();
    void ShowLatestRent() const;
    void AddRent(Rent& rent);
};