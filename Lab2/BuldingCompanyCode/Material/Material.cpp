#include "Material.h"

Material::Material(int exp, std::string name, std::string type, int amount) : Owner( exp, name) {
    this->type = type;
    this->amount = amount;
}
void Material::ShowInfo() const {
    std::cout << "Наименование материала : " << type << ", Количество единиц материала : " << amount << std::endl;
}
void Material::AddAmount(int quantity) {
    if (quantity > 0) {
        amount += quantity;
    }
    else {
        std::cout << "Количество должно быть положительным." << std::endl;
    }
}
void Material::ReduceAmount(int quantity) {
    if (quantity > 0 && quantity <= amount) {
        amount -= quantity;
    }
    else {
        std::cout << "Недопустимое количество." << std::endl;
    }
}

std::string Material::GetType() const {
    return type;
}

void Material::SetType(const std::string& newType) {
    type = newType;
}

int Material::GetAmount() const {
    return amount;
}

bool Material::HasMoreThan(const Material& other) const {
    return amount > other.amount;
}

bool Material::IsSameType(const Material& other) const {
    return type == other.type;
}