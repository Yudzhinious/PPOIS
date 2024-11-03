#include "Checkout.h"
Checkout::Checkout(int order, int load, double coord, std::string name) {
    this->order = order;
    this->load = load;    this->coordinate = coord;
    this->name = name;
}
void Checkout::AddBudget(const Budget& budget) {
    money.push_back(budget);
}
void Checkout::AddEquipment(const Equipment& equipment) {
    equip.push_back(equipment);
}
void Checkout::Casher() {
    for (int i = 0; i < load; i++) {
        std::cout << "Заказ содержит в очереди " << order - 8 * i << " заказов, подождите еще " << load - i << " дней" << std::endl;        order -= 8;
    }    std::cout << "Заказ готов к выдаче" << std::endl;
}
void Checkout::ShowCheckout() const {
    std::cout << "Касса " << name << " с расположением " << coordinate << " содержит в очереди " << order << " заказов c задержкой в " << load << " дней " << std::endl;    for (const auto& budget : money) {
        budget.ShowInfo();
    }
}
void Checkout::ShowingEquipment() const {
    std::cout << "Касса " << name << " с расположением " << coordinate << " содержит в очереди " << order << " заказов c задержкой в " << load << " дней " << std::endl;    for (const auto& equipment : equip) {
        equipment.ShowEquipmentForRental();
    }
}
std::vector<Budget> Checkout::getMoney() {
    return money;
}
std::vector<Equipment> Checkout::getEquip() {
    return equip;
}