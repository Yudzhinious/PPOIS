#include "Rent.h"

Rent::Rent(int time, int data, std::string name) {
    this->time = time;
    this->data = data;
    this->name = name;
}

void Rent::ShowInfoRent() {
    std::cout << "Посетитель библиотеки " << name << " взял книгу в пользование на " << time << " месяцев в " << data << " году." << std::endl;
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        it->ShowInfoCust();
    }

}
std::vector<Customers> Rent::getCustomer() {
    return customers;
}

void Rent::AddCustomer(Customers& customer) {
    customers.push_back(std::move(customer));
}
