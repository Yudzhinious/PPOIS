#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Budget.h"
#include "Equipment.h"
#include "Owner.h"
#include "Fabricator.h"

class Checkout {
private:
    int order;
    int load;
    double coordinate;
    std::string name;
    std::vector<Budget> money;
    std::vector<Equipment> equip;
public:
    Checkout(int order,int load, double coordinate, std::string name);
    void AddBudget(const Budget& money);
    void AddEquipment(const Equipment& equip);
    void Casher();
    void ShowCheckout() const;
    void ShowingEquipment() const;
    std::vector<Budget> getMoney();
    std::vector<Equipment> getEquip();
};