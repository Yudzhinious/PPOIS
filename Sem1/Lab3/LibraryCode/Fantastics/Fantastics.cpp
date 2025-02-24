#include "Fantastics.h"
Fantastics::Fantastics(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Fantastics::ShowInfo() {
    std::cout << "�������������� ����� " << name << " �������� " << quality << " ����� " << price << " ������." << std::endl;
}

void Fantastics::IncreaseQuality(int increment) {
    if (increment > 0) {
        quality += increment;
        std::cout << "�������� ����� ��������� �� " << increment << ". ����� ��������: " << quality << std::endl;
    }
    else {
        std::cout << "������: �������� ������ ���� �������������." << std::endl;
    }
}

void Fantastics::ReducePrice(int decrement) {
    if (decrement > 0 && decrement <= price) {
        price -= decrement;
        std::cout << "���� ����� ������� �� " << decrement << " ������. ����� ����: " << price << " ������." << std::endl;
    }
    else {
        std::cout << "������: ���������� ���� ������ ���� ������������� � �� ��������� ������� ����." << std::endl;
    }
}

double Fantastics::PricePerPage() const {
    if (pages > 0) {
        return static_cast<double>(price) / pages;
    }
    else {
        std::cout << "������: ���������� ������� ������ ���� �������������." << std::endl;
        return 0.0;
    }
}