#include "Owner.h"

Owner::Owner(int age, int exp, std::string surname) {
    this->age = age;
    this->exp = exp;
    this->surname = surname;
}

void Owner::ShowInfoOwner() {
    std::cout << "�������� " << surname << " ���������� ��������� " << age << " ��� ���������� �������������� �������� �� ���������� " << exp << " ���." << std::endl;
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        it->ShowInfoCust();
    }
}
std::vector<Customers> Owner::GetCash() {
    return customers;
}

void Owner::AddCustomer(Customers& customer) {
    customers.push_back(std::move(customer));
}