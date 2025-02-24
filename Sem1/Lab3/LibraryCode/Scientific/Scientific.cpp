#include "Scientific.h"

Scientific::Scientific(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Scientific::ShowInfo() {
    std::cout << "������� ����� " << name << " �������� " << quality << " ����� " << price << " ������." << std::endl;
}

double Scientific::EvaluateScientificValue() const {
    double value = static_cast<double>(quality) * pages;
    std::cout << "������� �������� �����: " << value << std::endl;
    return value;
}

void Scientific::UpdateEdition(int qualityIncrease, int priceIncrease) {
    if (qualityIncrease > 0) {
        quality += qualityIncrease;
    }
    else {
        std::cout << "������: ���������� �������� ������ ���� �������������." << std::endl;
    }

    if (priceIncrease > 0) {
        price += priceIncrease;
    }
    else {
        std::cout << "������: ���������� ���� ������ ���� �������������." << std::endl;
    }

    std::cout << "������� ���������. ����� ��������: " << quality
        << ", ����� ����: " << price << " ������." << std::endl;
}

double Scientific::PriceBasedOnRating(double rating) const {
    if (rating < 0.0 || rating > 1.0) {
        std::cout << "������: ������� ������ ���� � ��������� �� 0 �� 1." << std::endl;
        return 0.0;
    }

    double adjustedPrice = price * (1.0 + rating);
    std::cout << "���� ����� � ������ �������� " << rating
        << ": " << adjustedPrice << " ������." << std::endl;
    return adjustedPrice;
}