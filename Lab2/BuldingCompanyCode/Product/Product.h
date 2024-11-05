#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Material.h"

class Product {
private:
    int product_price;
    std::string product_name;
    std::vector<Material> materials; 
public:
    Product(int product_price, std::string product_name);
    void AddMaterial(Material& material);
    void ShowProduct();
    std::vector<Material> getMaterials();
};