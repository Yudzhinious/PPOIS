#include "Material.h"

Material::Material(int exp, std::string name, std::string type, int amount) : Owner( exp, name) {
    this->type = type;
    this->amount = amount;
}

void Material::ShowInfo() const {
    std::cout << "Наименование материала : " << type << ", Количество единиц материала : " << amount << std::endl;
}