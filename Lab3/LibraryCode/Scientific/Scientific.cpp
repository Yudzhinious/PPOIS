#include "Scientific.h"

Scientific::Scientific(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Scientific::ShowInfo() {
    std::cout << "Научная книга " << name << " качества " << quality << " стоит " << price << " рублей." << std::endl;
}

double Scientific::EvaluateScientificValue() const {
    double value = static_cast<double>(quality) * pages;
    std::cout << "Научная ценность книги: " << value << std::endl;
    return value;
}

void Scientific::UpdateEdition(int qualityIncrease, int priceIncrease) {
    if (qualityIncrease > 0) {
        quality += qualityIncrease;
    }
    else {
        std::cout << "Ошибка: увеличение качества должно быть положительным." << std::endl;
    }

    if (priceIncrease > 0) {
        price += priceIncrease;
    }
    else {
        std::cout << "Ошибка: увеличение цены должно быть положительным." << std::endl;
    }

    std::cout << "Издание обновлено. Новое качество: " << quality
        << ", новая цена: " << price << " рублей." << std::endl;
}

double Scientific::PriceBasedOnRating(double rating) const {
    if (rating < 0.0 || rating > 1.0) {
        std::cout << "Ошибка: рейтинг должен быть в диапазоне от 0 до 1." << std::endl;
        return 0.0;
    }

    double adjustedPrice = price * (1.0 + rating);
    std::cout << "Цена книги с учетом рейтинга " << rating
        << ": " << adjustedPrice << " рублей." << std::endl;
    return adjustedPrice;
}