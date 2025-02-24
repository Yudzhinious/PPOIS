#include "Souvenirs.h"

Souvenirs::Souvenirs(int price, std::string name, int money, int koef, std::string source) : Budget(money, koef, source) {
    this->price = price;
    this->name = name;
}
void Souvenirs::ApplyDiscount(int percent) {
    if (percent > 0 && percent <= 100) {
        price -= price * percent / 100;
        std::cout << "Скидка " << percent << "% применена. Новая цена сувенира: " << price << " рублей." << std::endl;
    }
    else {
        std::cout << "Ошибка: недопустимый процент скидки." << std::endl;
    }
}
bool Souvenirs::CanPurchase(int availableMoney) const {
    if (availableMoney >= price) {
        std::cout << "Вы можете купить сувенир " << name << "." << std::endl;
        return true;
    }
    else {
        std::cout << "Недостаточно средств для покупки сувенира " << name << "." << std::endl;
        return false;
    }
}
void Souvenirs::IncreasePrice(int percent) {
    if (percent > 0) {
        price += price * percent / 100;
        std::cout << "Цена сувенира " << name << " увеличена на " << percent << "%. Новая цена: " << price << " рублей." << std::endl;
    }
    else {
        std::cout << "Ошибка: процент увеличения должен быть положительным числом." << std::endl;
    }
}
void Souvenirs::CheckAvailability(int stockQuantity) const {
    if (stockQuantity > 0) {
        std::cout << "Сувенир " << name << " в наличии. Количество на складе: " << stockQuantity << "." << std::endl;
    }
    else {
        std::cout << "Сувенир " << name << " отсутствует на складе." << std::endl;
    }
}
void Souvenirs::ShowInfo() const {
    std::cout << "Сувенир " << name << " стоит" << price <<" рублей." << std::endl;

}
