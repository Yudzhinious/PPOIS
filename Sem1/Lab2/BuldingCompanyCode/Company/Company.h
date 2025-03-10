#pragma once
#include <iostream>
#include <string>
#include "Owner.h"
#include "Product.h"
#include "SectionsOfDepartment.h"

class Company : public Owner {
private:
    int year_of_foundation;
    std::string logo;
    std::vector<SectionsOfDepartment> sections;
    std::vector<Product> products;
public:
    Company(int exp, std::string name, std::string logo, int year_of_foundation);
    void AddSectionsOfDepartment(SectionsOfDepartment& section);
    void AddProduct(Product& product);
    void ShowingProduct();
    void ShowingSectionsOfDepartment();
    std::vector<Product> getProduct();
};