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
    void AddDelivery(Delivery& delivery);
    void ShowingDelivery();
    std::string Worker();
    std::vector<Delivery> getDelivery();
};