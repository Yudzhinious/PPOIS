#include "Checkout.h"
Checkout::Checkout(int order, int load, double coord, std::string naming) {
    this->order = order;
    this->load = load;    
    this->coordinate = coord;
    this->naming = naming;
}
void Checkout::AddBudget(Budget& budget) {
    money.push_back(std::move(budget));
}
void Checkout::AddEquipment(Equipment& equipment) {
    equip.push_back(std::move(equipment));
}
void Checkout::Casher() {
    for (int i = 0; i < load; i++) {
        std::cout << "Заказ содержит в очереди " << order - 8 * i << " заказов, подождите еще " << load - i << " дней" << std::endl;       
        order -= 8;
    }    std::cout << "Заказ готов к выдаче" << std::endl;
}
bool Checkout::True() {
    if (order == 0) {
        return true;
    }
    else {
        if (load == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}
void Checkout::ShowCheckout() {
    std::cout << "Касса " << naming << " с расположением " << coordinate << " содержит в очереди " << order << " заказов c задержкой в "<< load << " дней " << std::endl;
    for (auto it = money.begin(); it != money.end(); ++it) {
        it->ShowInfo();
    }
}

void Checkout::ShowingEquipment(){
    std::cout << "Касса " << naming << " с расположением " << coordinate << " содержит в очереди " << order << " заказов c задержкой в " << load << " дней " << std::endl;  
    for (auto it = equip.begin(); it != equip.end(); ++it) {
        it->ShowEquipmentForRental();
    }
}
std::vector<Budget> Checkout::getMoney() {
    return money;
}
std::vector<Equipment> Checkout::getEquip() {
    return equip;
}