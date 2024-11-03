#include "Company.h"

Company::Company(int exp, std::string name, std::string name2, int year) : Owner(exp, name) {
    this->logo = name2;
    this->year_of_foundation = year;
}
void Company::AddSectionsOfDepartment(const SectionsOfDepartment& section) {
    sections.push_back(section);
}
void Company::AddProduct(const Product& product) {
    products.push_back(product);
}
void Company::ShowingProduct() const {
    std::cout << "Строительная компания " << logo << " была создана в " << year_of_foundation << " году" << std::endl;
    for (const auto& product : products) {
        product.ShowProduct();
    }
}
void Company::ShowingSectionsOfDepartment() const {
    std::cout << "Строительная компания " << logo << " была создана в " << year_of_foundation << std::endl;
    for (const auto& SectionsOfDepartment : sections) {
        SectionsOfDepartment.ShowSectionsOfDepartment();
    }
}

std::vector<Product> Company::getProduct()
{
    return products;
}
