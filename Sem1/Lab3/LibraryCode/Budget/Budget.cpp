#include "Budget.h"

Budget::Budget(int money,int koef, std::string source) {
    this->money = money;
    this->koef = koef;
    this->source = source;
}
void Budget::IncreaseBudget(Budget& budget, int percent) {
    budget.money += budget.money * percent / 100;
    budget.koef += percent;
}
void Budget::ShowInfo() const{
    std::cout << "������ �������� " << money << " ������ ��� ������� �� ��������� " << source << " � �������� � " << koef << " ���������." << std::endl;
}