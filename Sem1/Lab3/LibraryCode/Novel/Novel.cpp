#include "Novel.h"

Novel::Novel(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Novel::ShowInfo() {
    std::cout << "Новельная книга " << name << " качества " << quality << " стоит " << price << " рублей." << std::endl;
}

void Novel::IncreaseQuality(int increment) {
    if (increment <= 0) {
        std::cout << "Ошибка: значение должно быть положительным." << std::endl;
        return;
    }
    quality += increment;
    std::cout << "Качество новельной книги увеличено на " << increment << ". Новое качество: " << quality << std::endl;
}

void Novel::ReducePrice(int decrement) {
    if (decrement > 0 && decrement <= price) {
        price -= decrement;
        std::cout << "Цена новельной книги снижена на " << decrement << " рублей. Новая цена: " << price << " рублей." << std::endl;
    }
    else {
        std::cout << (decrement <= 0 ? "Ошибка: уменьшение цены должно быть положительным."
            : "Ошибка: уменьшение цены не должно превышать текущую цену.") << std::endl;
    }
}

double Novel::PricePerPage() const {
    try {
        if (pages <= 0) throw std::invalid_argument("Ошибка: количество страниц должно быть положительным.");
        return static_cast<double>(price) / pages;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 0.0;
    }
}