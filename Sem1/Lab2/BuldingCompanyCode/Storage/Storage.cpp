#include "Storage.h"

Storage::Storage(int exp, std::string name, int amount, int percentage, std::string naming) : Owner( exp, name) {
    this->amount = amount;
    this->percentage = percentage;
    this->naming = naming;
}

void Storage::ShowInfo2() const {
    std::cout << "Xранилище  " << naming << " заполнено на " << percentage << "% " << amount << " единицами товара." << std::endl;
}

void Storage::Occupancy() {
    if (percentage < 100) {
        for (percentage; percentage < 100; percentage += 5) {
            std::cout << "“екуща€ наполн€емость склада равна " << percentage << " процентам, количество возможных добавочных товаров: " << amount << std::endl;
            amount -= 30;
        }
    }
    else {
        std::cout << "«аполнение склада невозможно, используйте другой склад" << std::endl;
    }
}