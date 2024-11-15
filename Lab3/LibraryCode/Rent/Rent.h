#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Customers.h"

class Rent {
protected:
    int time;
    int data;
    std::string name;
    std::vector<Customers> customers;
public:
    Rent(int time, int data, std::string name);
    void AddCustomer(Customers& customers);
    void ShowInfoRent();
     std::vector<Customers> getCustomer();
};