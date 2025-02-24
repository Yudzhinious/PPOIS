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
    void AddTransportRental(TransportRental& rental);
    void AddThings(Things& thing);
    void IsEnough();
    void ShowEquipmentForRental();
    void ShowEquipmentForThings();
    std::vector<TransportRental> getRentals();
    std::vector<Things> getThings();
};
