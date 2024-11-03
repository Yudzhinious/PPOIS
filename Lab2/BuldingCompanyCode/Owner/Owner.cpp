#include "Owner.h"

Owner::Owner(int exp, std::string name) {
    this->experience = exp;
    this->name = name;
}

void Owner::ShowInfo() const {
    std::cout << "Опыт работы : " << experience << " лет , Имя владельца компании: " << name << std::endl;
}

void Owner::ShowInfo2() const {
    std::cout << "Опыт работы : " << experience << " лет , Имя владельца компании: " << name << std::endl;
}
void Owner::Order() {
    std::cout << "Заказ оформлен!" << std::endl;
}