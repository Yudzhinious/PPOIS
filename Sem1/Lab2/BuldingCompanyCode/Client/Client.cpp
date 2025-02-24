#include "Client.h"

Client::Client(int exp, std::string name, std::string surname, int cash) : Owner(exp, name) {
    this->surname = surname;
    this->cash = cash;
}

void Client::ShowInfo() const {
    std::cout << "������ " << surname << " �������� ����� �� " << cash << " ������" << std::endl;
}
void Client::AddOrder(double amount, const std::string& date) {
    orderHistory.emplace_back(amount, date); 
}

void Client::ShowOrderHistory() const {
    std::cout << "������� ������� ������� " << surname << ":\n";
    for (const auto& order : orderHistory) {
        std::cout << "����� ������: " << order.first << " ������, ����: " << order.second << std::endl;
    }
}
