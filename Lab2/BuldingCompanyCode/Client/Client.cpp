#include "Client.h"

Client::Client(int exp, std::string name, std::string surname, int cash) : Owner(exp, name) {
    this->surname = surname;
    this->cash = cash;
}

void Client::ShowInfo() const {
    std::cout << "Клиент " << surname << " выполнил заказ на " << cash << " рублей" << std::endl;
}
void Client::AddOrder(double amount, const std::string& date) {
    orderHistory.emplace_back(amount, date); 
}

void Client::ShowOrderHistory() const {
    std::cout << "История заказов клиента " << surname << ":\n";
    for (const auto& order : orderHistory) {
        std::cout << "Сумма заказа: " << order.first << " рублей, Дата: " << order.second << std::endl;
    }
}
