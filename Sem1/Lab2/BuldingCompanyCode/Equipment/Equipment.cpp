#include "Equipment.h"

Equipment::Equipment(std::string source, int cash) {
    this->source = source;
    this->cash = cash;
}
void Equipment::ShowEquipmentForRental(){
    std::cout << "���������� ������ ������������ " << source << " �� ����� " << cash << " ������." << std::endl;    
    for (auto it = rentals.begin(); it != rentals.end(); ++it) {
        it->ShowHelp_1();
    }
}
void Equipment::IsEnough() {
    int money = 360000;
    int real = cash * 30;
    if (money > real) {
        std::cout << "������� ��������� ������� " << std::endl;
    }
    else {
        std::cout << "������������ ������� ��� ������� ������������. ������� ��������� " << std::endl;
    }
}
void Equipment::AddTransportRental(TransportRental& rental) {
    rentals.push_back(std::move(rental));
}
void Equipment::ShowEquipmentForThings() {
    std::cout << "���������� ������ ������������ " << source << " �� ����� " << cash << " ������." << std::endl;
    for (auto it = things.begin(); it != things.end(); ++it) {
        it->ShowHelp_2();
    }
}
void Equipment::AddThings(Things& thing) {
    things.push_back(std::move(thing));
}
std::vector<TransportRental> Equipment::getRentals() {
    return rentals;
}
std::vector<Things> Equipment::getThings()
{
    return things;
}