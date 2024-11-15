#include "Fantastics.h"
Fantastics::Fantastics(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Fantastics::ShowInfo() {
    std::cout << "Фантастическая книга " << name << " качества " << quality << " стоит " << price << " рублей." << std::endl;
}

void Fantastics::IncreaseQuality(int increment) {
    if (increment > 0) {
        quality += increment;
        std::cout << "Качество книги увеличено на " << increment << ". Новое качество: " << quality << std::endl;
    }
    else {
        std::cout << "Ошибка: значение должно быть положительным." << std::endl;
    }
}

void Fantastics::ReducePrice(int decrement) {
    if (decrement > 0 && decrement <= price) {
        price -= decrement;
        std::cout << "Цена книги снижена на " << decrement << " рублей. Новая цена: " << price << " рублей." << std::endl;
    }
    else {
        std::cout << "Ошибка: уменьшение цены должно быть положительным и не превышать текущую цену." << std::endl;
    }
}

double Fantastics::PricePerPage() const {
    if (pages > 0) {
        return static_cast<double>(price) / pages;
    }
    else {
        std::cout << "Ошибка: количество страниц должно быть положительным." << std::endl;
        return 0.0;
    }
}