#pragma once
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include "Customers.h"

class Owner {
protected:
    int age;
    int exp;
    std::string surname;
    std::vector<Customers> customers;
public:
    Owner(int age, int exp, std::string surname);
    void AddCustomer(Customers& customers);
    void ShowInfoOwner();
    std::vector<Customers> GetCash();
};