#include "Product.h"

Product::Product(int price, std::string name) {
    this->product_price = price;
    this->product_name = name;
}

void Product::AddMaterial(Material& material) {
    materials.push_back(std::move(material));
}

void Product::ShowProduct() {
    std::cout << "��� �������� ����� " << product_name << " �� ����� " << product_price << " ������." << std::endl;
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        it->ShowInfo();
    }
}
std::vector<Material> Product::getMaterials()
{
    return materials;
}
