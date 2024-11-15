#include "Novel.h"

Novel::Novel(int pages, std::string name, std::string author, int quality, int price) : Book(pages, name, author) {
    this->quality = quality;
    this->price = price;
}

void Novel::ShowInfo() {
    std::cout << "��������� ����� " << name << " �������� " << quality << " ����� " << price << " ������." << std::endl;
}

void Novel::IncreaseQuality(int increment) {
    if (increment <= 0) {
        std::cout << "������: �������� ������ ���� �������������." << std::endl;
        return;
    }
    quality += increment;
    std::cout << "�������� ��������� ����� ��������� �� " << increment << ". ����� ��������: " << quality << std::endl;
}

void Novel::ReducePrice(int decrement) {
    if (decrement > 0 && decrement <= price) {
        price -= decrement;
        std::cout << "���� ��������� ����� ������� �� " << decrement << " ������. ����� ����: " << price << " ������." << std::endl;
    }
    else {
        std::cout << (decrement <= 0 ? "������: ���������� ���� ������ ���� �������������."
            : "������: ���������� ���� �� ������ ��������� ������� ����.") << std::endl;
    }
}

double Novel::PricePerPage() const {
    try {
        if (pages <= 0) throw std::invalid_argument("������: ���������� ������� ������ ���� �������������.");
        return static_cast<double>(price) / pages;
    }
    catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
        return 0.0;
    }
}