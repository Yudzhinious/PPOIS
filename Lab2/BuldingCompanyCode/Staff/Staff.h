#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Owner.h"
#include "Delivery.h"
#include "Client.h"

class Staff {
private:
    int age;
    std::string post;
    std::vector<Delivery> delivery;
public:
    Staff(std::string post, int age);
    void AddDelivery(const Delivery& delivery);
    void ShowingDelivery() const;
    std::vector<Delivery> getDelivery();
};