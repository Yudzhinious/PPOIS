#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "TransportRental.h"
#include "Things.h"
class Equipment {
private:
    std::string source;
    int cash;
    std::vector<TransportRental> rentals;
    std::vector<Things> things;
public:
    Equipment(std::string source, int cash);
    void AddTransportRental(const TransportRental& rental);
    void AddThings(const Things& thing);
    void IsEnough();
    void ShowEquipmentForRental() const;
    void ShowEquipmentForThings() const;
    std::vector<TransportRental> getRentals();
    std::vector<Things> getThings();
};
