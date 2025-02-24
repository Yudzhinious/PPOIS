#include "Company.h"

Company::Company(int exp, std::string name, std::string name2, int year) : Owner(exp, name) {
    this->logo = name2;
    this->year_of_foundation = year;
}
void Company::AddSectionsOfDepartment(SectionsOfDepartment& section) {
    sections.push_back(std::move(section));
}
void Company::AddProduct(Product& product) {
    products.push_back(std::move(product));
}
void Company::ShowingProduct() {
    std::cout << "Строительная компания " << logo << " была создана в " << year_of_foundation << " году" << std::endl;
    for (auto it = products.begin(); it != products.end(); ++it) {
        it->ShowProduct();
    }
}
void Company::ShowingSectionsOfDepartment() {
    std::cout << "Строительная компания " << logo << " была создана в " << year_of_foundation << std::endl;
    for (auto it = sections.begin(); it != sections.end(); ++it) {
        it->ShowSectionsOfDepartment();
    }
}

std::vector<Product> Company::getProduct()
{
    return products;
}
