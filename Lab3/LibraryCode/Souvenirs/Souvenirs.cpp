#include "Souvenirs.h"

Souvenirs::Souvenirs(int price, std::string name, int money, int koef, std::string source) : Budget(money, koef, source) {
    this->price = price;
    this->name = name;
}
void Souvenirs::ApplyDiscount(int percent) {
    if (percent > 0 && percent <= 100) {
        price -= price * percent / 100;
        std::cout << "������ " << percent << "% ���������. ����� ���� ��������: " << price << " ������." << std::endl;
    }
    else {
        std::cout << "������: ������������ ������� ������." << std::endl;
    }
}
bool Souvenirs::CanPurchase(int availableMoney) const {
    if (availableMoney >= price) {
        std::cout << "�� ������ ������ ������� " << name << "." << std::endl;
        return true;
    }
    else {
        std::cout << "������������ ������� ��� ������� �������� " << name << "." << std::endl;
        return false;
    }
}
void Souvenirs::IncreasePrice(int percent) {
    if (percent > 0) {
        price += price * percent / 100;
        std::cout << "���� �������� " << name << " ��������� �� " << percent << "%. ����� ����: " << price << " ������." << std::endl;
    }
    else {
        std::cout << "������: ������� ���������� ������ ���� ������������� ������." << std::endl;
    }
}
void Souvenirs::CheckAvailability(int stockQuantity) const {
    if (stockQuantity > 0) {
        std::cout << "������� " << name << " � �������. ���������� �� ������: " << stockQuantity << "." << std::endl;
    }
    else {
        std::cout << "������� " << name << " ����������� �� ������." << std::endl;
    }
}
void Souvenirs::ShowInfo() const {
    std::cout << "������� " << name << " �����" << price <<" ������." << std::endl;

}
