#include "Shop.h"
Shop::Shop(int data, std::string name) {
    this->data = data;
    this->name = name;
}

void Shop::ShowInfoShop() {
    std::cout << "������� " << name << " ��� ������� ���������� ������� ��� �������� � " << data <<  " ����." << std::endl;
    for (auto it = rents.begin(); it != rents.end(); ++it) {
        it->ShowInfoRent();
    }
}
void Shop::ShowLatestRent() const {
    if (rents.empty()) {
        std::cout << "� �������� " << name << " ��� �����." << std::endl;
        return;
    }
    const Rent& latestRent = rents.back();
    std::cout << "����� ��������� ������ � �������� " << name << ":" << std::endl;
}

void Shop::AddRent(Rent& rent) {
    rents.push_back(std::move(rent));
}